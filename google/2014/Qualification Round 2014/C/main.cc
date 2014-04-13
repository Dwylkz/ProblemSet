#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 2e3+10;

template<int N> struct graph_t {
	struct edge_t {
		int v, to;
	};
	vector<edge_t> E;
	int L[N];
	void init() {
		E.clear();
		memset(L, -1, sizeof(L));
	}
	void add(int u, int v) {
		edge_t t = {v, L[u]};
		L[u] = E.size();
		E.push_back(t);
	}
};
template<class edge_t, int N> struct bgm_t {
	int vis[N], pre[N], lma[N], rma[N];
	bool bfs(vector<edge_t> &E, int *L, int u) {
		vector<int> q(1, u);
		memset(vis, 0, sizeof(vis));
		memset(pre, -1, sizeof(pre));
		for (int h = 0; h < q.size(); h++) {
			u = q[h];
			for (int e = L[u]; ~e; e = E[e].to) {
				int v = E[e].v;
				if (!vis[v]) {
					vis[v] = 1;
					if (rma[v] == -1) {
						for ( ; ~u; ) {
							rma[v] = u;
							swap(v, lma[u]);
							u = pre[u];
						}
						return 1;
					} else {
						pre[rma[v]] = u;
						q.push_back(rma[v]);
					}
				}
			}
		}
		return 0;
	}
	int operator () (vector<edge_t> &E, int *L, int V) {
		int mmat = 0;
		memset(lma, -1, sizeof(lma));
		memset(rma, -1, sizeof(rma));
		for (int u = 0; u < V; u++)
			mmat += bfs(E, L, u);
		return mmat;
	}
};

int solve(int n, double a[], double b[]) {
	graph_t<N> g;
	bgm_t<graph_t<N>::edge_t, N> bgm;
	g.init();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i] > b[j])
				g.add(i, n+j);
	return bgm(g.E, g.L, n+n);
}

int main() {
#if 0
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
  for (int cas = 1; cas <= T; cas++) {
		printf("Case #%d:", cas);
		int n;
		double a[N], b[N];
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%lf", a+i);
		for (int i = 0; i < n; i++) scanf("%lf", b+i);
		printf(" %d %d\n", solve(n, a, b), n-solve(n, b, a));
  }
  return 0;
}
