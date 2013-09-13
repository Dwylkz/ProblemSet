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

namespace seg {
  struct node {
    int l, r, mx;
    node *ls, *rs;
    int m() {
      return l+r>>1;
    }
  } s[N<<1], *top;
  struct seg_t {
    void make(int l, int r, node *x = 0) {
      node t = {l, r, 0};
      *x = t;
      if (l == r) return ;
      make(l, x->m(), x->ls = top++);
      make(x->m()+1, r, x->rs = top++);
    }
    void put(int k, int mx, node *x) {
      if (x->l == x->r) {
        x->mx = mx; 
        return ;
      }
      int m = x->m();
      if (k <= m) put(k, mx, x->ls);
      else put(k, mx, x->rs);
      x->mx = max(x->ls->mx, x->rs->mx);
    }
    int ask(int l, int r, node *x) {
      if (l <= x->l && x->r <= r) return x->mx;
      int rv = 0, m = x->m();
      if (l <= m) rv = max(rv, ask(l, r, x->ls));
      if (m < r) rv = max(rv, ask(l, r, x->rs));
      return rv;
    }
  };
}

struct hld_t {
  typedef int ai_t[N];
  int n;
  ai_t d, sz, fa, hv, in, cl, id, w, q;
  void operator () (vector<edge_t> &E, int *L, int V, int u) {
    vector<int> q(1, u);
    n = V;
    d[u] = 0;
    fa[u] = -1;
    w[u] = -1;
    for (int h = 0; h < q.size(); h++) {
      u = q[h];
      for (int e = L[u]; ~e; e = E[e].to) {
        int v = E[e].v;
        if (v == fa[u]) continue;
        fa[v] = u;
        d[v] = d[u]+1;
        w[v] = E[e].w;
        q.push_back(v);
      }
    }
    for (int h = q.size()-1; ~h; h--) {
      u = q[h];
      sz[u] = 1;
      hv[u] = -1;
      for (int e = L[u]; ~e; e = E[e].to) {
        int v = E[e].v;
        if (v == fa[u]) continue;
        if (!~hv[u] || sz[v] > sz[hv[u]]) hv[u] = v;
        sz[u] += sz[v];
      }
    }
    q.resize(1);
    in[q[0]] = q[0];
    id[q[0]] = 0;
    cl[q[0]] = 1;
    for (int h = 0; h < q.size(); h++) {
      u = q[h];
      for (int e = L[u]; ~e; e = E[e].to) {
        int v = E[e].v;
        if (v == fa[u]) continue;
        if (v == hv[u]) {
          in[v] = in[u];
          id[v] = id[u]+1;
          cl[in[v]]++;
        } else {
          in[v] = v;
          cl[v] = 1;
          id[v] = 0;
        }
        q.push_back(v);
      }
    }
  }
  seg::node *rt[N];
  seg::seg_t zkl;
  void make() {
    seg::top = seg::s;
    for (int i = 0; i < n; i++)
      if (in[i] == i) zkl.make(0, cl[i]-1, rt[i] = seg::top++);
    for (int i = 0; i < n; i++) if (in[i] != i) rt[i] = rt[in[i]];
    for (int i = 0; i < n; i++) zkl.put(id[i], w[i], rt[i]);
  }
  void put(int e, int mx) {
    e <<= 1;
    int v = E[e^1].v;
    if (fa[E[e].v] == E[e^1].v) v = E[e].v;
    zkl.put(id[v], mx, rt[v]);
  }
  int ask(int u, int v) {
    if (u == v) return 0;
    int rv = 0;
    for ( ; in[u]^in[v]; u = fa[in[u]]) {
      if (d[in[u]] < d[in[v]]) swap(u, v);
      rv = max(rv, zkl.ask(0, id[u], rt[u]));
    }
    if (id[u] > id[v]) swap(u, v);
    rv = max(rv, zkl.ask(id[u]+1, id[v], rt[u]));
    return rv;
  }
} hld;

int n;

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
    hld(E, L, n, 0);
    hld.make();
    for (char op[10]; scanf("%s", op), *op^'D'; ) {
      int x, y;
      scanf("%d%d", &x, &y);
      if (*op^'Q') hld.put(x-1, y);
      else printf("%d\n", hld.ask(x-1, y-1));
    }
  }
  return 0;
}
