#pragma comment(linker, "/STACK:102400000")
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5+10;

struct graph_t {
  struct edge_t {
    int v, to;
  };
  vector<edge_t> e;
  vector<int> h;
  int size() {
    return h.size();
  }
  edge_t &operator [] (int x) {
    return e[x];
  }
  int &operator () (int x) {
    return h[x];
  }
  void init(int n) {
    e.clear();
    h.resize(n);
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

struct ftrie_t {
  static int const D = 16;
  struct node {
    node *s[2];
    int c[2];
  } s[D*N+D], *top, *phi;
  void init() {
    top = s;
    phi = top++;
    phi->c[0] = phi->c[1] = 0;
    phi->s[0] = phi->s[1] = phi;
  }
  node *put(int k, node *y, int d = D) {
    if (!d) return 0;
    node *x = top++;
    *x = *y;
    int i = k>>(d-1)&1;
    x->c[i]++;
    x->s[i] = put(k, y->s[i], d-1);
    return x;
  }
  int ask(int k, node *x, node *y, int d = D) {
    if (!d) return 0;
    int i = k>>(d-1)&1;
    if (x->c[!i]-y->c[!i])
      return (1<<d-1)+ask(k, x->s[!i], y->s[!i], d-1);
    return ask(k, x->s[i], y->s[i], d-1);
  }
};

struct hld_t {
  typedef int ia_t[N];
  ia_t d, sz, hb, fa, cl, in, id;
  void link(int h) {
    cl[h] = 1, in[h] = h, id[h] = 0;
    for (int v = h; ~hb[v]; )
      in[v = hb[v]] = h, id[v] = cl[h]++;
  }
  void go(graph_t &g, int u, int p = -1, int l = 0) {
    d[u] = l, sz[u] = 1, hb[u] = -1, fa[u] = p;
    for (int e = g(u); ~e; e = g[e].to) {
      int v = g[e].v;
      if (v == p) continue;
      go(g, v, u, l+1);
      sz[u] += sz[v];
      if (!~hb[u] || sz[hb[u]] < sz[v]) hb[u] = v;
    }
    for (int e = g(u); ~e; e = g[e].to)
      if (g[e].v != p && g[e].v != hb[u]) link(g[e].v);
    if (!~p) link(u);
  }
  ftrie_t zkl;
  ftrie_t::node *rt[N];
  void make(int *w, int n) {
    zkl.init();
    for (int u = 0; u < n; u++) {
      if (in[u] != u)  continue;
      rt[u] = zkl.put(w[u], zkl.phi);
      for (int v = hb[u]; ~v; v = hb[v])
        rt[v] = zkl.put(w[v], rt[fa[v]]);
    }
  }
  int ask(int u, int v, int w) {
    int result = 0;
    for ( ; in[u]^in[v]; u = fa[in[u]]) {
      if (d[in[u]] < d[in[v]]) swap(u, v);
      result = max(result, zkl.ask(w, rt[u], zkl.phi));
    }
    if (id[u] > id[v]) swap(u, v);
    if (in[u] == u) result = max(result, zkl.ask(w, rt[v], zkl.phi));
    else result = max(result, zkl.ask(w, rt[v], rt[fa[u]]));
    return result;
  }
};

hld_t hld;
graph_t g;
int n, m, w[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    g.init(n);
    for (int i = 0; i < n; i++) scanf("%d", w+i);
    for (int i = 0; i < n-1; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      g.badd(u-1, v-1);
    }
    hld.go(g, 0);
    hld.make(w, g.size());
    for ( ; m--; ) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      printf("%d\n", hld.ask(x-1, y-1, z));
    }
  }
  return 0;
}
