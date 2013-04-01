//Head
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
//Dwylkz
namespace Dwylkz{
	//Type
	typedef unsigned int UI;
	typedef long long LL;
	typedef long double LD;
	//Constant
	const LL INFLL = ~0uLL >> 1;
	const int INFI = ~0u >> 1;
	const int MAXN = 1e6;
	const int MOD = 1e9 + 7;
	//Array
	typedef int AI[MAXN];
	typedef bool AB[MAXN];
	typedef double AD[MAXN];
	typedef LL ALL[MAXN];
	typedef LD ALD[MAXN];
	typedef vector<int> VI;
}
using namespace Dwylkz;
//Macro
#define MS(c, a) memset(c, a, sizeof c)
#define Rep(c, a, b) for (int c = a; c < int(b); c++)
#define Nre(c, a, b) for (int c = a; c > int(b); c--)
#define FK puts("Here")
//Graph
struct Edge{
	int v, next;
};
vector<Edge> E;
AI L;
void G_ini(){
	MS(L, -1);
	E.clear();
}
void AE(int u, int v){
	Edge t = {v, L[u]};
	L[u] = E.size();
	E.push_back(t);
}
//Global
int n, k;
AI c, Q;
AB vis;
//DFS
void DFS(int u = 0){
	vis[u] = 1;
	for (int i = L[u]; i != -1; i = E[i].next){
		int v = E[i].v;
		if (c[u] != c[v]) Q[c[u]]++, Q[c[v]]++;
		if (!vis[v]) DFS(v);
	}
}
//Main
int main(){
#if 0
	freopen("test.txt", "r", stdin);
	//freopen("test.out", "w", stdout);
#endif
	while (~scanf("%d%d", &n, &k)){
		for (int i = 0; i < n; i++) scanf("%d", c + i);
		G_ini();
		while (k--){
			int u, v;
			scanf("%d%d", &u, &v);
			u--; v--;
			AE(u, v);
			AE(v, u);
		}
		MS(vis, 0);
		MS(Q, 0);
		DFS();
		int max = 0, id = 0;
		for (int i = 0; i < n; i++)
			if (Q[i] > max){
				max = Q[i];
				id = i;
			}
		if (!max) printf("%d\n", c[0]);
		else printf("%d\n", id);
	}
	return 0;
}
