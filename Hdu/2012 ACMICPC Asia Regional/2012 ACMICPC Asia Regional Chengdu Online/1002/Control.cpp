/*
 This problem corrspond to kind of Minimum-Cut staff

 Split a city into two node(I'd love to call it input-node and output-node).

 Connect them with a directed edge and
 the edge's capacity as the cost of the city
 
 A supper source node connect to the input-node of city S
 The output-node of city-D connect to the sink node
 Both edges above has an infinte capacity.

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

//FSG
struct Edge{
    int v, w, next;
};
vector<Edge> E;
AI L;
void G_ini(){
	E.clear(); MS(L, -1);
}
void AE(int u, int v, int w){
	Edge te = {v, w, L[u]};
	L[u] = E.size();
	E.push_back(te);
}
void SAE(int u, int v, int w){
	AE(u, v, w); AE(v, u, 0);
}
#define Ere(c, a, L) for (int c = L[a]; c != -1; c = E[c].next)

//SAP
int SAP(int src, int snk, int V){
	static AI dis, gap, _L, se;
	int u = src, mxf = 0, te = 0;
	memcpy(_L, L, sizeof L);
	MS(dis, -1); MS(gap, 0);
	gap[dis[snk] = 0] = 1;
	queue<int> Q; Q.push(snk);
	while (!Q.empty()){
		int u = Q.front(); Q.pop();
		Ere(i, u, L) if (E[i].w && dis[E[i].v] < 0){
			gap[dis[E[i].v] = dis[u] + 1]++; Q.push(E[i].v);
		}
	}
	while (dis[src] < V){
		for (int &i = _L[u]; i != -1; i = E[i].next)
			if (E[i].w && dis[u] == dis[E[i].v] + 1) break;
		if (_L[u] != -1){
			u = E[se[te++] = _L[u]].v;
			if (u == snk){
				int _i = 0, mf = INFI;
				Rep(i, 0, te) if (E[se[i]].w < mf){
					mf = E[se[i]].w; _i = i;
				}
				Rep(i, 0, te){
					E[se[i]].w -= mf; E[se[i] ^ 1].w += mf;
				}
				mxf += mf; te = _i;
				u = E[se[_i] ^ 1].v;
			}
			continue;
		}
		int md = V;
		Ere(i, u, L) if (E[i].w && dis[E[i].v] < md){
			md = dis[E[i].v]; _L[u] = i;
		}
		if (!--gap[dis[u]]) break;
		gap[dis[u] = md + 1]++;
		if (u != src) u = E[se[te-- - 1] ^ 1].v;
	}
	return mxf;
}

int n, m, s, d;

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	while (~scanf("%d%d", &n, &m))
	{
		G_ini();
		scanf("%d%d", &s, &d);
		int V = 2 * n + 2, src = V - 2, snk = V - 1; 
		s = (s - 1) << 1;
		d = (d - 1) << 1;
		SAE(src, s, INFI);
		SAE(d + 1, snk, INFI);
		Rep(i, 0, n)
		{
			int w, u = i << 1;
			scanf("%d", &w);
			SAE(u, u + 1, w);
		}
		while (m--)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			u = (u - 1) << 1;
			v = (v - 1) << 1;
			SAE(u + 1, v, INFI);
			SAE(v + 1, u, INFI);
		}
		printf("%d\n", SAP(src, snk, V));
	}
	return 0;
}
