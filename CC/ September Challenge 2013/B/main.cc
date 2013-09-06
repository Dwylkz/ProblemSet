#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 5e2+10;

int n, m, f[N][N][4], p[N];
char g[N][N];

int isp(int x) {
  for (int i = sqrt(x); i >= 2; i--)
    if (x%i == 0) return 0;
  return 1;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  p[2] = 1;
  for (int i = 3; i < N; i++) p[i] = p[i-1]+isp(i);
#if 0
  for (int i = 0; i < 20; i++)
    printf("%d: %d\n", i, p[i]);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", g[i]);
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (g[i][j] == '^') {
          if (i && g[i-1][j] == '^') f[i][j][0] = f[i-1][j][0]+1;
          if (j && g[i][j-1] == '^') f[i][j][1] = f[i][j-1][1]+1;
        }
        int ri = n-1-i, rj = m-j-1;
        if (g[ri][rj] == '^') {
          if (ri < n-1 && g[ri+1][rj] == '^') f[ri][rj][2] = f[ri+1][rj][2]+1;
          if (rj < m-1 && g[ri][rj+1] == '^') f[ri][rj][3] = f[ri][rj+1][3]+1;
        }
      }
#if 0
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
//         if (g[i][j] == '^')
//           printf("in %d %d: %d %d %d %d\n", i, j,
//               f[i][j][0], f[i][j][1], f[i][j][2], f[i][j][3]);
        printf("%d", f[i][j][3]);
//         printf("%c", g[i][j]);
      }
      puts("");
    }
#endif
    int rv = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (g[i][j] == '^'){
          int cpc = N;
          for (int k = 0; k < 4; k++) cpc = min(cpc, f[i][j][k]);
          rv += p[cpc];
        }
    printf("%d\n", rv);
  }
  return 0;
}
