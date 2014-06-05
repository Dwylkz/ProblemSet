#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int N = 8+10;

const int to[][2] = {
  {2, 2},
  {2, -2},
  {-2, 2},
  {-2, -2}
};
int n, x[2], y[2], tag[2][N][N];
char buff[N][N];

void flood(int x, int y, int col, int step = 0) {
  tag[col][x][y] = step;
  for (int i = 0; i < 4; i++) {
    int tx = x+to[i][0], ty = y+to[i][1];
    if (0 <= tx && tx < 8 && 0 <= ty && ty < 8 && !~tag[col][tx][ty])
      flood(tx, ty, col, step+1);
  }
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
      scanf("%s", buff+i);
      for (int j = 0; j < 8; j++)
        if (buff[i][j] == 'K') {
          x[cnt] = i;
          y[cnt] = j;
          cnt++;
        }
    }
#if 0
    printf("%d,%d %d,%d\n", x[0], y[0], x[1], y[1]);
#endif
    memset(tag, -1, sizeof(tag));
    for (int i = 0; i < 2; i++)
      flood(x[i], y[i], i);
    int yes = 0;
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        if (buff[i][j] != '#'
            && ~tag[0][i][j] && ~tag[1][i][j]
            && (tag[0][i][j]&1) == (tag[1][i][j]&1))
          yes = 1;
#if 0
    for (int k = 0; k < 2; k++) {
      printf("%d\n", k);
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
          printf(" %2d", tag[k][i][j]);
        puts("");
      }
    }
#endif
    puts(yes? "YES": "NO");
  }
  return 0;
}
