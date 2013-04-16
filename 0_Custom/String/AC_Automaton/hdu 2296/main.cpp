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
UC key[maxn][maxm];
int dp[maxn][1200];
II pre[maxn][1200];
//access and mutator
void CTI(int *t, UC *s, int sz) {
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
			CTI(buf, key[i], strlen((char*)key[i]));
			aca.Insert(w, buf, strlen((char*)key[i]));
		}
		aca.Link();
		memset(dp, 0, sizeof(dp));
		memset(pre, -1, sizeof(pre));
		II res(0, 0);
		ACA::Node *t = aca.t;
		for (int i = 1; i <= n; i++) {
			queue<int> Q;
			bool vis[maxn];
			memset(vis, 0, sizeof(vis));
			Q.push(0);
			vis[0] = 1;
			while (!Q.empty()) {
				int u = Q.front();
				Q.pop();
				for (int k = 0; k < maxm; k++) {
					int v = t[u].s[k] - t;
					if (dp[i][v] < dp[i - 1][u] + t[v].a) {
						dp[i][v] = dp[i - 1][u] + t[v].a;
						if (dp[res.first][res.second] < dp[i][v]) {
							res = make_pair(i, v);
						}
						pre[i][v] = make_pair(i - 1, u);
					}
					if (!vis[v]) {
						vis[v] = 1;
						Q.push(v);
					}
				}
			}
		}
#if 1
		printf("%d\n", dp[res.first][res.second]);
#endif
		vector<char> ans;
		II v = res;
		while (1) {
			II u = pre[v.first][v.second];
			if (!v.first) {
				break;
			}
			for (int i = 0; i < maxm; i++) {
				if (t[u.second].s[i] == t + v.second) {
					ans.push_back(i + 'a');
					break;
				}
			}
			v = u;
		}
		for (int i = ans.size() - 1; 0 <= i; i--) {
			putchar(ans[i]);
		}
		puts("");
	}
	return 0;
}
