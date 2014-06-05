#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int N = 2e4+10;
const int M = 1e5+10;
typedef map<short, bool> mib_t;

// 4*N+M*2*2*10
struct edge_t {
  short v;
  int to, id;
};
vector<edge_t> E;
int L[N];
void init() {
  E.clear();
  memset(L, -1, sizeof(L));
}
void add(int u, int v, int id) {
  edge_t t = {v, L[u], id};
  L[u] = E.size();
  E.push_back(t);
}
void badd(int u, int v, int id) {
  add(u, v, id);
  add(v, u, id);
}

/* Doubling LCA
 * */
// (2+2*15)*N
template<class edge_t, int N> struct lca_t {
  static const int M = 15;
  short d[N], a[N][M];
  void operator () (vector<edge_t> &E, int *L, int u) {
    vector<int> q(1, u);
    memset(a, -1, sizeof(a));
    for (int h = d[u] = 0; h < q.size(); h++) {
      u = q[h];
      for (int i = 1; i < M; i++)
        if (~a[u][i-1]) a[u][i] = a[a[u][i-1]][i-1];
      for (int e = L[u]; ~e; e = E[e].to) {
        int v = E[e].v;
        if (~E[e].id || v == a[u][0]) continue;
        d[v] = d[u]+1;
        a[v][0] = u;
        q.push_back(v);
      }
    }
  }
  int getp(int x) {
    int result = 0;
    for ( ; x; ) x >>= 1;
    return result;
  }
  int skip(int u, int x) {
    for ( ; x; x -= -x&x) u = a[u][getp(-x&x)];
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
};
typedef lca_t<edge_t, N> lca_i;

// 2*M
lca_i lca;
int n, m, q;
short in[M];

// 3*N+4*M
struct tarjan_t {
  typedef short ia_t[N>>1];
  int time, v, top, cc, branch, rt;
  ia_t in, out;
  bool cut[N>>1];
  vector<int> st;
  void operator () (int _rt, int n) {
    rt = _rt;
    branch = 0;
    time = 0;
    cc = n;
    for (int i = 0; i < n; i++) {
      cut[i] = 0;
      in[i] = out[i] = -1;
    }
    st.clear();
    go(rt);
  }
  void go(int u, int p = -1) {
    in[u] = out[u] = time++;
    for (int e = L[u]; ~e; e = E[e].to) {
      if (e == p) continue;
      v = E[e].v;
      if (in[v] > in[u]) continue;
      st.push_back(e);
      if (~in[v]) {
        out[u] = min(out[u], in[v]);
      } else {
        go(v, e^1);
        out[u] = min(out[u], out[v]);
        if (in[u] <= out[v]) {
          if (u == rt) {
            if (branch > 1) cut[u] = 1;
          } else cut[u] = 1;
          for ( ; ; ) {
            top = st.back();
            ::in[E[top].id] = cc;
            st.pop_back();
            if (top == e || !st.back()) break;
          }
          cc++;
        }
      }
    }
  }
};
tarjan_t zkl;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m), n|m; ) {
    init();
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      badd(u-1, v-1, i);
    }
    zkl(0, n);
    for (int u = 0; u < n; u++) if (zkl.cut[u]) {
      mib_t visit;
      for (int e = L[u]; ~e; e = E[e].to)
        if (!visit.count(in[E[e].id])) {
          badd(u, in[E[e].id], -1);
          visit[in[E[e].id]] = 1;
        }
    }
    lca(E, L, n);
#if 0
    printf("cc=%d\n", zkl.cc-n);
    for (int i = 0; i < n; i++)
      printf("%2d: in=%2d, out=%2d, cut=%2d\n",
          i, zkl.in[i], zkl.out[i], zkl.cut[i]);
    for (int i = 0; i < m; i++)
      printf("%2d in %2d\n", i, in[i]);
#endif
    scanf("%d", &q);
    for ( ; q--; ) {
      int u, v;
      scanf("%d%d", &u, &v);
      u = in[u-1];
      v = in[v-1];
      if (u == v) puts("0");
      else {
        int w = lca(u, v);
        printf("%d\n", lca.d[u]+lca.d[v]-lca.d[w]>>1);
      }
    }
  }
  return 0;
}
