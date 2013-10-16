#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;

int n, m, c[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    fill(c, c+n, 0);
    for (int i = 0; i < m; i++) {
      int a[3];
      scanf("%d%d%d", a, a+1, a+2);
      int used = 0;
      for (int j = 0; j < 3; j++)
        if (c[a[j]]) {
          used = c[a[j]];
          break;
        }
      int col = 1;
      for (int j = 0; j < 3; j++)
        if (!c[a[j]]) {
          if (used == col) col++;
          c[a[j]] = col++;
        }
    }
    for (int i = 0; i < n; i++)
      printf("%d%c", c[i+1], i < n-1? ' ': '\n');
  }
  return 0;
}
