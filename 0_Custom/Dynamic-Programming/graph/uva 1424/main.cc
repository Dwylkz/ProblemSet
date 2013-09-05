#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2e2+10;
const int inf = 0x3f3f3f3f;

int n, m, g[N][N], l, s[N], f[N][N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d%d", &n, &m);
    memset(g, 0, sizeof(g));
    for (int i = 0, u, v; i < m; i++) {
      scanf("%d%d", &u, &v);
      u--, v--;
      g[u][v] = g[v][u] = 1;
    }
    for (int i = 0; i < n; i++) g[i][i] = 1;
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
      scanf("%d", s+i);
      s[i]--;
    }
    for (int i = 0; i < n; i++) f[0][i] = (s[0] != i);
    for (int i = 1; i < l; i++)
      for (int j = 0; j < n; j++) {
        f[i][j] = inf;
        for (int k = 0; k < n; k++)
          if (g[k][j]) f[i][j] = min(f[i][j], f[i-1][k]+(s[i] != j));
      }
    int mn = inf;
    for (int i = 0; i < n; i++) mn = min(mn, f[l-1][i]);
    printf("%d\n", mn);
  }
  return 0;
}
