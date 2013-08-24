#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3+10;
const int K = 20+10;
const int inf = 1e6+10;

struct edge_t {
  int v, to;
};
vector<edge_t> E;
int L[N];
void ginit(int n) {
  E.clear();
  memset(L, -1, sizeof(int)*n);
}
void gadd(int u, int v) {
  edge_t e = {v, L[u]};
  L[u] = E.size();
  E.push_back(e);
}

int n, k, w[N];

/* f[i][j][k] means the biggest part in tree i, after cut j time.
 * k = 0/1 means that the biggest part is/isn's connected to node i.
 * */
int f[N][K][2], ra[N];
void dfs(int u) {
  int (*g)[2] = f[u];
  for (int i = 0; i <= k; i++) {
    g[i][0] = -inf;
    g[i][1] = -inf;
  }
  g[0][1] = w[u];
  for (int i = L[u]; ~i; i = E[i].to) {
    if (g[1][1] == -inf) g[1][1] = w[u];
    if (ra[u] == i) continue;
    ra[E[i].v] = i^1;
    dfs(E[i].v);
    int (*h)[2] = f[E[i].v];
    g[0][1] += h[0][1];
    for (int j = 1; j <= k; j++) {
      if (h[j][1] != -inf) g[j][1] += h[j][1];
      if (h[j][0] != -inf) g[j][0] = max(g[j][0], h[j][0]);
      else if (h[j][0] == -inf && j == 1) {
        g[j][0] = max(g[j][0], w[E[i].v]);
      }
      if (j) {
        g[j][0] = max(g[j][0], h[j-1][1]);
        g[j][0] = max(g[j][0], h[j-1][0]);
      }
    }
  }
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &k); ) {
    for (int i = 0; i < n; i++) {
      scanf("%d", w+i);
    }
    ginit(n);
    for (int i = 0; i < n-1; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      gadd(--u, --v);
      gadd(v, u);
    }
    memset(ra, -1, sizeof(int)*n);
    dfs(0);
    int mx = max(f[0][k][0], f[0][k][1]);
    for (int i = 0; i < n; i++) w[i] *= -1;
    dfs(0);
    int mn = -1*max(f[0][k][0], f[0][k][1]);
#if 1
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= k; j++) {
        printf("(%7d, %7d)", f[i][j][0], f[i][j][1]);
      }
      puts("");
    }
#endif
    printf("%d %d\n", mn, mx);
  }
  return 0;
}
