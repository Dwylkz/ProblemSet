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
	  maxn = 55;
const long long inf64 = 0x7fffffffffffffffLL; 
//structure
//AC Automaton
//include: queue, cstring
//usage: obj.Init->obj.Link->(obj.$(others))*->obj.Free
struct ACA {
	const static int m = 55,  //Size of charator set
		  shift = 32;           //Charactor shift
	struct Node {
		//Extern
		//Basic
		Node *s[m],             //Adjust node
			 *p;                //Failure link
		int  a;                 //Accpet state or not
	};
	typedef Node *PNode;
	//Extern
	vector<int> cnt[m];
	//Basic
	stack<PNode> ct;
	PNode   rt;                   //Initial State
	//Init a node
	//usage: obj.New([length], [Failure Link])
	PNode New() {
		PNode x = (PNode)malloc(sizeof(Node));
		memset(x, 0, sizeof(Node));
		ct.push(x);
		return x;
	}
	//Init
	//usage: obj.Init()
	void Init() {
		//Extern
		memset(cnt, 0, sizeof(cnt));
		//Basic
		for ( ; !ct.empty(); ct.pop()) {
		}
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
		x->a++;
	}
	//Failure Linking
	//usage: obj.Link()
	void Link() {
		queue<PNode> Q;
		for (Q.push(rt); !Q.empty(); ) {
			PNode x = Q.front();
			Q.pop();
			for (int i = 0; i < m; i++) {
				if (x->s[i]) {
					if (x == rt) {
						x->s[i]->p = x;
					} else {
						PNode y = x->p;
						for (; y && !y->s[i]; y = y->p) {
						}
						if (!y) {
							x->s[i]->p = rt;
						} else {
							x->s[i]->p = y->s[i];
						}
					}
					Q.push(x->s[i]);
				}
			}
		}
	}
	//statistic work
	//usage: obj.Search(key array, array length)
	int Search(int *s, int sl) {
		int total = 0;
		PNode x = rt;
		map<PNode, bool> h;
		h.clear();
		for (int i = 0; i < sl; i++) {
			int k = s[i] - shift;
			for ( ; x && (k < 0 ||  m <= k || !x->s[k]); x = x->p) {
			}	
			if (!x) {
				x = rt;
				continue;
			}
			for (PNode y = x->s[k]; y; y = y->p) {
				if (h.find(y) == h.end()) {
					total += y->a;
					h[y] = 1;
				}
			}
			x = x->s[k];
		}
		return total;
	}
	//Free spaces
	//usage: obj.Free()
	void Free(PNode x = 0) {
		for ( ; !ct.empty(); ct.pop()) {
			free(ct.top());
		}
	}
	void cntInit() {
		for (int i = 0; i < m; i++) {
			cnt[i].clear();
		}
	}
};
//type definition
typedef long long LL;
//global variable
ACA aca;
vector<ACA::Node> tai[maxn];
int N, M, P, buf[maxn], dp[maxn];
char a[maxn], p[maxn];
//access and mutator
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	while (~scanf("%d%d%d", &N, &M, &P)) {
		scanf("%s", a);
		aca.Init();
		for (int i = 0; i < maxn; i++) {
			tai[i].clear();
		}
		for (int i = 0; i < P; i++) {
			scanf("%s", p);
			for (char *j = p; *j; j++) {
				buf[j - p] = *j;
			}
			aca.Insert(strlen(p), buf, strlen(p));
		}
		aca.cntInit();
		//aca.Link();
		dp[0] = 0;
		for (int i = 1; i <=M; i++) {
			for (int j = 0; j < N; j++) {
			}
		}
		aca.Free();
	}
	return 0;
}
