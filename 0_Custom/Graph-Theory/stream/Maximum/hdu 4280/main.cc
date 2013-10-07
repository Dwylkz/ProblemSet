#pragma comment(linker, "/STACK:65536000,65536000")
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e5+10;

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

/* SAP dfs
 * sap(E, L, V, src, snk) */
template<class edge_t, int N> struct sap_t {
  int dis[N], gap[N], H[N], *L, V, src, snk, nogap;
  vector<edge_t> E;
  int dfs(int u, int f = ~1u>>1) {
    if (u == snk) return f;
    int rf = f;
    for (int e = H[u]; ~e; e = E[e].to) {
      int v = E[e].v, &w = E[e].w;
      if (!w || dis[u] != dis[v]+1) continue;
      int df = dfs(v, min(w, rf));
      w -= df, E[e^1].w += df;
      if (!(rf -= df)) return f;
    }
    int mn = V;
    for (int e = L[u]; ~e; e = E[e].to)
      if (E[e].w && dis[E[e].v] < mn) H[u] = e, mn = dis[E[e].v];
    if (!--gap[dis[u]]) nogap = 0;
    gap[dis[u] = mn+1]++;
    return f-rf;
  }
  int operator () (vector<edge_t> &_E, int *_L, int _V, int _src, int _snk) {
    E = _E, L = _L, V = _V, src = _src, snk = _snk;
    for (int i = 0; i < V; i++) dis[i] = -1, gap[i] = 0, H[i] = L[i];
    int result = 0;
    vector<int> q(1, snk);
    gap[dis[snk] = 0] = 1;
    for (int h = 0; h < q.size(); h++)
      for (int e = L[q[h]]; ~e; e = E[e].to)
        if (E[e].w && !~dis[E[e].v])
          gap[dis[E[e].v] = dis[q[h]]+1]++, q.push_back(E[e].v);
    for (nogap = 1; dis[src] < V && nogap; ) result += dfs(src);
    return result;
  }
};

struct island_t {
  int x, y;
  void input() {
    scanf("%d%d", &x, &y);
  }
};

sap_t<edge_t, N> sap;
island_t island[N];
int n, m;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d%d", &n, &m);
    island[0].input();
    int src = 0, snk = 0, V = n;
    for (int i = 1; i < n; i++) {
      island[i].input();
      if (island[i].x < island[src].x) src = i;
      if (island[i].x > island[snk].x) snk = i;
    }
    init();
    for ( ; m--; ) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      u--, v--;
      add(u, v, w);
      add(v, u, w);
    }
    printf("%d\n", sap(E, L, V, src, snk));
  }
  return 0;
}
