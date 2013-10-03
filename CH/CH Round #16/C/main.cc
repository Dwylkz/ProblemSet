#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;
const int M = 100+10;

int n, m, t, p, g[M][M];
char a[N], b[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d%d", &n, &m, &t, &p); ) {
    for (int i = 0; i < n; i++) {
      int ai;
      scanf("%d", &ai);
      a[i] = ai+'a';
    }
    a[n] = 0;
    for (int i = 0; i < m; i++) {
      int bi;
      scanf("%d", &bi);
      b[i] = bi+'a';
    }
    b[m] = 0;
    if (!p) {
      int rv = 0;
      for (char *i = strstr(a, b); i; i = strstr(i+m, b))
        rv++;
      printf("%d\n", rv);
    } else {
    }
  }
  return 0;
}
