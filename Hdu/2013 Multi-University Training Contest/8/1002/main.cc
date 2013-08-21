#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 3e4+10;
const int B = 181;

namespace graph {
  struct edge_t {
    int v, to;
  };
  vector<edge_t> E;
  int L[N];
  void init(int n) {
    E.clear();
    memset(L, -1, sizeof(int)*n);
  }
  void add(int u, int v) {
    edge_t t = {v, L[u]};
    L[u] = E.size();
    E.push_back(t);
  }
}
using namespace graph;
struct jfs_t {
  int f[N];
  void init(int l, int r) {
    for (int i = l; i < r; i++) f[i] = i;
  }
  int find(int u) {
    if (f[u] != u) f[u] = find(f[u]);
    return f[u];
  }
  bool join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
      f[u] = v;
      return 1;
    }
    return 0;
  }
};
struct ask_t {
  int r, i;
};

/* Block i's range is [ lb[i], rb[i] ).
 * Scc[j] store "current" connected component amount
 * from i to block j(included), ie. figure 1.
 * 
 *   current vertice    block j
 *           |             |
 *           |             |
 *           V             V
 * ... | ... i... | ... | ... | ... 
 *           |                |
 *           |  this interval |
 *           |  's connected  |
 *           |  component     |
 *           |  amount is     |
 *           |  scc[j]        |
 *
 *           figure 1
 *
 */
int n, m, ans[N], lb[B], rb[B], scc[B];
/* Ans[l] store query which left end is l. */
vector<ask_t> ask[N];
/* Maintain s[i] as to maintain scc[i]. */
jfs_t s[B], zkl;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int i = 0; i < B; i++) rb[i] = (lb[i] = i*B)+B;
  int T;
  scanf("%d", &T);
  for (int ks = 1; ks <= T; ks++) {
    printf("Case #%d:\n", ks);
    scanf("%d%d", &n, &m);
    init(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      add(--u, --v);
      add(v, u);
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < n; i++) ask[i].clear();
    for (int i = 0; i < q; i++) {
      int l, r;
      scanf("%d%d", &l, &r);
      ask[--l].push_back((ask_t){r, i});
    }
    int bl = n/B+(n%B > 0);
    for (int i = 0; i < bl; i++) {
      s[i].init(0, n);
      scc[i] = 0;
    }
    for (int i = n-1; i >= 0; i--) {
      // deal with i
      for (int j = i/B; j < bl; j++) {
        scc[j]++;
        for (int k = L[i]; ~k; k = E[k].to) {
          int v = E[k].v;
          if (i < v && v < rb[j]) scc[j] -= s[j].join(i, v);
        }
      }
      // deal with all queries [i, r)
      for (int j = 0; j < ask[i].size(); j++) {
        int b = (ask[i][j].r-1)/B, dec = 0;
        int l = max(lb[b], i+1), r = ask[i][j].r;
        zkl.init(0, n);
        for (int u = l; u < r; u++) {
          for (int k = L[u]; ~k; k = E[k].to) {
            int v = E[k].v;
            if (i <= v && v < r)
              dec += zkl.join(u, (b != i/B? s[b-1].find(v): v));
          }
        }
        ans[ask[i][j].i] = r-max(lb[b], i)-dec;
        if (b != i/B) ans[ask[i][j].i] += scc[b-1];
      }
    }
    for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
  }
  return 0;
}
