#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e2;

int r, c;
char g[N][N];

bool check(int x, int y) {
  int L = 0, R = 0, T = 0, B = 0;
  for (int i = y-1; i >= 0; i--)
    if (g[x][i] == '#') break;
    else L++;
  for (int i = y+1; i < c; i++)
    if (g[x][i] == '#') break;
    else R++;
  for (int i = x-1; i >= 0; i--)
    if (g[i][y] == '#') break;
    else T++;
  for (int i = x+1; i < r; i++)
    if (g[i][y] == '#') break;
    else B++;
#if 0
  printf("in %d %d: %d %d %d %d\n", x, y, L, R, T, B);
#endif
  return 2 <= min(L, min(R, min(T, B)));
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++)
      scanf("%s", g[i]);
    int rv = 0;
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++)
        if (g[i][j] == '^')
          rv += check(i, j);
    printf("%d\n", rv);
  }
  return 0;
}
