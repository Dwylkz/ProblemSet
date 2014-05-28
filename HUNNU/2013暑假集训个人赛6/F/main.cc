#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e2+10;

struct jfs_t {
  int f[N];
  void init(int n) {
    for (int i = 0; i < n; i++) f[i] = i;
  }
  int find(int x) {
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
  }
  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    f[x] = y;
    return 1;
  }
};
struct edge_t {
  int u, v, w;
  void input() {
    scanf("%d%d%d", &u, &v, &w);
    u--, v--;
  }
  friend bool operator < (edge_t lhs, edge_t rhs) {
    return lhs.w < rhs.w;
  }
};

int n, m, k, w[N];
edge_t e[N];
jfs_t jfs;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) scanf("%d", w+i);
    for (int i = 0; i < m; i++) e[i].input();
    sort(e, e+m);
    int ans = w[0];
    for (int s = 1, bl = 1<<n; s < bl; s++) {
      if (~s&1) continue;
      int cost = 0, pop = w[0], ban[N] = {0};
      ban[0] = 1;
      jfs.init(n);
      for (int j = 0; j < m; j++)
        if (e[j].u != e[j].v && s&(1<<e[j].u) && s&(1<<e[j].v)) {
          if (jfs.join(e[j].u, e[j].v)) {
            if (!ban[e[j].u]) pop += w[e[j].u];
            ban[e[j].u] = 1;
            if (!ban[e[j].v]) pop += w[e[j].v];
            ban[e[j].v] = 1;
            cost += e[j].w;
          }
        }
#if 0
      printf("cost = %d pop = %d\n", cost, pop);
#endif
      if (cost <= k) ans = max(ans, pop);
    }
    printf("%d\n", ans);
  }
  return 0;
}
