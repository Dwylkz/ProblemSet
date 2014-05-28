#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 200+10;

int n;
double l, r, s, f[2][N][N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    int c;
    scanf("%d", &c);
    printf("%d ", c);
    scanf("%d%lf%lf", &n, &l, &r);
    s = 1.-l-r;
    int t = 0;
    memset(f, 0., sizeof(f));
    f[0][n][n] = 1.0;
    int m = n<<1;
    for (int i = 1; i <= n; i++, t ^= 1) {
      memset(f[!t], 0., sizeof(f[!t]));
      for (int j = 0; j <= m; j++) {
        for (int k = 0; k <= j; k++)
          f[!t][j][j] += (j? f[t][j-1][k]: 0)*r+f[t][j][k]*s+(j < m? f[t][j+1][k]: 0)*l;
        for (int k = j+1; k <= m; k++)
          f[!t][j][k] = (j? f[t][j-1][k]: 0)*r+f[t][j][k]*s+(j < m? f[t][j+1][k]: 0)*l;
      }
    }
    double ex = 0.;
    for (int i = 0; i <= m; i++)
      for (int j = 0; j <= m; j++)
        ex += f[t][i][j]*(j-n);
    printf("%.4f\n", ex);
  }
  return 0;
}
