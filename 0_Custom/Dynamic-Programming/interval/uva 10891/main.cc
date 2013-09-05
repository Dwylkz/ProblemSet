#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e2+10;
const int inf = 0x3f3f3f3f;

int n, f[N][N][2], g[N][N][2], v[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n), n; ) {
    for (int i = 0; i < n; i++) scanf("%d", v+i);
    for (int i = 0; i < n; i++) {
      f[i][i][0] = v[i];
      f[i][i][1] = 0;
    }
    for (int l = n-2; l >= 0; l--) {
      for (int r = l+1; r < n; r++) {
        int *g = f[l][r];
        f[l][r][0] = f[l][r][1] = -inf;
        for (int d = -inf, ls = 0, rs = 0, i = 1; i <= r-l+1; i++) {
          ls += v[l+i-1], rs += v[r-i+1];
          if (i < r-l+1) {
            if (ls+f[l+i][r][1]-f[l+i][r][0] > d) {
              g[0] = ls+f[l+i][r][1];
              g[1] = f[l+i][r][0];
              d = g[0]-g[1];
            }
            if (f[l][r-i][1]+rs-f[l][r-i][0] > d) {
              g[0] = f[l][r-i][1]+rs;
              g[1] = f[l][r-i][0];
              d = g[0]-g[1];
            }
          } else {
            if (ls > d) {
              g[0] = ls;
              g[1] = 0;
              d = g[0]-g[1];
            }
            if (rs > d) {
              g[0] = rs;
              g[1] = 0;
              d = g[0]-g[1];
            }
          }
        } // subinterval
      } // left end
    } // length
    printf("%d\n", f[0][n-1][0]-f[0][n-1][1]);
  }
  return 0;
}
