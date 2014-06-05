#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5e2+10;

int n, m, k;
char g[N][N];
bool use[N][N];

int cnt, to[] = {0, 1, 1, 0, 0, -1, -1, 0};
void dfs(int x, int y) {
  if (x < 0 || x >= n ||
      y < 0 || y >= m ||
      g[x][y] == '#' ||
      use[x][y] ||
      !cnt) return ;
  cnt--;
  use[x][y] = 1;
  for (int i = 0 ; i < 4; i++)
    dfs(x+to[i<<1], y+to[i<<1|1]);
}

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d", &n, &m, &k); ) {
    int s = 0;
    for (int i = 0 ; i < n; i++) {
      scanf("%s", g[i]);
      s += count(g[i], g[i]+m, '.');
    }
    for (int i = 0; i < n*m; i++)
      if (g[i/m][i%m] == '.') {
        cnt = s-k;
        memset(use, 0, sizeof(use));
        dfs(i/m, i%m);
        break;
      }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        if (g[i][j] == '.') putchar(use[i][j]? '.': 'X');
        else putchar('#');
      puts("");
    }
  }
  return 0;
}
