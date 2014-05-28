#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e2+10;
const int inf = 0x3f3f3f3f;

int n, m;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    int mx = 0, mn = inf;
    for (int i = 0; i < n; i++) {
      int ai;
      scanf("%d", &ai);
      mx = max(mx, ai);
      mn = min(mn, ai);
    }
    int tl = max(mn<<1, mx);
    for (int i = 0; i < m; i++) {
      int bi;
      scanf("%d", &bi);
      if (bi <= tl) tl = -1;
    }
    printf("%d\n", tl);
  }
  return 0;
}
