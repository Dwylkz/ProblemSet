#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
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

struct trie_t {
  struct node {
    node *s[2];
    int c[2];
  } s[17*N*2], *top, *nil;
  void init() {
    top = s;
    nil = phi();
  }
  node *make() {
    memset(top, 0, sizeof(node));
    return top++;
  }
  node *phi(int i = 15) {
    node *x = make();
    if (i) {
      x->s[0] = phi(i-1);
      x->s[1] = phi(i-1);
    }
    return x;
  }
  node *put(node *y, int k, int i = 15) {
    node *x = make();
    *x = *y;
    x->c[k>>i&1]++;
    if (i) x->s[k>>i&1] = put(y->s[k>>i&1], k, i-1);
    return x;
  }
  int ask(node *x, node *y, int k, int i = 15) {
    int rv = 0, id = k>>i&1, to = !id;
    if (x->c[!id]-y->c[!id]) rv |= 1<<i;
    else to = id;
    if (i) rv += ask(x->s[to], y->s[to], k, i-1);
    return rv;
  }
};

template<int N> struct hld_t {
  typedef int ai_t[N];
  int n;
  ai_t d, sz, fa, hv, in, cl, id;
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
  trie_t::node *rt[N];
  trie_t zkl;
  void make(int *w) {
    zkl.init();
    for (int i = 0; i < n; i++) rt[i] = 0;
    for (int i = 0; i < n; i++)
      if (!rt[i] && !~hv[i]) {
        rt[i] = zkl.put(zkl.nil, w[i]);
        for (int u = i; ~fa[u] && in[fa[u]] == in[u]; u = fa[u])
          rt[fa[u]] = zkl.put(rt[u], w[fa[u]]);
      }
  }
  int ask(int u, int v, int w) {
    int rv = 0;
    for ( ; in[u]^in[v]; u = fa[in[u]]) {
      if (d[in[u]] < d[in[v]]) swap(u, v);
      rv = max(rv, zkl.ask(rt[in[u]], zkl.nil, w));
    }
    if (id[u] > id[v]) swap(u, v);
    rv = max(rv, zkl.ask(rt[u], (~hv[v]? rt[hv[v]]: zkl.nil), w));
    return rv;
  }
};

hld_t<N> hld;
int n, m, w[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    init();
    for (int i = 0; i < n; i++) scanf("%d", w+i);
    for (int i = 0; i < n-1; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      add(u, v), add(v, u);
    }
    hld(E, L, n, 0);
    hld.make(w);
    for ( ; m--; ) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      u--, v--;
      printf("%d\n", w>>16<<16|hld.ask(u, v, w));
    }
  }
  return 0;
}
