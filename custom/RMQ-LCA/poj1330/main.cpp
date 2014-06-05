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
#include <cmath>
//namespaces
using namespace std;
//constants
const char input[] = "input.in",
	  output[] = "output.out";
const int inf32 = 0x7fffffff,
	  maxn = 1e5 + 10;
const long long inf64 = 0x7fffffffffffffffLL; 
//structure
struct Edge {
	int v, t;
};
vector<Edge> E;
int L[maxn];
void EdgeInit() {
	E.clear();
	memset(L, -1, sizeof(L));
}
void AE(int u, int v) {
	Edge te = {v, L[u]};
	L[u] = E.size();
	E.push_back(te);
}
//type definition
typedef long long LL;
//global variable
int n, ind[maxn];
//access and mutator
int dep[maxn], anc[maxn][20];
//Doubling LCA
//usage: LCAInit()->LCA();
void LCAInit(int u, int d = 0, int p = -1) { dep[u] = d;
	if (p != -1) {
		anc[u][0] = p;
		for (int i = 1; i < 20; i++) {
			anc[u][i] = anc[anc[u][i - 1]][i - 1];
		}
	}
	for (int i = L[u]; i != -1; i = E[i].t) {
		if (E[i].v != p) {
			LCAInit(E[i].v, d + 1, u);
		}
	}
}
void JKA(int &u, int k) {
	for ( ; k; k -= -k & k) {
		for (int i = 0; i < 20; i++) {
			if ((1 << i) == (-k & k)) {
				u = anc[u][i];
				break;
			}
		}
	}
}
int LCA(int u, int v) {
	if (dep[u] < dep[v]) {
		swap(u, v);
	}
	JKA(u, dep[u] - dep[v]);
	for (int i = 20; u != v && 0 <= i; i--) {
		if ((1 << i) <= dep[u] && anc[u][i] != anc[v][i]) {
			u = anc[u][i];
			v = anc[v][i];
		}
	}
	return u == v? u: anc[u][0];
}
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		EdgeInit();
		memset(ind, 0, sizeof(ind));
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			AE(u, v);
			ind[v]++;
		}
		for (int u = 1; u <= n; u++) {
			if (!ind[u]) {
				LCAInit(u);
				break;
			}
		}
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", LCA(u, v));
	}
	return 0;
}
