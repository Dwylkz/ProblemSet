#pragma comment(linker, "/STACK:32768000")
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int N = 2e4+10;
const int M = 1e5+10;
typedef map<int, int> mii_t;

struct graph_t {
  struct edge_t {
    int v, to;
  };
  vector<edge_t> e;
  vector<int> h;
  edge_t &operator [] (int x) {
    return e[x];
  }
  int &operator () (int x) {
    return h[x];
  }
  int size() {
    return h.size();
  }
  void init(int n) {
    e.clear(), h.resize(n);
    fill(h.begin(), h.end(), -1);
  }
  void add(int u, int v) {
    edge_t t = {v, h[u]};
    h[u] = e.size();
    e.push_back(t);
  }
  void badd(int u, int v) {
    add(u, v), add(v, u);
  }
};

struct bcc_t {
  int time, cc, cut[N], dfn[N], low[N];
  vector<int> in, st;
  void dfs(graph_t &g, int u, int p = -1) {
    int branch = 0;
    dfn[u] = low[u] = time++;
    for (int e = g(u); ~e; e = g[e].to) {
      int v = g[e].v;
      if (e == p || dfn[v] >= dfn[u]) continue;
      st.push_back(e);
      if (~dfn[v]) low[u] = min(low[u], dfn[v]);
      else {
        branch++;
        dfs(g, v, e^1);
        low[u] = min(low[u], low[v]);
        if (dfn[u] > low[v]) continue;
        for (cut[u] = 1; ; ) {
          int t = st.back();
          st.pop_back();
          in[t] = in[t^1] = cc;
          if (t == e) break;
        }
        cc++;
      }
    }
    if (!~p && cut[u] && branch < 2) cut[u] = 0;
  }
  void operator () (graph_t &g) {
    in.resize(g.e.size());
    for (int u = 0; u < g.size(); u++)
      dfn[u] = low[u] = -1, cut[u] = 0;
    st.clear();
    for (int u = time = cc = 0; u < g.size(); u++)
      if (!~dfn[u]) dfs(g, u);
  }
};

struct slca_t {
  graph_t q;
  vector<int> r, f, c, d;
  void init(int n) {
    q.init(n), f.resize(n), c.resize(n);
    for (int i = 0; i < n; i++)
      f[i] = i, c[i] = 0;
  }
  void add(int u, int v) {
    r.push_back(-1);
    q.badd(u, v);
  }
  int find(int x) {
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
  }
  void go(graph_t &g, int u, int p = -1) {
    for (int e = g(u); ~e; e = g[e].to) {
      if (e == p) continue;
      go(g, g[e].v, e^1);
      f[find(g[e].v)] = u;
    }
    c[u] = 1;
    for (int e = q(u); ~e; e = q[e].to) {
      if (!c[q[e].v]) continue;
      r[e>>1] = find(q[e].v);
    }
  }
};

struct dfs_t {
  int d[N];
  void go(graph_t &g, int u, int p = -1, int dep = 0) {
    d[u] = dep;
    for (int e = g(u); ~e; e = g[e].to) {
      if (e == p) continue;
      go(g, g[e].v, e^1, dep+1);
    }
  }
};

slca_t slca;
bcc_t bcc;
graph_t g, f;
dfs_t dfs;
int n, m, q, id[M];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m), n|m; ) {
    g.init(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      id[i] = g.e.size();
      g.badd(u-1, v-1);
    }
    bcc(g);
    for (int i = 0; i < m; i++) id[i] = n+bcc.in[id[i]];
#if 0
    printf("cc=%2d\n", bcc.cc);
    for (int i = 0; i < n; i++)
      printf("\t%2d: cut=%2d, dfn=%2d, low=%2d\n",
          i+1, bcc.cut[i], bcc.dfn[i], bcc.low[i]);
    for (int i = 0; i < m; i++)
      printf("\t%2d in %2d\n", i+1, id[i]);
#endif
    f.init(n+bcc.cc);
    for (int u = 0; u < n; u++) {
      if (!bcc.cut[u]) continue;
      mii_t added;
      for (int e = g(u); ~e; e = g[e].to)
        if (!added.count(bcc.in[e])) {
          added[bcc.in[e]] = 1;
          f.badd(u, n+bcc.in[e]);
        }
    }
    slca.init(n+bcc.cc);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      slca.add(id[x-1], id[y-1]);
    }
    slca.go(f, n);
    dfs.go(f, n);
    for (int i = 0; i < q; i++) {
      int u = slca.q[i<<1].v, v = slca.q[i<<1|1].v, lca = slca.r[i];
      printf("%d\n", (dfs.d[u]+dfs.d[v]-2*dfs.d[lca])>>1);
    }
  }
  return 0;
}
