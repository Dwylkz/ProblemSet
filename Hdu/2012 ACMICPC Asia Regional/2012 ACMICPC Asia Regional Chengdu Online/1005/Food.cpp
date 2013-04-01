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
		int md = V; _L[u] = -1;
		Ere(i, u, L) if (E[i].w && dis[E[i].v] < md){
			md = dis[E[i].v]; _L[u] = i;
		}
		if (!--gap[dis[u]]) break;
		gap[dis[u] = md + 1]++;
		if (u != src) u = E[se[te-- - 1] ^ 1].v;
	}
	return mxf;
}

int n, f, d;

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	while (~scanf("%d%d%d", &n, &f, &d))
	{
		G_ini();
		int V = 1 + f + 2 * n + d + 1, src = 0, snk = V - 1;
		Rep(i, 0, n)
		{
			int u = 1 + f + 2 * i, v = u + 1;
			AE(u, v, 1); AE(v, u, 0);
		}
		Rep(i, 0, f)
		{
			int fi, v = 1 + i;
			scanf("%d", &fi);
			AE(src, v, fi); AE(v, src, 0);
		}
		Rep(i, 0, d)
		{
			int di, u = 1 + f + 2 * n + i;
			scanf("%d", &di);
			AE(u, snk, di); AE(snk, u, 0);
		}
		Rep(i, 0, n)
		{
			int v = 1 + f + 2 * i;
			char fd[MAXN];
			scanf("%s", fd);
			Rep(j, 0, f) if (fd[j] == 'Y')
			{
				int u = 1 + j;
				AE(u, v, 1); AE(v, u, 0);
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
				AE(u, v, 1); AE(v, u, 0);
			}
		}
		printf("%d\n", SAP(src, snk, V));
	}
	return 0;
}
