#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii_t;
#define _x first
#define _y second
const int N = 1e5+10;
const LL inf = 0x7fffffffffffffffll;

int n, c, w[N];
/* f[n]: means the min-cost the distribute n mail packages.
 * f[n] = min{ f[i-1]+distance(0->i->n->0) | sum(i->n) <= c, i in [0, n] } */
LL d[N], dn[N], f[N];
pii_t p[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int blank = 0; T--; blank = 1) {
    if (blank) puts("");
    scanf("%d%d", &c, &n);
    for (int i = 0; i < n; i++) {
      scanf("%lld%lld%d", &p[i]._x, &p[i]._y, w+i);
      d[i] = p[i]._x+p[i]._y;
      dn[i] = abs(p[i]._x-p[i-1]._x)+abs(p[i]._y-p[i-1]._y);
      if (i) {
        dn[i] += dn[i-1];
        w[i] += w[i-1];
      } else dn[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      f[i] = inf;
      for (int j = i; j >= 0; j--) {
        int wn = w[i]-(j? w[j-1]: 0);
        if (wn > c) break;
        LL dis = (j? f[j-1]: 0)+d[j]+dn[i]-dn[j]+d[i];
        f[i] = min(f[i], dis);
      }
    }
    printf("%lld\n", f[n-1]);
  }
  return 0;
}
