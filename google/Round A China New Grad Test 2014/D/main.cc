#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e2+10;
const int M = N*N;
typedef pair<int, int> pii_t;
#define _x first
#define _y second

int n, sx, sy, ex, ey;
int to[][2] = {
  {0, 1},
  {1, 1},
  {1, 0},
  {1, -1},
  {0, -1},
  {-1, -1},
  {-1, 0},
  {-1, 1}
};
char dr[] = {'E', 'D', 'S', 'D', 'W', 'D', 'N', 'D'};
char m[N][N];

pii_t pre[N][N];
int dis[N][N];
bool b[N][N];
vector<pii_t> q(1, pii_t(sx, sy));
int bfs() {
  memset(b, 0, sizeof(b));
  q.clear();
  q.push_back(pii_t(sx, sy));
  pre[sx][sy] = pii_t(-1, -1);
  dis[sx][sy] = 0;
  b[sx][sy] = 1;
  for (int h = 0; h < q.size(); h++) {
    int x = q[h]._x, y = q[h]._y,
        d = x == sx && y == sy? 2: 1;
    if (x == ex && y == ey) return 1;
    for (int i = 0; i < 8; i += d) {
      int tx = x+to[i][0], ty = y+to[i][1];
      if (m[tx][ty] == '#') {
        if (i&1) tx = x+to[(i+1)%8][0], ty = y+to[(i+1)%8][1];
        else tx = x+to[(i+2)%8][0], ty = y+to[(i+2)%8][1];
        if (m[tx][ty] == '.' && !b[tx][ty]) {
          b[tx][ty] = 1;
          q.push_back(pii_t(tx, ty));
          pre[tx][ty] = pii_t(x, y);
          dis[tx][ty] = dis[x][y]+1;
        }
      }
    }
  }
  return 0;
}

string r;
void make(int x, int y) {
  if (x == sx && y == sy ) return ;
  int tx = pre[x][y]._x, ty = pre[x][y]._y;
  make(tx, ty);
  for (int i = 0; i < 8; i += 2)
    if (x-tx == to[i][0] && y-ty == to[i][1]) {
      r += dr[i];
      break;
    }
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int kas = 1; T--; kas++) {
    printf("Case #%d: ", kas);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%s", m[i]+1);
    for (int i = 0; i < n+2; i++) {
      m[0][i] = m[i][0] = m[n+1][i] = m[i][n+1] = '#';
      m[i][n+2] = 0;
    }
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    if (bfs()) {
      printf("%d\n", dis[ex][ey]);
      r = "";
      make(ex, ey);
      printf("%s\n", r.data());
    } else puts("Edison ran out of energy.");
  }
  return 0;
}
