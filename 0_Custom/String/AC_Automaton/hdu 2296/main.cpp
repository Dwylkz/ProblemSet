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
	  maxn = 110,
	  mod =  20090717,
	  maxm = 26; 
const long long inf64 = 0x7fffffffffffffffLL; 
//structure
//AC Automaton
//include: queue, cstring
//usage: obj.Init->obj.Link->(obj.$(others))*->obj.Free
struct ACA {
	enum {m = maxm, shift = 'a'};
	struct Node {
		//Extern
		int d;
		//Basic
		Node *s[m],             //Adjust node
			 *p;                //Failure link
		int  a;                 //Accpet Tag
	};
	typedef Node *PNode;
	//Extern
	//Basic
	int sz;
	Node t[1200];
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
		x->a = a;
	}
	//Failure Linking
	//usage: obj.Link()
	void Link() {
		queue<PNode> Q;
		rt->p = rt;
		for (int i = 0; i < m; i++) {
			if (rt->s[i]) {
				rt->s[i]->d = 1;
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
					x->s[i]->d = x->d + 1;
					x->s[i]->p = x->p->s[i];
					x->s[i]->a += x->p->s[i]->a;
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
typedef pair<int, int> II;
//global variable
ACA aca;
int n, m, k, buf[maxn];
char key[maxn][maxm];
int dp[maxn][1200];
string st[maxn][1200];
//access and mutator
void CTI(int *t, char *s, int sz) {
	for (int i = 0; i < sz; i++) {
		t[i] = s[i];
	}
}
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		aca.Init();
		for (int i = 0; i < m; i++) {
			scanf("%s", key + i);
		}
		for (int i = 0; i < m; i++) {
			int w;
			scanf("%d", &w);
			CTI(buf, key[i], strlen(key[i]));
			aca.Insert(w, buf, strlen(key[i]));
		}
		aca.Link();
		memset(dp, -1, sizeof(dp));
		int dpmx = 0;
		string stmx = "";
		dp[0][0] = 0;
		for (int i = 0; i <= n; i++) {
			for (int u = 0; u < aca.sz; u++) {
				st[i][u] = "";
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int u = 0; u < aca.sz; u++) {
				if (i <= aca.t[u].d) {
					continue;
				}
				for (int j = 0; j < aca.m; j++) {
					int v = aca.t[u].s[j] - aca.t;
					if (dp[i][v] < dp[i - 1][u] + aca.t[v].a
							|| dp[i][v] == dp[i - 1][u] + aca.t[v].a
							&& st[i - 1][u] + char(j + 'a') < st[i][v]) {
						dp[i][v] = dp[i - 1][u] + aca.t[v].a;
						st[i][v] = st[i - 1][u] + char(j + 'a');
						if (dpmx < dp[i][v]
								|| dpmx == dp[i][v] && st[i][v] < stmx) {
							dpmx = dp[i][v];
							stmx = st[i][v];
						}
					}
				}
			}
		}
		printf("%s\n", stmx.data());
	}
	return 0;
}
