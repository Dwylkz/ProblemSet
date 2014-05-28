#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int a, b, c;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d", &a, &b, &c); ) {
    int x, y = -1, z = -1;
    for (x = 0; x <= a; x++) {
      int ty = b-x, tz = c-ty;
      if (ty >= 0 && tz >= 0 && x+tz == a) {
        y = ty;
        z = tz;
        break;
      }
    }
    if (~y) printf("%d %d %d\n", x, y, z);
    else puts("Impossible");
  }
  return 0;
}
