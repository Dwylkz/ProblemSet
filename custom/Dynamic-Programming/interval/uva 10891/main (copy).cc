#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e2+10;

/* f(l, r) = the max-score would get by player who would move first.
 * g(l, r) = min{f(l, i) | i in [l, r)}
 * h(l, r) = min{f(i, r) | i in (l, r]} */
int n, f[N][N], g[N][N], h[N][N], v[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#else
  freopen("e.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n), n; ) {
    for (int i = 0; i < n; i++) {
      scanf("%d", v+i);
      if (i) v[i] += v[i-1];
    }
    for (int i = 0; i < n; i++)
      f[i][i] = g[i][i] = h[i][i] = v[i]-(i? v[i-1]: 0);
    for (int l = n-2; l >= 0; l--) {
      for (int r = l+1; r < n; r++) {
        int sum = v[r]-(l? v[l-1]: 0);
        f[l][r] = sum-min(0, min(g[l][r-1], h[l+1][r]));
        g[l][r] = min(f[l][r], g[l][r-1]);
        h[l][r] = min(f[l][r], h[l+1][r]);
      } // left end
    } // length
    printf("%d\n", f[0][n-1]-(v[n-1]-f[0][n-1]));
  }
  return 0;
}
