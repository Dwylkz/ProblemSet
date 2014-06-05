//coder: SXDwylkz
//heads
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
//namespaces
using namespace std;
//constants
const char input[] = "input.in",
	  output[] = "output.out";
const int inf32 = 0x7fffffff,
	  maxn = 26,
	  mod =  20090717,
	  maxm = (1 << 10);
const long long inf64 = 0x7fffffffffffffffLL; 
//structure
//AC Automaton
//include: queue, cstring
//usage: obj.Init->obj.Link->(obj.$(others))*->obj.Free
struct ACA {
	enum {n = 11, m = 26, shift = 'a'};
	struct Node {
		//Extern
		//Basic
		Node *s[m],             //Adjust node
			 *p;                //Failure link
		int  a;                 //Accpet Tag
	};
	typedef Node *PNode;
	//Extern
	//Basic
	int sz;
	Node t[101];
	PNode   rt;                   //Initial State
	//Init a node
	//usage: obj.New([length], [Failure Link])
	PNode New() {
		memset(t + sz, 0, sizeof(Node));
		return t + sz++;
	}
	//Init
	//usage: obj.Init()
	void Init() {
		//Extern
		//Basic
		sz = 0;
		rt = New();
	}
	//Append a string
	//usage: obj.Insert(charactor)
	void Insert(int a, int *s, int sl) {
		PNode x = rt;
		for (int i = 0; i < sl; i++) {
			int k = s[i] - shift;
			if (!x->s[k]) {
				x->s[k] = New();
			}
			x = x->s[k];
		}
		x->a |= 1 << a;
	}
	//Failure Linking
	//usage: obj.Link()
	void Link() {
		queue<PNode> Q;
		rt->p = rt;
		for (int i = 0; i < m; i++) {
			if (rt->s[i]) {
				rt->s[i]->p = rt;
				Q.push(rt->s[i]);
			} else {
				rt->s[i] = rt;
			}
		}
		while (!Q.empty()) {
			PNode x = Q.front();
			Q.pop();
			for (int i = 0; i < m; i++) {
				if (x->s[i]) {
					x->s[i]->p = x->p->s[i];
					x->s[i]->a |= x->p->s[i]->a;
					Q.push(x->s[i]);
				} else {
					x->s[i] = x->p->s[i];
				}
			}
		}
	}
};
//type definition
typedef long long LL;
typedef unsigned char UC;
//global variable
ACA aca;
int n, m, k, buf[maxn];
UC key[maxn];
int dp[maxn][101][maxm];
//access and mutator
void CTI(int *t, UC *s, int sz) {
	for (int i = 0; i < sz; i++) {
		t[i] = s[i];
	}
}
int GW(int x) {
	int res = 0;
	for ( ; x; x >>= 1) {
		res += x & 1;
	}
	return res;
}
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	while (scanf("%d%d%d", &n, &m, &k), n || m || k) {
		aca.Init();
		for (int i = 0; i < m; i++) {
			scanf("%s", key);
			CTI(buf, key, strlen((char*)key));
			aca.Insert(i, buf, strlen((char*)key));
		}
		aca.Link();
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;
		ACA::PNode t = aca.t;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < aca.sz; j++) {
				for (int l = 0, ml = 1 << m; l < ml; l++) {
					if (!dp[i - 1][j][l]) {
						continue;
					}
					for (int k = 0; k < 26; k++) {
						int id = t[j].s[k] - t, mask = l | t[id].a;
						dp[i][id][mask] += dp[i - 1][j][l];
						if (mod <= dp[i][id][mask]) {
							dp[i][id][mask] %= mod;
						}
					}
				}
			}
		}
		int res = 0;
		for (int i = 0; i < aca.sz; i++) {
			for (int j = 0, ml = 1 << m; j < ml; j++) {
				if (k <= GW(j)) {
					res += dp[n][i][j];
					if (mod <= res) {
						res %= mod;
					}
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
