#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <queue>
#include <stack>
using namespace std;
#define MS(c, a) memset(c, a, sizeof c)
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
#define MAXN (50050 << 1)

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
	const static int n = MAXN;
	const static int m = MAXN;
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
	const static int n = MAXN << 1;
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
	AI         dis;
	//Init
	//usage: obj.Init(int Root, Graph *Tree)
	void Init(int _rt, LLG *_G) {
		rt = _rt;
		G = _G;
		E = G->E;
		V = G->V;
		L = G->L;
		//rule: list[] = {basic, extern}
		int *list[] = {dep, ta, id, dis};
		//rule: for (int i = 0; i < listSize; i++)
		for (int i = 0; i < 4; i++) {
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
				dis[E[i].v] = dis[u] + E[i].w;
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

LLG G; 
LCA lca;
int n, q;

bool cmp(int p, int q) {
	if (lca.dep[p] != lca.dep[q]) return lca.dep[p] < lca.dep[q];
	return p < q;
}

int main() {
#if 1
	freopen("input.in", "rt", stdin);
#endif
	bool spa = 0;
	while (~scanf("%d", &n))
	{
		if (spa) puts(""); 
		spa = 1;
		G.Init(n);
		Rep(i, 0, n - 1)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			G.AddEdge(u, v, w);
			G.AddEdge(v, u, w);
		}
		lca.Init(0, &G);
		scanf("%d", &q);
		vector<int> x;
		while (q--)
		{
			int tx;
			x.clear();
			Rep(i, 0, 3)
			{
				scanf("%d", &tx);
				x.push_back(tx);
			}
			tx = x.size();
			Rep(i, 0, tx) Rep(j, 0, tx)
				x.push_back(lca.Ask(x[i], x[j]));
			sort(x.begin(), x.end(), cmp);
			x.erase(unique(x.begin(), x.end()), x.end());
			int res = 0;
			Rep(i, 1, x.size())
				Nre(j, i - 1, -1)
				{
					if (lca.Ask(x[i], x[j]) == x[j])
					{
						res += lca.dis[x[i]] - lca.dis[x[j]];
						break;
					}
				}
			printf("%d\n", res);
		}
	}
	return 0;
}
