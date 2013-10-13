#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e2+10;
const int inf = 1e8+10;


int n, m, sx, sy, ex, ey, g[N][N];

const int to[4][2] = {
  {0, 1},
  {1, 0},
  {0, -1},
  {-1, 0}
};

int reach[N][N];
void flood(int x, int y) {
  reach[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int tx = x+to[i][0], ty = y+to[i][1];
    if (~g[tx][ty] && !reach[tx][ty]) flood(tx, ty);
  }
}

struct dp_t {
  int d, v;
  dp_t(int _d = inf, int _v = 0): d(_d), v(_v) {}
  friend bool operator < (const dp_t &lhs, const dp_t &rhs) {
    return lhs.d == rhs.d? lhs.v > rhs.v: lhs.d < rhs.d;
  }
};

dp_t dp[N][N];
dp_t dfs(int x, int y) {
  if (x == ex && y == ey) return dp[x][y] = dp_t(0, g[x][y]);
  if (~dp[x][y].d) return dp[x][y];
  dp_t mx;
  int temp = g[x][y];
  g[x][y] = -1;
  for (int i = 0; i < 4; i++) {
    int tx = x+to[i][0], ty = y+to[i][1];
    if (~g[tx][ty]) {
      dp_t result = dfs(tx, ty);
      result = dp_t(result.d+1, result.v+temp);
      mx = min(mx, result);
    }
  }
  g[x][y] = temp;
  return dp[x][y] = mx;
}

int dis[N][N], val[N][N], in[N][N];
int spfa(int x, int y) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      dis[i][j] = inf, val[i][j] = 0, in[i][j] = 0;
  vector<int> qx(1, x), qy(1, y);
  dis[x][y] = 0;
  val[x][y] = g[x][y];
  in[x][y] = 1;
  for (int h = 0; h < qx.size(); h++) {
    x = qx[h], y = qy[h];
    in[x][y] = 0;
    for (int i = 0; i < 4; i++) {
      int tx = x+to[i][0], ty = y+to[i][1];
      if (!~g[tx][ty]) continue;
      if (dis[tx][ty] == dis[x][y]+1 && val[tx][ty] < val[x][y]+g[tx][ty]
          || dis[tx][ty] > dis[x][y]+1) {
        dis[tx][ty] = dis[x][y]+1;
        val[tx][ty] = val[x][y]+g[tx][ty];
        if (!in[tx][ty]) {
          qx.push_back(tx);
          qy.push_back(ty);
          in[tx][ty] = 1;
        }
      }
    }
  }
  return val[ex][ey];
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int kas = 1 ; kas <= T; kas++) {
    printf("Case #%d: ", kas);
    scanf("%d%d%d%d%d%d", &n, &m, &sx, &sy, &ex, &ey);
    sx++, sy++, ex++, ey++;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        scanf("%d", g[i]+j);
    for (int i = 1; i <= m; i++)
      g[0][i] = g[n+1][i] = -1;
    for (int i = 1; i <= n; i++)
      g[i][0] = g[i][m+1] = -1;
    memset(reach, 0, sizeof(reach));
    flood(sx, sy);
    if (!reach[ex][ey]) {
      puts("Mission Impossible.");
      continue;
    }
    printf("%d\n", spfa(sx, sy));
//     memset(dp, -1, sizeof(dp));
//     printf("%d\n", dfs(sx, sy).v);
#if 0
    puts("");
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++)
        printf(" %2d", g[i][j]);
      puts("");
    }
    puts("");
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++)
        printf(" %11d", dp[i][j].v);
      puts("");
    }
#endif
  }
  return 0;
}
