#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 200+10;

char c[N];
int n, m, mat[4][N][N], ans[N][N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d%d", &n, &m);
    swap(n, m);
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < m; k++)
          scanf("%1d", mat[i][j]+k);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        ans[i][j] = 0;
        if (0 < mat[0][i][j] && mat[0][i][j] < 8) {
          for (int k = 0; k < 3; k++)
            if (mat[0][i][j]&(1<<k)) ans[i][j] += mat[k+1][i][j];
        }
        ans[i][j] = min(9, ans[i][j]);
      }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        printf("%d", ans[i][j]);
      puts("");
    }
  }
  return 0;
}
