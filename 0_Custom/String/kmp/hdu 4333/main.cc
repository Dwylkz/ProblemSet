#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2e5+10;

struct exkmp_t {
  void operator () (char *p, int *g) {
    int pl = g[g[1] = 0] = strlen(p);
    for (int i = 1, k = 1; i < pl; (k+g[k] < i+g[i]? k = i: 0), i++)
      for (g[i] = min(g[i-k], max(k+g[k]-i, 0)); ; g[i]++)
        if (i+g[i] >= pl || p[i+g[i]] != p[g[i]]) break;
  }
  void operator () (char *s, char *p, int *f, int *g) {
    int sl = strlen(s), pl = strlen(p);
    for (int i = f[0] = 0, k = 0; i < sl; (k+f[k] < i+f[i]? k = i: 0), i++)
      for (f[i] = min(g[i-k], max(k+f[k]-i, 0)); ; f[i]++)
        if (i+f[i] >= sl || f[i] >= pl || s[i+f[i]] != p[f[i]]) break;
  }
} exkmp;

char a[N];
int f[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int ks = 1; T--; ks++) {
    printf("Case %d: ", ks);
    scanf("%s", a);
    int n = strlen(a);
    strncat(a, a, n);
    exkmp(a, f);
    int l = 0, e = 0, r = 0, c = n;
    for (int i = 1; i < n; i++)
      if (f[i] == 2*n-i) c = min(c, i);
    for (int i = 0; i < n; i++)
      if (f[i] >= n) e++;
      else if (a[i+f[i]] > a[f[i]]) r++;
      else l++;
    printf("%d %d %d\n", l/(n/c), e/(n/c), r/(n/c));
  }
  return 0;
}
