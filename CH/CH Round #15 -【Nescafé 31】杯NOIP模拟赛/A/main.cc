#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3+10;

int n, m, g[N][N], dp[N][N][2];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    memset(g, 0, sizeof(g));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        scanf("%d", g[i]+j);
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = dp[0][0][1] = g[0][0];
    for (int i = 1; i < m; i++) {
      dp[0][i][0] = g[0][i]+dp[0][i-1][0]+g[1][i-1];
      dp[i][0][1] = g[i][0]+dp[i-1][0][1]+g[i-1][1];
    }
    for (int i = 1; i < n; i++)
      for (int j = 1; j < m; j++) {
        int *f = dp[i][j], *l = dp[i][j-1], *u = dp[i-1][j];
        f[0] = g[i][j]+min(l[0]+g[i+1][j-1]+g[i-1][j], l[1]+g[i+1][j-1]);
        f[1] = g[i][j]+min(u[1]+g[i-1][j+1]+g[i][j-1], u[0]+g[i-1][j+1]);
      }
    printf("%d\n", min(dp[n-1][m-1][0], dp[n-1][m-1][1]));
  }
  return 0;
}
