#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3+10;
const int K = 20+10;
const int inf = 0x7fffffff;

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
int f[N][K][2], tmp[K][2], ra[N], sz[N];
void dfs(int u) {
  int (*g)[2] = f[u];
  sz[u] = 1;
  for (int i = 0; i <= k; i++) g[i][0] = g[i][1] = -inf;
  g[0][1] = w[u];
  for (int i = L[u]; ~i; i = E[i].to) {
    int v = E[i].v;
    if (ra[u] == i) continue;
    ra[v] = i^1;
    dfs(v);
    int (*h)[2] = f[v];
    for (int j = 0; j <= k; j++) tmp[j][0] = tmp[j][1] = -inf;
    for (int a = sz[u]-1; a >= 0; a--)
      for (int b = sz[v]-1; b >= 0; b--) {
        // cut undirectly
        if (a+b <= k) {
          tmp[a+b][1] = max(tmp[a+b][1], g[a][1]+h[b][1]);
          tmp[a+b][0] = max(tmp[a+b][0], h[b][0]);
        }
        // cut directly
        if (a+b+1 <= k) {
          tmp[a+b+1][1] = max(tmp[a+b+1][1], g[a][1]);
          tmp[a+b+1][0] = max(tmp[a+b+1][0], g[a][0]);
          tmp[a+b+1][0] = max(tmp[a+b+1][0], h[b][1]);
          tmp[a+b+1][0] = max(tmp[a+b+1][0], h[b][0]);
        }
      }
    sz[u] += sz[v];
    for (int j = 0; j <= k; j++) {
      g[j][0] = max(g[j][0], tmp[j][0]);
      g[j][1] = tmp[j][1];
    }
  }
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &k); ) {
    for (int i = 0; i < n; i++) scanf("%d", w+i);
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
    printf("%d %d\n", mn, mx);
  }
  return 0;
}
