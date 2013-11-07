#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3+10;
const int mod = 1e9+7;

int c[N][N];
void init() {
  for (int i = 0; i <= N; i++) c[i][0] = c[0][i] = 1;
  for (int i = 1; i < N; i++)
    for (int j = 1; j < N; j++)
      c[i][j] = (c[i-1][j]+c[i][j-1])%mod;
}

int n, m, k;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  init();
  for ( ; ~scanf("%d%d%d", &n, &m, &k); ) {
    int result = 0;
    n++, m++;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (j+1 < m)
          result += (mod+c[n-1][m-1]-1ll*c[i][j+1]*c[n-1][m-(j+1)-1]%mod)%mod == k;
        if (i+1 < n)
          result += (mod+c[n-1][m-1]-1ll*c[i+1][j]*c[n-(i+1)-1][m-1]%mod)%mod == k;
      }
    n--, m--;
    printf("%d/%d\n", result, (n+1)*m+n*(m+1));
  }
  return 0;
}
