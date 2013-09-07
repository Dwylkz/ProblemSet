#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 1e5+10;

int p, n;
long double x[N], y[N];

long double cmx(long double *x) {
  long double mx = 0;
  for (int i = 0; i < n; i++) mx += x[i];
  return mx/n;
}
long double csd(long double *x) {
  long double mx = cmx(x), sd = 0;
  for (int i = 0; i < n; i++) sd += (x[i]-mx)*(x[i]-mx);
  return sqrt(sd/n);
}
long double csm(long double *x) {
  long double mx = cmx(x), sm = 0;
  for (int i = 0; i < n; i++) sm += x[i]-mx;
  return sm;
}
long double csm(long double *x, long double *y) {
  long double mx = cmx(x), my = cmx(y), sm = 0;
  for (int i = 0; i < n; i++) sm += (x[i]-mx)*(y[i]-my);
  return sm;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &p, &n); ) {
    if (p == 1) {
      for (int i = 0; i < n; i++) scanf("%Lf", x+i);
      long double mx = cmx(x), sd = csd(x);
      for (int i = 0; i < n; i++)
        printf("%.2Lf%c", (x[i]-mx)/sd, i < n-1? ' ': '\n');
    } else if (p == 2) {
      long double mp;
      scanf("%Lf", &mp);
      for (int i = 0; i < n; i++) scanf("%Lf", x+i);
      long double mx = cmx(x), se = csd(x)/sqrt(n);
      printf("%.2Lf\n", (mx-mp)/se);
    } else {
      for (int i = 0; i < n; i++) scanf("%Lf", x+i);
      for (int i = 0; i < n; i++) scanf("%Lf", y+i);
      long double sdx = csd(x), sdy = csd(y),
             smx = csm(x), smy = csm(y),
             rxy = csm(x, y)/(n*sdx*sdy),
             b = csm(x, y)/(n*sdx*sdx),
             a = cmx(y)-b*cmx(x);
      if (p == 3) printf("%.2Lf\n", rxy);
      else printf("%.2Lf %.2Lf\n", a, b);
    }
  }
  return 0;
}
