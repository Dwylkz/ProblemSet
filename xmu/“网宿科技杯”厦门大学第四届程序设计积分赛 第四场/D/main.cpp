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
//type definition
typedef int AB[maxn];
typedef int AI[maxn];
typedef char AC[maxn];
typedef long long LL;
//Extern
struct Edge {
	int v, to;
};
vector<Edge> E;
int L[maxn];
void initEdge() {
	E.clear();
	memset(L, -1, sizeof(L));
}
void AE(int u, int v) {
	Edge te = {v, L[u]};
	L[u] = E.size();
	E.push_back(te);
}
int n, m;
AI a;
AI f[20], anc[20], dep;
void initF(int u, int p = -1) {
	if (u) {
		dep[u] = dep[p] + 1;
		anc[0][u] = p;
		for (int i = 1; i < 20; i++) {
			anc[i][u] = anc[i - 1][anc[i - 1][u]];
		}
		f[0][u] = max(a[u], a[p]);
		for (int i = 1; i < 20; i++) {
			f[i][u] = max(f[i - 1][u], f[i - 1][anc[i - 1][u]]);
		}
	} else {
		dep[u] = 0;
		f[0][u] = 0;
	}
	for (int i = L[u]; i != -1; i = E[i].to) {
		initF(E[i].v, u);
	}
}
int findMax(int u, int k) {
	int mx = -1;
	for ( ; k; k -= -k & k) {
		int i = 0;
		for ( ; (1 << i) < (-k & k); i++) {}
		mx = max(mx, f[i][u]);
		u = anc[i][u];
	}
	return mx;
}
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	a[0] = 0;
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
		}
		initEdge();
		for (int v = 1; v <= n; v++) {
			int u;
			scanf("%d", &u);
			AE(u, v);
		}
		initF(0);
		scanf("%d", &m);
		while (m--) {
			int u, k;
			scanf("%d%d", &k, &u);
			if (dep[u] < k) {
				puts("Wrong request");
			} else {
				printf("%d\n", findMax(u, k));
			}
		}
	}
	return 0;
}
