/* This is an troublesome problem, and I think it's hard for me.
 * Graph Theory, it has been a long time since
 * the last graph problem i solved.
 *
 * OK, let's talk about this dick.
 * 
 * Fisrt, we found that each node only has one out degree, which means
 * there are only N edges in a N nodes connected graph,
 * and, obviously, a circle would be exist in a connected graph.
 *
 * We regard each circle as a strong connected component, AKA SCC.
 * Then, another characteristic appear.
 * That is, SCC doesn't have out degree.
 *
 * After calculating all SCC in an connected graph, we could see that
 * SCCs construct a tree-like structure.
 * I would like to call it SCC tree.
 *
 * Hence, in a connected graph, the only circle, must be
 * the root of the SCC tree.
 *
 * We add an extra node as the root of all connected graph.
 *
 * Then the required answer could be equal to a classic LCA problem --
 * calculate the length of the unique path of two specifc node.
 * But it would be more situations since it's a SCC tree. */
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
	  maxn = 4e5 + 10;
const long long inf64 = 0x7fffffffffffffffLL; 
//type definition
typedef bool AB[maxn];
typedef int AI[maxn];
typedef char AC[maxn];
typedef long long LL;
//Extern
int n, m;
struct Edge {
	int v, to;
};
vector<Edge> E;
AI L;
void GInit() {
	E.clear();
	memset(L, -1, sizeof(L));
}
void AE(int u, int v) {
	Edge te = {v, L[u]};
	L[u] = E.size();
	E.push_back(te);
}
AI low, dfn, belong, csize, toc;
AB inS, crt;
stack<int> S;
int timing, ccnt, rt;
void Tarjan(int u) {
	S.push(u);
	inS[u] = 1;
	low[u] = dfn[u] = timing++;
	for (int i = L[u]; i != -1; i = E[i].to) {
		int v = E[i].v;
		if (dfn[v] == -1) {
			Tarjan(v);
			dfn[u] = min(dfn[u], dfn[v]);
		} else if (inS[v]) {
			dfn[u] = min(dfn[u], low[v]);
		}
	}
	if (low[u] == dfn[u]) {
		int v;
		do {
			v = S.top();
			inS[v] = 0;
			S.pop();
			csize[belong[v] = ccnt]++;
		} while (v != u);
		ccnt++;
	}
}
void Compress() {
	memset(crt, 0, sizeof(crt));
	for (int u = rt; u < ccnt; u++) {
		toc[u] = u;
	}
	for (int u = 1; u <= n; u++) {
		int v = E[L[u]].v,
			cu = belong[u], cv = belong[v];
		if (cu == cv) {
			if (!crt[cu]) {
				AE(rt, cu);
				crt[cu] = 1;
			}
		} else {
			AE(cv, cu);
			toc[cu] = v;
		}
	}
}
void TInit() {
	timing = 0;
	rt = n + 1;
	ccnt = rt + 1;
	memset(inS, 0, sizeof(inS));
	memset(csize, 0, sizeof(csize));
	memset(dfn, -1, sizeof(dfn));
	for ( ; !S.empty(); S.pop()) {}
	for (int u = 1; u <= n; u++) {
		if (dfn[u] == -1) {
			Tarjan(u);
		}
	}
	Compress();
}
AI ldis;
void LoopDis() {
	memset(ldis, -1, sizeof(ldis));
	for (int u = 1; u <= n; u++) {
		int d = 0;;
		for (int v = u; ldis[v] == -1; v = E[L[v]].v) {
			ldis[v] = d++;
		}
	}
}
AI dep, anc[20];
void LInit(int d, int u, int p = -1) {
	dep[u] = d;
	if (p != -1) {
		anc[0][u] = p;
		for (int i = 1; i < 20; i++) {
			anc[i][u] = anc[i - 1][anc[i - 1][u]];
		}
	}
	for (int i = L[u]; i != -1; i = E[i].to) {
		if (1 < d) {
			toc[E[i].v] = toc[u];
		}
		LInit(d + 1, E[i].v, u);
	}
}
int LCA(int u, int v) {
	if (dep[u] < dep[v]) {
		swap(u, v);
	}
	int k = dep[u] - dep[v];
	for ( ; k; k -= -k & k) {
		int p = 0;
		for ( ; (1 << p) < (-k & k); p++) {}
		u = anc[p][u];
	}
	for (int i = 20; u != v && 0 <= i; i--) {
		if ((1 << i) <= dep[u] && anc[i][u] != anc[i][v]) {
			u = anc[i][u];
			v = anc[i][v];
		}
	}
	return u == v? u: anc[0][u];
}
void Debug() {
	printf("After tarjan:\n");
	printf("ccnt = %d\n", ccnt);
	printf("csize: ");
	for (int i = rt; i < ccnt; i++) {
		printf(" %d", csize[i]);
	}
	puts("");
	printf("belong: ");
	for (int u = 1; u <= n; u++) {
		printf(" %d", belong[u]);
	}
	puts("");
	printf("After Loopdis:\n");
	printf("Loopdis: ");
	for (int u = 1; u <= n; u++) {
		printf(" %d", ldis[u]);
	}
	puts("");
	printf("After LInit:\n");
	printf("toc: ");
	for (int u = 1; u < ccnt; u++) {
		printf(" %d", toc[u]);
	}
	puts("");
}
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	while (~scanf("%d", &n)) {
		GInit();
		for (int u = 1; u <= n; u++) {
			int v;
			scanf("%d", &v);
			AE(u, v);
		}
		TInit();
		LoopDis();
		LInit(0, rt);
		for (int u = 1; u <= n; u++) {
			int cu = belong[u];
			if (toc[cu] != cu) {
				toc[u] = toc[cu];
			} else {
				toc[u] = u;
			}
		}
		//Debug();
		scanf("%d", &m);
		while (m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			int cu = belong[u], cv = belong[v],
				lca = LCA(cu, cv),
				res = dep[cu] + dep[cv] - 2 * dep[lca];
			if (lca == rt) {
				res = -1;
			} else if (1 < csize[lca]) {
				res += abs(ldis[toc[u]] - ldis[toc[v]]);
			}
			printf("%d\n", res);
		}
	}
	return 0;
}
