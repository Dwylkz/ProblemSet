/*
 Maximum-stream again.
 
 We can divide the graph into 5 part.
 
 super-source -----> food -----> customer -----> drink -----> super-sink
               fi           1               1            dj
 fi as the amount of ith food.
 di as the amount of jth drink.
 
 The graph above insure that
 every customer will be served at least one kind of food and drink.
 Thus we have to split a customer into two node.
 Connect them with a directed edge which capacity is 1 to guarantee that
 everyone will be served exactly one kind of food and one kind of drink.

 Then sap.
 */
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
#include <cmath>
using namespace std;
//STL
#define MS(c, a) memset(c, a, sizeof c)
//Syntax
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
//DEBUG
#define FK puts("Fu*k here!")
//Type
typedef unsigned int UI;
typedef long long LL;
typedef long double LD;
//Constant
const LL INFL = 0x7fffffffffffffffLL;
const int INFI = 0x7fffffff;
const int MAXN = 2005;
const int MOD = 1000000007;
//Array
typedef int AI[MAXN];
typedef bool AB[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];

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
	const static int m = MAXN * MAXN * 2;
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
//SAP  
//include: LLG
int SAP(int src, int snk, LLG *G){
	const int n = MAXN;
	const int inf = INFI;
	typedef int AI[n];
	static AI dis, gap, _L, se, Q;
	int u = src, mxf = 0, te = 0, Qf = 0, Qt = 0;
	int V = G->V, *L = G->L;
	LLG::Edge *E = G->E;
	memcpy(_L, L, sizeof L);  
	memset(dis, -1, sizeof(dis));
	memset(gap, 0, sizeof(gap));  
	gap[dis[snk] = 0] = 1;  
	Q[Qt++] = snk;
	while (Qf < Qt){ 
		int u = Q[Qf++];
		for (int i = L[u]; i != -1; i = E[i].next) {
			if (E[i].w && dis[E[i].v] < 0){  
				gap[dis[E[i].v] = dis[u] + 1]++;
				Q[Qt++] = E[i].v;  
			}  
		}
	}
	while (dis[src] < V) {
		for (int &i = _L[u]; i != -1; i = E[i].next) {
			if (E[i].w && dis[u] == dis[E[i].v] + 1) {
				break;  
			}
		}
		if (_L[u] != -1) {  
			u = E[se[te++] = _L[u]].v;  
			if (u == snk) {  
				int _i = 0, mf = inf;  
				for (int i = 0; i < te; i++) {
					if (E[se[i]].w < mf){  
						mf = E[se[i]].w;
						_i = i;  
					}
				}  
				for (int i = 0; i < te; i++) { 
					E[se[i]].w -= mf;
					E[se[i] ^ 1].w += mf;  
				}  
				mxf += mf;
				te = _i;  
				u = E[se[_i] ^ 1].v;  
			}  
			continue;  
		}  
		int md = V;
		_L[u] = -1;  
		for (int i = L[u]; i != -1; i = E[i].next) {
			if (E[i].w && dis[E[i].v] < md){  
				md = dis[E[i].v];
				_L[u] = i;  
			}  
		}
		if (!--gap[dis[u]]) {
			break;  
		}
		gap[dis[u] = md + 1]++;  
		if (u != src) {
			u = E[se[te-- - 1] ^ 1].v;  
		}
	}  
	return mxf;  
}  


LLG G;
int n, f, d;

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
	//freopen("test.out", "w", stdout);
#endif
	while (~scanf("%d%d%d", &n, &f, &d))
	{
		//puts("here");
		int V = 1 + f + 2 * n + d + 1, src = 0, snk = V - 1;
		G.Init(V);
		Rep(i, 0, n)
		{
			int u = 1 + f + 2 * i, v = u + 1;
			G.FlowAddEdge(u, v, 1);
		}
		Rep(i, 0, f)
		{
			int fi, v = 1 + i;
			scanf("%d", &fi);
			G.FlowAddEdge(src, v, fi);
		}
		Rep(i, 0, d)
		{
			int di, u = 1 + f + 2 * n + i;
			scanf("%d", &di);
			G.FlowAddEdge(u, snk, di);
		}
		Rep(i, 0, n)
		{
			int v = 1 + f + 2 * i;
			char fd[MAXN];
			scanf("%s", fd);
			Rep(j, 0, f) if (fd[j] == 'Y')
			{
				int u = 1 + j;
				G.FlowAddEdge(u, v, 1);
			}
		}
		Rep(i, 0, n)
		{
			int u = 1 + f + 2 * i + 1;
			char fd[MAXN];
			scanf("%s", fd);
			Rep(j, 0, d) if (fd[j] == 'Y')
			{
				int v = 1 + f + 2 * n + j;
				G.FlowAddEdge(u, v, 1);
			}
		}
		printf("%d\n", SAP(src, snk, &G));
	}
	return 0;
}
