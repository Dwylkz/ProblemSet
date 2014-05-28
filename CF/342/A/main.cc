#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 8;

int n;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    int h[N] = {0};
    for (int a, i = 0; i < n; i++) {
      scanf("%d", &a);
      h[a]++;
    }
    int a = 0, b = 0, c = 0;
    for ( ; n; ) {
      int yes = 0;
      if (h[1] && h[2] && h[4]) {
        int mn = min(h[1], min(h[2], h[4]));
        h[1] -= mn;
        h[2] -= mn;
        h[4] -= mn;
        n -= 3*mn;
        a += mn;
        yes = 1;
      }
      if (h[1] && h[2] && h[6]) {
        int mn = min(h[1], min(h[2], h[6]));
        h[1] -= mn;
        h[2] -= mn;
        h[6] -= mn;
        n -= 3*mn;
        b += mn;
        yes = 1;
      }
      if (h[1] && h[3] && h[6]) {
        int mn = min(h[1], min(h[3], h[6]));
        h[1] -= mn;
        h[3] -= mn;
        h[6] -= mn;
        n -= 3*mn;
        c += mn;
        yes = 1;
      }
      if (!yes) break;
    }
    if (n) puts("-1");
    else {
      for ( ; a--; ) puts("1 2 4");
      for ( ; b--; ) puts("1 2 6");
      for ( ; c--; ) puts("1 3 6");
    }
  }
  return 0;
}
