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
//type definition
typedef long long LL;
//global variable
LLG llg;
int N, M, dep[maxn], pre[maxn];
//access and mutator
void Travel(int u, int p = -1) {
	if (p != -1) {
		pre[u] = p;
		dep[u] = dep[llg.E[p].v] + 1;
	}
	for (int i = llg.L[u]; i != -1; i = llg.E[i].next) {
		if (i != p) {
			Travel(llg.E[i].v, i ^ 1);
		}
	}
}
bool YYCIO(int u, int v) {
	vector<int> E;
	while (u != v && E.size() < 32) {
		if (dep[v] <= dep[u]) {
			E.push_back(llg.E[pre[u]].w);
			u = llg.E[pre[u]].v;
		} else {
			E.push_back(llg.E[pre[v]].w);
			v = llg.E[pre[v]].v;
		}
	}
	sort(E.begin(), E.end());
	for (int i = 2; i < E.size(); i++) {
		if (E[i] < E[i - 2] + E[i - 1]) {
			return 1;
		}
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
	while (~scanf("%d", &T)) {
		for (int Case = 1; Case <= T; Case++) {
			scanf("%d", &N);
			llg.Init(N);
			for (int i = 0; i < N - 1; i++) {
				int u, v, l;
				scanf("%d%d%d", &u, &v, &l);
				u--;
				v--;
				llg.AddEdge(u, v, l);
				llg.AddEdge(v, u, l);
			}
			memset(dep, 0, sizeof(dep));
			Travel(0);
			scanf("%d", &M);
			printf("Case #%d:\n", Case);
			while (M--) {
				int u, v;
				scanf("%d%d", &u, &v);
				u--;
				v--;
				puts(YYCIO(u, v)? "Yes": "No");
			}
		}
	}
	return 0;
}
