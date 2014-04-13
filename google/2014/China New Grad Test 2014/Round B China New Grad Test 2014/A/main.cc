#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 6*6*6*6+10;

int n, g[N][N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int kas = 1; kas <= T; kas++) {
    printf("Case #%d:", kas);
    scanf("%d", &n);
    for (int i = 0; i < n*n; i++)
      for (int j = 0; j < n*n; j++) {
        scanf("%d", g[i]+j);
        g[i][j]--;
      }
    int yes = 1;
    for (int i = 0; i < n*n; i++) {
      int r[N] = {0}, c[N] = {0};
      for (int j = 0; j < n*n; j++)
        r[g[i][j]]++, c[g[j][i]]++;
      for (int j = 0; j < n*n; j++)
        if (r[j] != 1 || c[j] != 1) yes = 0;
    }
    for (int i = 0; i < n*n; i += n)
      for (int j = 0; j < n*n; j += n) {
        int b[N] = {0};
        for (int x = i; x < i+n; x++)
          for (int y = j; y < j+n; y++)
            b[g[x][y]]++;
        for (int k = 0; k < n*n; k++)
          if (b[k] != 1) yes = 0;
      }
    puts(yes? " Yes": " No");
  }
  return 0;
}
