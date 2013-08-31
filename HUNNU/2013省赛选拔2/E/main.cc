#include <cstdio>
#include <bitset>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef bitset<35+10> bs_t;
const int N = 17+10;
const int M = 7*500+10;
const int inf = 0x7f7f7f7f;

int g[N][N], id[N][N], f[N], e[N], od[N];
bs_t zkl[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int n; ~scanf("%d", &n), n; ) {
    int r = 0;
    memset(g, 0, sizeof(g));
    for (int i = 0; i < n; i++) {
      char op[10];
      scanf("%s%d", op, od+i);
      e[i] = od[i];
      int u = *op-'A';
      for (int k = 0; k < od[i]; k++) {
        scanf("%s", op);
        scanf("%d", g[u]+*op-'A');
        id[u][*op-'A'] = r++;
      }
    }
    vector<int> q(1, n-1);
    for (int h = 0; h < q.size(); h++) {
      int u = q[h], ec = 0, ei = -1, lc = inf;
      zkl[u].reset();
      f[u] = inf;
      for (int v = 0; v < n; v++)
        if (g[u][v]) f[u] = min(f[u], f[v]+g[u][v]);
      for (int v = 0; v < n; v++)
        if (g[u][v] && f[u] == f[v]+g[u][v]) {
          ec++;
          zkl[u] |= zkl[v];
          if (lc > zkl[v].count()) {
            lc = zkl[v].count();
            ei = v;
          }
        }
      if (ec == e[u] && zkl[u].count() <= zkl[ei].count()+1) {
      } else {
        zkl[u].reset();
        zkl[u][id[u][ei]] = 1;
        zkl[u] |= zkl[ei];
      }
      for (int v = 0; v < n; v++)
        if (g[v][u] && !--od[v]) q.push_back(v);
      if (u == n-1) f[u] = 0;
    }
    printf("%d %d\n", f[0], (int)zkl[0].count());
  }
  return 0;
}
