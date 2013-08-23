#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e2+10;

int a, b, n, g[N], d[N], x[N], y[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &a, &b); ) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", g+i);
      if (i) d[i] = g[i]-g[i-1];
      else d[i] = g[i]-b;
    }
    for (int i = 0; i < n; i++) {
      y[i] = 0;
      if (y[i]+d[i] < 0) y[i] = -d[i];
      x[i] = y[i]+d[i];
      a -= x[i];
      b -= y[i];
    }
    if (a < 0 || b < 0) puts("ERROR");
    else for (int i = 0; i < n; i++)
      printf("%d %d\n", x[i], y[i]);
  }
  return 0;
}
