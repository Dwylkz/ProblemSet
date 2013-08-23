#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3+10;
const int inf = 0x7fffffff;

namespace graph {
  struct edge_t {
    int v, to, w;
  };
  vector<edge_t> E;
  int L[N];
  void init(int n) {
    E.clear();
    memset(L, -1, sizeof(int)*n);
  }
  void add(int u, int v, int w) {
    edge_t t = {v, L[u], w};
    L[u] = E.size();
    E.push_back(t);
  }
}
using namespace graph;

int n, m;

// lower bound of maximum power limit
int lb, f[N], fs[N];
void dfs(int u = 0, int p = -1) {
  int is = 1;
  fs[u] = 0;
  f[u] = 0;
  for (int e = L[u]; ~e; e = E[e].to) {
    if (e == p) continue;
    is = 0;
    int v = E[e].v, w = E[e].w;
    dfs(v, e^1);
    int t = f[v];
    if (w <= lb) t = min(f[v], w);
    if (t != inf) {
      f[u] += t;
      fs[v] = 0;
    }
    fs[u] += fs[v];
  }
  if (fs[u] += is) f[u] = inf;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; scanf("%d%d", &n, &m), n || m; ) {
    init(n);
    for (int i = 0; i < n-1; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      add(--u, --v, w);
      add(v, u, w);
    }
    int L = 1, R = N, ans = -1;
    for ( ; L < R; ) {
      lb = L+R>>1;
      dfs();
      if (f[0] <= m && !fs[0]) {
        ans = R = lb;
      } else L = lb+1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
