#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e2+10;

int n, b[N][N];

int to[6][2] = {
  {0, 1},
  {1, 0},
  {1, -1},
  {-1, 0},
  {0, -1},
  {1, -1}
};

int count, color, visit[N][N], connected;
void flood (int x, int y) {
  visit[x][y] = 0;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int kas = 1; kas <= T; kas++) {
    printf("Case #%d: ", kas);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        char op[2];
        scanf("%1s", op);
        b[i][j] = *op;
      }
    }
    for (int i = 0; i <= n+1; i++)
      b[0][i] = b[n+1][i] = b[i][0] = b[i][n+1] = -1;
    int cntR = 0, cntB = 0;
    // deal R
    count = 0, color = 'R';
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (b[i][j] == color && !visit[i][j])
          flood(i, j);
    cntR = count;
    // deal B
    count = 0, color = 'B';
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (b[i][j] == color && !visit[i][j])
          flood(i, j);
    cntB = count;
  }
  return 0;
}
