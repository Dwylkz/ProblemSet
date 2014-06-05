#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N  =1e5+10;

int n, f[N][5][2];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", &f[j][i][0]);
        f[j][i][1] = f[j][i][0];
      }
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        int tmp = -0x7fffffff;
        for (int k = 0; k < j; k++) {
          tmp = max(tmp, f[i][j][0]+f[i-1][k][1]);
        }
        f[i][j][0] = tmp;
        tmp = -0x7fffffff;
        for (int k = j+1; k < 5; k++) {
          tmp = max(tmp, f[i][j][1]+f[i-1][k][0]);
        }
        f[i][j][1] = tmp;
      }
    }
    int ans = -0x7fffffff;
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 2; j++)
        ans = max(ans, f[n-1][i][j]);
    printf("%d\n", ans);
  }
  return 0;
}
