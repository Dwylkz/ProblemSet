#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e2+10;
const int inf32 = 0x7fffffff;
typedef long long LL;

int r, c, m[N][N], bx, by;

bool vis[N][N];
const int mv[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int judge(int x, int y) {
  return 0 <= x && x < r && 0 <= y && y < c;
}
int d[N][N];
int dfs(int x, int y) {
  if (d[x][y] != -1) return d[x][y];
  if (!x || x == r-1 || !y || y == c-1) return d[x][y] = 0;
  int rv = 0x7fffffff;
  vis[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int tx = x+mv[i][0], ty = y+mv[i][1];
    if (!judge(tx, ty) || m[x][y] > m[tx][ty] || vis[tx][ty]) continue;
    rv = min(rv, max(dfs(tx, ty), m[tx][ty]-m[x][y]));
  }
  vis[x][y] = 0;
  return d[x][y] = rv;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int Case = 1; Case <= T; Case++) {
    scanf("%d%d%d%d", &r, &c, &bx, &by);
    bx--, by--;
    for (int i = 0; i < r; i++) 
      for (int j = 0; j < c; j++)
        scanf("%d", m[i]+j);
    memset(d, -1, sizeof(d));
    int rv = dfs(bx, by);
#if 0
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++)
        printf("%12d%c", d[i][j], j < c-1? ' ': '\n');
#endif
    printf("%d. ", Case);
    if (rv != inf32) printf("%d\n", rv);
    else puts("IMPOSSIBLE");
  }
  return 0;
}
