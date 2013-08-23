#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e2+10;

char v[N][N];
int n, m;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    int x, y;
    for (int i = 0; i < n; i++) {
      scanf("%s", v[i]);
      for (int j = 0; j < m; j++)
        if (v[i][j] == 'P') {
          x = i;
          y = j;
        }
    }
    int flag = 0;
    for (  ; !flag && x != n-1; ) {
#if 0
      printf("[%d, %d]: %c\n", x, y, v[x][y]);
#endif
      if (v[x+1][y] == '.') x++;
      else if (v[x+1][y] == '/') {
        if (y-1 < 0) flag = 1;
        else {
          y--;
          if (v[x+1][y] == '/') x++;
          else if (v[x+1][y] == '\\') flag = 1;
        }
      } else {
        if (y+1 >= m) flag = 1;
        else {
          y++;
          if (v[x+1][y] == '\\') x++;
          else if (v[x+1][y] == '/') flag = 1;
        }
      }
    }
    if (flag) puts("-1");
    else printf("%d\n", y+1);
  }
  return 0;
}
