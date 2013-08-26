#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 3e3+10;
const int inf = 1e9+10;

struct edge_t {
  int v, to, w;
};
vector<edge_t> E;
int L[N];
void init() {
  E.clear();
  memset(L, -1, sizeof(L));
}
void add(int u, int v, int w) {
  edge_t t = {v, L[u], w};
  L[u] = E.size();
  E.push_back(t);
}
void badd(int u, int v, int w) {
  add(u, v, w);
  add(v, u, 0);
}

int n, m, tot, a[N], b[N], g[N][N];

int sap(vector<edge_t> &E, int *L, int src, int snk, int V) {
	static int dis[N], gap[N], _L[N], se[N];
  int mxf = 0, te = 0;
	memcpy(_L, L, sizeof(L));  
	memset(dis, -1, sizeof(dis));
	memset(gap, 0, sizeof(gap));  
	gap[dis[snk] = 0] = 1;  
  vector<int> q(1, snk);
	for (int h = 0; h < q.size(); h++)
		for (int i = L[q[h]]; i != -1; i = E[i].to)
			if (E[i].w && dis[E[i].v] < 0) {
				gap[dis[E[i].v] = dis[q[h]]+1]++;
        q.push_back(E[i].v);
			}
	for (int u = src; dis[src] < V; ) {
		for (int &i = _L[u]; i != -1; i = E[i].to)
			if (E[i].w && dis[u] == dis[E[i].v] + 1) break;  
		if (_L[u] != -1) {
			u = E[se[te++] = _L[u]].v;
			if (u == snk) {
				int _i = 0, mf = inf;
				for (int i = 0; i < te; i++)
					if (E[se[i]].w < mf) {
						mf = E[se[i]].w;
						_i = i;
					}
				for (int i = 0; i < te; i++) {
					E[se[i]].w -= mf;
					E[se[i]^1].w += mf;
				}
				mxf += mf;
				u = E[se[te = _i]^1].v;
			}
			continue;
		}
		int md = V;
		_L[u] = -1;
		for (int i = L[u]; i != -1; i = E[i].to)
			if (E[i].w && dis[E[i].v] < md) {
				md = dis[E[i].v];
				_L[u] = i;
			}
		if (!--gap[dis[u]]) break;
		gap[dis[u] = md+1]++;
		if (u != src) u = E[se[te---1]^1].v;
	}
	return mxf;
}

bool check(int lim) {
  init();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (g[i][j] <= lim) badd(i, n+j, inf);
  int src = n+n, snk = src+1;
  for (int i = 0; i < n; i++) {
    badd(src, i, a[i]);
    badd(n+i, snk, b[i]);
  }
  return sap(E, L, src, snk, snk+1) == tot;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    tot = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", a+i, b+i);
      tot += a[i];
    }
    memset(g, 0x7f, sizeof(g));
    int lim = 0;
    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      u--, v--;
      g[u][v] = min(g[u][v], w);
      g[v][u] = min(g[v][u], w);
      lim = max(lim, w);
    }
    for (int i = 0; i < n; i++) g[i][i] = 0;
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if (g[i][j]-g[i][k] > g[k][j])
            g[i][j] = g[i][k]+g[k][j];
    int L = 0, R = lim, ans = -1;
    for ( ; L < R; ) {
      int m = L+R>>1;
      if (check(m)) ans = R = m;
      else L = m+1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
