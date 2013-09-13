#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> pii_t;
typedef map<pii_t, int> mpi_t;
const int N = 1e5+10;

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

struct seg_t {
  struct node {
    int l, r, sm;
    node *ls, *rs;
    int m() {
      return l+r>>1;
    }
  } s[N<<2], *top;
  void make(int l, int r, node *x) {
    node t = {l, r, 0};
    *x = t;
    if (l == r) return ;
    make(l, x->m(), x->ls = top++);
    make(x->m()+1, r, x->rs = top++);
  }
  void put(int k, int c, node *x) {
    if (x->l == x->r) x->sm = c;
    else {
      if (k <= x->m()) put(k, c, x->ls);
      else put(k, c, x->rs);
      x->sm = x->ls->sm+x->rs->sm;
    }
  }
  int ask(int l, int r, node *x) {
    if (!x->sm) return -1;
    if (x->l == x->r) return x->l;
    if (l <= x->m() && x->ls->sm) return ask(l, r, x->ls);
    if (x->m() < r) return ask(l, r, x->rs);
    return -1;
  }
} seg;

struct hld_t {
  typedef int ai_t[N];
  int n;
  ai_t d, sz, fa, hv, in, cl, id, q, w;
  mpi_t m;
  void operator () (vector<edge_t> &E, int *L, int V, int u) {
    vector<int> q(1, u);
    n = V;
    d[u] = 0;
    fa[u] = -1;
    for (int h = 0; h < q.size(); h++) {
      u = q[h];
      for (int e = L[u]; ~e; e = E[e].to) {
        int v = E[e].v;
        if (v == fa[u]) continue;
        fa[v] = u;
        d[v] = d[u]+1;
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
    m.clear();
    q.resize(1);
    m[pii_t(q[0], q[0])] = q[0];
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
        m[pii_t(in[v], id[v])] = v;
        q.push_back(v);
      }
    }
  }
  seg_t::node *rt[N];
  void make() {
    seg.top = seg.s;
    for (int i = 0; i < n; i++)
      if (in[i] == i) seg.make(0, cl[i]-1, rt[i] = seg.top++);
    for (int i = 0; i < n; i++) {
      if (in[i] != i) rt[i] = rt[in[i]];
      w[i] = 0;
    }
  }
  void put(int x) {
    w[x] ^= 1;
    seg.put(id[x], w[x], rt[x]);
  }
  int ask(int x) {
    int rv = -1;
    for (int u = x; ~u; u = fa[in[u]]) {
      int t = seg.ask(0, id[u], rt[u]);
      if (!~t) continue;
      rv = m.find(pii_t(in[u], t))->second;
    }
    return ~rv? rv+1: -1;
  }
} hld;

int n, q;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  scanf("%d%d", &n, &q);
  init();
  for (int i = 0; i < n-1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    add(u, v);
    add(v, u);
  }
  hld(E, L, n, 0);
  hld.make();
  for ( ; q--; ) {
    int op, x;
    scanf("%d%d", &op, &x);
    x--;
    if (!op) hld.put(x);
    else printf("%d\n", hld.ask(x));
  }
  return 0;
}
