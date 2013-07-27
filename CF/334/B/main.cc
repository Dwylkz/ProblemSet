#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < (b); c++)
const int maxn = 1e6 + 10;

struct point {
  int x, y;
} p[8];
int n;
bool xh[maxn], yh[maxn];

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &p[0].x, &p[0].y); ) {
    for (int i = 1; i < 8; i++) {
      scanf("%d%d", &p[i].x, &p[i].y);
    }
    memset(xh, 0, sizeof(xh));
    memset(yh, 0, sizeof(yh));
    bool yes = 1;
    int cx = 0, cy = 0;
    for (int i = 0; i < 8; i++) {
      if (!xh[p[i].x]) cx += xh[p[i].x] = 1;
      if (!yh[p[i].y]) cy += yh[p[i].y] = 1;
    }
    if (cx != 3 || cy != 3) yes = 0;
    int mx = -1, my = -1, c = 0;
    for (int i = 0; i < maxn; i++) {
      c += xh[i];
      if (c == 2) {
        mx = i;
        break;
      }
    }
    c = 0;
    for (int i = 0; i < maxn; i++) {
      c += yh[i];
      if (c == 2) {
        my = i;
        break;
      }
    }
#if 0
    printf("%d (%d, %d), (%d, %d)\n", yes, cx, cy, mx, my);
#endif
    for (int i = 0; i < 8; i++) {
      if (p[i].x == mx && p[i].y == my) {
        yes = 0;
        break;
      }
      for (int j = i + 1; j < 8; j++) {
        if (p[i].x == p[j].x && p[i].y == p[j].y) {
          yes = 0;
          break;
        }
      }
    }
    puts(yes? "respectable": "ugly");
  }
	return 0;
}
