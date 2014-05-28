#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e6+10;

struct exkmp_t {
  void operator () (char *p, int *g) {
    int pl = g[0] = strlen(p);
    for (int i = 1; i < pl; i++)
      for (int j = max(0, min(g[1], g[i-1]-1)); ; j++)
        if (i+j == pl || j == pl || p[i+j] != p[j]) {
          g[i] = j;
          break;
        }
  }
  void operator () (char *s, char *p, int *f, int *g) {
    int sl = strlen(s), pl = strlen(p);
    for (int i = 0; i < sl; i++)
      for (int j = max(0, min(g[1], i? f[i-1]-1: 0)); ; j++)
        if (i+j == sl || j == pl || s[i+j] != p[j]) {
          f[i] = j;
          break;
        }
  }
} exkmp;

int f[N], g[N];
char a[N], b[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%s%s", a, b); ) {
    int rv = 0, la = strlen(a);
    exkmp(b, g);
    exkmp(a, b, f, g);
    for (int i = 0; i < la; i++)
      if (f[i] == la-i) rv = max(rv, f[i]);
    printf("%d\n", rv);
  }
  return 0;
}
