#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e4+10;

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

struct lca_t {
  static const int M = 16;
  int d[N], a[N][M], p[1<<M];
  void operator () (vector<edge_t> E, int *L, int u) {
    vector<int> q(1, u);
    memset(a, -1, sizeof(a));
    for (int h = d[u] = 0; h < q.size(); h++) {
      u = q[h];
      for (int i = 1; i < M; i++)
        if (~a[u][i-1]) a[u][i] = a[a[u][i-1]][i-1];
      for (int e = L[u]; ~e; e = E[e].to) {
        int v = E[e].v;
        if (v == a[u][0]) continue;
        d[v] = d[u]+1;
        a[v][0] = u;
        q.push_back(v);
      }
    }
    for (int i = 0; i < M; i++) p[1<<i] = i;
  }
  int skip(int u, int x) {
    for ( ; x; x -= -x&x) u = a[u][p[-x&x]];
    return u;
  }
  int operator () (int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    u = skip(u, d[u]-d[v]);
    if (u == v) return u;
    for (int i = M-1; ~i && a[u][0] != a[v][0]; i--)
      if (~a[u][i] && a[u][i] != a[v][i])
        u = a[u][i], v = a[v][i];
    return a[u][0];
  }
} lca;

int n;

int d[N];
void dfs(int u, int p = -1, int _d = 0) {
  d[u] = _d;
  for (int e = L[u]; ~e; e = E[e].to)
    if (E[e].v != p) dfs(E[e].v, u, _d+E[e].w);
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d", &n);
    init();
    for (int i = 0; i < n-1; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      u--, v--;
      add(u, v, w);
      add(v, u, w);
    }
    dfs(0);
    lca(E, L, 0);
    for (char op[10]; scanf("%s", op), op[1] != 'O'; ) {
      int x, y;
      scanf("%d%d", &x, &y);
      x--, y--;
      int a = lca(x, y);
      if (op[1] == 'T') {
        int z, du = lca.d[x]-lca.d[a]+1, dv = lca.d[y]-lca.d[a];
        scanf("%d", &z);
        if (z <= du) printf("%d\n", lca.skip(x, z-1)+1);
        else printf("%d\n", lca.skip(y, dv-(z-du))+1);
      } else printf("%d\n", d[x]+d[y]-2*d[a]);
    }
    puts("");
  }
  return 0;
}
