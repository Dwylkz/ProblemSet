#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e4+10;
const int K = 10+10;
const int inf = 0x7fffffff;

namespace graph {
  struct edge_t {
    int v, to, w;
  };
  vector<edge_t> E;
  int L[N];
  void init(int n) {
    E.clear();
    memset(L, -1, sizeof(int)*n);
  }
  void add(int u, int v, int w) {
    edge_t t = {v, L[u], w};
    L[u] = E.size();
    E.push_back(t);
  }
}
using namespace graph;

int n, s, k; 

/* dp[u][r][b] the min-cost when there is r robot start from u
 * and b robot return. */
int dp[N][K][K], h[K][K];
void dfs(int u, int p = -1) {
  int (*f)[K] = dp[u];
  memset(f, 0, sizeof(dp[0]));
  for (int e = L[u]; ~e; e = E[e].to) {
    if (e == p) continue;
    dfs(E[e].v, e^1);
    int (*g)[K] = dp[E[e].v];
    for (int r = 1; r <= k; r++)
      for (int b = 0; b <= r; b++)
        h[r][b] = inf;
    for (int r = 1; r <= k; r++) {
      for (int b = 0; b <= r; b++) {
        for (int i = 1; i <= r; i++) {
          for (int j = 1; j <= r; j++) {
            int x = max(0, j-(r-i)), y = max(0, b-j), w = E[e].w;
            // case 1: travel v after u
            h[r][b] = min(h[r][b], f[i][x+y]+g[j][b-y]+w*(j+b-y));
            // case 2: travel u after v
            x = max(0, i-(r-j)), y = max(0, b-i);
            h[r][b] = min(h[r][b], g[j][x+y]+w*(j+x+y)+f[i][b-y]);
          } // j as the number of robot send to v.
        } // i as the number of robot send to u.
      } // b as the number of robot which would return.
    } // r as the number of robot.
    for (int r = 1; r <= k; r++)
      for (int b = 0; b <= r; b++)
        f[r][b] = h[r][b];
  }
#if 0
  printf("in %d\n", u);
  for (int r = 1; r <= k; r++) {
    printf("use %4d: ", r);
    for (int b = 0; b <= r; b++)
      printf("%4d%c", dp[u][r][b], b < r? ' ': '\n');
  }
#endif
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d", &n, &s, &k); ) {
    init(n);
    for (int i = 0; i < n-1; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      add(--u, --v, w);
      add(v, u, w);
    }
    dfs(--s);
    printf("%d\n", dp[s][k][0]);
  }
  return 0;
}
