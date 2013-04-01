#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define MAXN (1024)
#define MAXB (24)
#define INF32 (0x7fffffff)
#define LLU int

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
		L.clear();
		for (int i = 0; i < V; i++) {
			L.push_back(-1);
		}
	}
	//AddEdge 
	//usage: obj.AddEdge(From, To, Extern)
	void AddEdge(int u, int v, int w) {
		Node t =  {w, v, L[u]}; //rule: Node t = {Extern, Basic}
		L[u] = E.size();
		E.push_back(t);
	}
	//FlowAddEdge 
	//usage: obj.AddEdge(From, To, Extern)
	void FlowAddEdge(int u, int v, int w) {
		Node t =  {w, v, L[u]}; //rule: Node t = {Extern, Basic}
		L[u] = E.size();
		E.push_back(t);
		AddEdge(u, v, w);
		AddEdge(v, u, 0);
	}
};
//SAP
//include: Graph, Graph::Node[extern int w]
int SAP(int src, int snk, Graph *G){
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
				int _i = 0, mf = 0x7fffffff;
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
		for (int i = G->L[u]; i != -1; i = G->E[i].next) {
			if (G->E[i].w && dis[G->E[i].v] < md) {
				md = dis[G->E[i].v];
				_L[u] = i;
			}
		}
		if (!gap[dis[u]]) {
			break;
		}
		gap[dis[u] = md + 1]++;
		if (u != src) {
			u = G->E[se[te-- - 1] ^ 1].v;
		}
	}
	return mxf;
}

int n, m
LLU N, b, c[MAXN][MAXB], r[MAXB];

bool chk(LLU det)
{
    int ans;

    n = N + b;
    Rep(s, 0, b - det + 1)
    {
        G.Init(n + 2);
        Rep(i, 0, N)
        {
            G.FlowAddEdge(n, i, 1);
            Rep(j, s, s + det)
                G.FlowAddEdge(i, N + c[i][j], 1);
        }
        Rep(i, 0, b)
            G.FlowAddEdge(N + i, n + 1, r[i]);
#if 0
        Rep(i, 0, n + 2)
        {
            printf("%d: ", i);
            for (int j = L[i]; j != -1; j = E[j].next)
                if (E[j].w) printf("(%d,%d)", E[j].v, E[j].w);
            printf("\n");
        }
#endif
        ans = SAP(n, n + 1, &G);
#if 0
        printf(" maxf = %d\n", ans);
#endif
        if (ans == N) return 1;
    }

    return 0;
}

LLU BS(LLU l, LLU r)
{
    LLU m;

    while (l < r)
    {
        m = (l + r) >> 1;
#if 0
        printf("m = %d\n", m);
#endif
        if (chk(m)) r = m;
        else l = m + 1;
    }

    return l;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("test.txt", "rt", stdin);
#endif

    int tc;

    scanf("%d%d", &N, &b);
    Rep(i, 0, N) Rep(j, 0, b)
    {
        scanf("%d", c[i] + j);
        c[i][j]--;
        /*scanf("%d", &tc);
        c[i][tc - 1] = j;*/
    }
    Rep(i, 0, b) scanf("%d", r + i);
#if 0
    Rep(i, 0, b) printf("%d ", r[i]);
    printf("\n");
#endif
    printf("%d\n", BS(1, b));

    return 0;
}
