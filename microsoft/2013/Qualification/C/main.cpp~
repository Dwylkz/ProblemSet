//coder: SXDwylkz
//heads
#include <cmath>
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
	  maxn = 1e5 + 10;
const long long inf64 = 0x7fffffffffffffffLL; 
//structure
//structures
//Linking list Graph
//include: vector
struct LLG {
    struct Edge {
        //Externs should be defined here
        int w;
        //Basic
        int v,       //Adjust node v
            next;    //Index of the next node v
    };
	const static int n = maxn;
	const static int m = maxn << 1;
	Edge E[m];    //Aarry in which Edges store
	int  L[n],    //Head of linking list of nodes
		 El,         //Total of Edges
		 V;          //Total of nodes
    //Init
    //usage: obj.Init(int TotalOfNode)
    void Init(int _V = 0) {
        V = _V;
		El = 0;
		memset(L, -1, sizeof(L));
    }
    //AddEdge 
    //usage: obj.AddEdge(From, To, Extern)
    void AddEdge(int u, int v, int w) {
        Edge t =  {w, v, L[u]}; //rule: Node t = {Extern, Basic}
        L[u] = El;
        E[El++] = t;
    }
    //FlowAddEdge 
    //usage: obj.FlowAddEdge(From, To, Extern)
    void FlowAddEdge(int u, int v, int w) {
        AddEdge(u, v, w);
        AddEdge(v, u, 0);
    }
};
//LCA
//Lowest Common Ancestor
//include: LLG
struct LCA {
	const static int n = maxn << 1;
	typedef int AI[n];
	//Basic
	LLG        *G;        //The tree we're going to deal with
	LLG::Edge  *E;        //The Graph's Edges Set
	int        V,         //Total of Graph's Nodes      
			   *L;        //The Graph's link head
	AI         dep,       //The depth of each node in ta
			   ta,        //The transformed tree
			   id,        //ID of each node
			   st[20];    //Sparse Table according to dep
	int        ind,       //Index iterator
			   rt;        //Root of the tree
	//Extern
	//Init
	//usage: obj.Init(int Root, Graph *Tree)
	void Init(int _rt, LLG *_G) {
		rt = _rt;
		G = _G;
		E = G->E;
		V = G->V;
		L = G->L;
		//rule: list[] = {basic, extern}
		int *list[] = {dep, ta, id};
		//rule: for (int i = 0; i < listSize; i++)
		for (int i = 0; i < 3; i++) {
			memset(list[i], 0, sizeof(list[i]));
		}
		for (int i = 0; i < 20; i++) {
			memset(st[i], 0, sizeof(st[i]));
		}
		ind = 0;
		TTI(rt);
		stInit();
	}
	//binary Ceil of x
	//usage: Ceil(int value)
	int Ceil(int x) {
		int o = 0;
		for (; (1 << o) <= x; o++) {
		};
		return o;
	}
	//Tree to Intervel
	//usage: obj.TTI(int Root, int Father)
	void TTI(int u, int fa = -1) {
		if (fa != -1) {
			dep[u] = dep[fa] + 1;
		}
		ta[id[u] = ind++] = u;
		for (int i = L[u]; i != -1; i = E[i].next) {
			if (E[i].v != fa) {
				TTI(E[i].v, u);
				ta[ind++] = u;
			}
		}
	}
	//Sparse table init
	//usage: ST_init()
	void stInit() {
		for (int i = 0; i < ind; i++) {
			st[0][i] = ta[i];
		}
		int l = Ceil(ind);
		for (int i = 1; i < l; i++) {
			for (int j = 0; j < ind; j++) {
				if (j + (1 << i) < ind) {
					int x = st[i - 1][j],
						y = st[i - 1][j + (1 << (i - 1))];
					st[i][j] = (dep[x] < dep[y])? x: y;
				}
			}
		}
	}
	//Return Ask(x, y) in Graph G when rt as the tree root
	//usage: obj.Ask(int u, int v)
	int Ask(int x, int y) {
		x = id[x];
		y = id[y];
		if (x > y) swap(x, y);
		int l = Ceil(y - x + 1) - 1;
		x = st[l][x];
		y = st[l][y - (1 << l) + 1];
		return (dep[x] < dep[y])? x: y;
	}
};
struct FST {
	typedef struct Node {
		Node *ls, *rs;
		int sum;
	} *PNode;
	stack<PNode> ct;
	PNode phi;
	void Init(int L, int R) {
		for ( ; !ct.empty(); ct.pop()) {
		}
		phi = Build(L, R);
	}
	PNode Build(int L, int R) {
		PNode x = new Node;
		ct.push(x);
		memset(x, 0, sizeof(Node));
		if (L < R) {
			int M = L + R >> 1;
			x->ls = Build(L, M);
			x->rs = Build(M + 1, R);
		}
		return x;
	}
	PNode Insert(int k, int L, int R, PNode y) {
		PNode x = new Node;
		ct.push(x);
		*x = *y;
		x->sum++;
		if (L < R) {
			int M = L + R >> 1;
			if (k <= M) {
				x->ls = Insert(k, L, M, y->ls);
			} else {
				x->rs = Insert(k, M + 1, R, y->rs);
			}
		}
		return x;
	}
	int Ask(int k, int L, int R, PNode a, PNode u, PNode v) {
		if (L == R) {
			return L;
		}
		int M = L + R >> 1, sum = u->ls->sum + v->ls->sum - 2 * a->ls->sum;
		if (k <= sum) {
			return Ask(k, L, M, a->ls, u->ls, v->ls);
		}
		return Ask(k - sum, M + 1, R, a->rs, u->rs, v->rs);
	}
};
struct DA {
	static const int n = maxn;
	int s[n], l;
	void Init() {
		l = 0;
	}
	int Insert(int k) {
		s[l++] = k;
	}
	int Build() {
		sort(s, s + l);
		l = unique(s, s + l) - s;
	}
	int Ask(int k) {
		int L = 0, R = l - 1;
		while (L < R) {
			int m = L + R >> 1;
			if (k <= s[m]) {
				R = m;
			} else {
				L = m + 1;
			}
		}
		return L;
	}
	int operator [] (int x) {
		return s[x];
	}
};
//type definition
typedef long long LL;
//global variable
LLG llg;
LCA lca;
FST fst;
FST::PNode rt[maxn];
DA da;
int N, M;
//access and mutator
void Travel(int u, int p = -1) {
	if (p != -1) {
		rt[u] = fst.Insert(da.Ask(llg.E[p].w), 0, da.l, rt[llg.E[p].v]);
	}
	for (int i = llg.L[u]; i != -1; i = llg.E[i].next) {
		if (i != p) {
			Travel(llg.E[i].v, i ^ 1);
		}
	}
}
bool YYCIO(int u, int v) {
	int a = lca.Ask(u, v),
		e1 = fst.Ask(1, 0, da.l, rt[a], rt[u], rt[v]),
		e2 = fst.Ask(2, 0, da.l, rt[a], rt[u], rt[v]),
		r = 3;
	for (int e3= fst.Ask(r++, 0, da.l, rt[a], rt[u], rt[v]); e3 < da.l; ) {
#if 0	
		printf("%d < %d + %d?\n", da[e3], da[e1], da[e2]);
#endif
		if (da[e3] < da[e1] + da[e2]) {
			return 1;
		}
		e1 = e2;
		e2 = e3;
		e3 = fst.Ask(r++, 0, da.l, rt[a], rt[u], rt[v]);
	}
	return 0;
}
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	int T;
#if 0
	int t = 1, f0 = 1, f1 = 1;
	for ( ; f1 < 1000000000; t++) {
		int f = f1;
		f1 = f1 + f0;
		f0 = f1;
	}
	printf("f1 = %d, max = %d\n", f1, t);
#endif
	while (~scanf("%d", &T)) {
		for (int Case = 1; Case <= T; Case++) {
			scanf("%d", &N);
			llg.Init(N);
			da.Init();
			for (int i = 0; i < N - 1; i++) {
				int u, v, l;
				scanf("%d%d%d", &u, &v, &l);
				u--;
				v--;
				llg.AddEdge(u, v, l);
				llg.AddEdge(v, u, l);
				da.Insert(l);
			}
			da.Build();
#if 0
			printf("#da = %d: ", da.l);
			for (int i = 0; i < da.l; i++) {
				printf("%4d", da.Ask(da[i]));
			}
			puts("");
#endif
			fst.Init(0, da.l);
			rt[0] = fst.phi;
			Travel(0);
			lca.Init(0, &llg);
#if 0
			printf("N = %d\n", lca.V);
			printf("dep: ");
			for (int i = 0; i < 2 * N; i++) {
				printf("%4d", lca.dep[i]);
			}
			puts("");
			printf("ta: ");
			for (int i = 0; i < 2 * N; i++) {
				printf("%4d", lca.ta[i]);
			}
			puts("");
			printf("id: ");
			for (int i = 0; i < 2 * N; i++) {
				printf("%4d", lca.id[i]);
			}
			puts("");
			printf("L: ");
			for (int i = 0; i < N; i++) {
				printf("%4d", lca.L[i]);
			}
			puts("");
#endif
			scanf("%d", &M);
			printf("Case #%d:\n", Case);
			while (M--) {
				int u, v;
				scanf("%d%d", &u, &v);
				u--;
				v--;
#if 0
				printf("Quest %d, %d\n", u + 1, v + 1);
#endif
				puts(YYCIO(u, v)? "Yes": "No");
			}
		}
	}
	return 0;
}
