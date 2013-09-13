#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define MAXN (20020)
#define INF32 (0x7fffffff)

//Graph
//include: vector
struct Graph {
	struct Node {
		//Externs should be defined here
		int w;
		//Basic
		int v,       //Adjust node v
			next;    //Index of the next node v
	};
	vector<Node> E;  //Aarry in which Edges store
	vector<int>  L;  //Head of linking list of nodes
	int          V;  //Total of nodes
	//Init
	//usage: obj.Init(int TotalOfNode)
	void Init(int _V = 0) {
		V = _V;
		E.clear();
		L.assign(V, -1);
	}
	//AddEdge 
	//usage: obj.AddEdge(From, To, Extern)
	void AddEdge(int u, int v, int w) {
		Node t =  {w, v, L[u]}; //rule: Node t = {Extern, Basic}
		L[u] = E.size();
		E.push_back(t);
	}
	//FlowAddEdge 
	//usage: obj.FlowAddEdge(From, To, Extern)
	void FlowAddEdge(int u, int v, int w) {
		AddEdge(u, v, w);
		AddEdge(v, u, 0);
	}
};
//SAP
//include: queue, Graph, Graph::Node[extern int w]
int SAP(int src, int snk, Graph *G){
	const int inf32 = 0x7fffffff;
	typedef vector<int> VI;
	VI dis(G->V, -1), gap(G->V, 0), _L(G->L), se(G->V, 0);
	int u = src, mxf = 0, te = 0;
	//memcpy(_L, L, sizeof L);
	//memset(dis, -1, sizeof(dis));
	//memset(gap, 0, sizeof(gap));
	gap[dis[snk] = 0] = 1;
	queue<int> Q;
	Q.push(snk);
	while (!Q.empty()){
		int u = Q.front();
		Q.pop();
		for (int i = G->L[u]; i != -1; i = G->E[i].next) {
			if (G->E[i].w && dis[G->E[i].v] < 0) {
				gap[dis[G->E[i].v] = dis[u] + 1]++;
				Q.push(G->E[i].v);
			}
		}
	}
	while (dis[src] < G->V) {
		for (int &i = _L[u]; i != -1; i = G->E[i].next) {
			if (G->E[i].w && dis[u] == dis[G->E[i].v] + 1) {
				break;
			}
		}
		if (_L[u] != -1) {
			u = G->E[se[te++] = _L[u]].v;
			if (u == snk) {
				int _i = 0, mf = inf32;
				for (int i = 0; i < te; i++) {
					if (G->E[se[i]].w < mf) {
						mf = G->E[se[i]].w;
						_i = i;
					}
				}
				for (int i = 0; i < te; i++) {
					G->E[se[i]].w -= mf;
					G->E[se[i] ^ 1].w += mf;
				}
				mxf += mf;
				te = _i;
				u = G->E[se[_i] ^ 1].v;
			}
			continue;
		}
		int md = G->V;
		_L[u] = -1;
		for (int i = G->L[u]; i != -1; i = G->E[i].next) {
			if (G->E[i].w && dis[G->E[i].v] < md) {
				md = dis[G->E[i].v];
				_L[u] = i;
			}
		}
		if (!--gap[dis[u]]) {
			break;
		}
		gap[dis[u] = md + 1]++;
		if (u != src) {
			u = G->E[se[te-- - 1] ^ 1].v;
		}
	}
	return mxf;
}

Graph G;
int n, m;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.in", "rt", stdin);
    #endif
    int a, b, c;
    while (~scanf("%d%d", &n, &m))
    {
        G.Init(n + 2);
        Rep(i, 0, n)
        {
            scanf("%d%d", &a, &b);
            G.FlowAddEdge(n, i, a);
            G.FlowAddEdge(i, n + 1, b);
        }
        Rep(i, 0, m)
        {
            scanf("%d%d%d", &a, &b, &c);
            G.FlowAddEdge(a - 1, b - 1, c);
            G.FlowAddEdge(b - 1, a - 1, c);
        }
        printf("%d\n", SAP(n, n + 1, &G));
    }
    return 0;
}
