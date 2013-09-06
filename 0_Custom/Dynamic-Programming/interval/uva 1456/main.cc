#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e2+10;
const int inf = 0x3f3f3f3f;

/* f[n][w][p]:  the minimum cost when among first n cell, there is w parts
 *              and the last part has p cell.
 * g[n][w]:     min{ f[n][w][p] | p in [1, n-(w-1)] }*/
int n, w, u[N], s[N], f[N][N][N], g[2][N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n; i++) scanf("%d", u+i);
    sort(u, u+n, greater<int>());
    for (int i = 0; i < n; i++) {
      s[i] = u[i];
      if (i) s[i] += s[i-1];
    }
    memset(f, 0x3f, sizeof(f));
    memset(g, 0x3f, sizeof(g));
    int t = 0;
    f[0][1][1] = g[0][1] = u[0];
    for (int i = 1; i < n; i++) {
      memset(g[!t], 0x3f, sizeof(g[!t]));
      for (int j = 1; j <= w; j++) {
        for (int k = 1; k <= i+1; k++) {
          int sm = s[i-1]-(i-k >= 0? s[i-k]: 0);
          f[i][j][k] = min(f[i-1][j][k-1]+sm, g[t][j-1]);
          f[i][j][k] += (i+1)*u[i];
          g[!t][j] = min(g[!t][j], f[i][j][k]);
        } // size of the last part
      } // number of parts
      t ^= 1;
    } // i-th cell
    int mn = inf;
    for (int i = 1; i <= w; i++)
      for (int j = 1; j <= n; j++)
        mn = min(mn, f[n-1][i][j]);
    printf("%.4f\n", 1.*mn/s[n-1]);
  }
  return 0;
}
