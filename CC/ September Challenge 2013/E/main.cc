#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
typedef map<int, int> mii_t;
typedef mii_t::iterator mii_i;
const int N = 50+10;

int n, a[N], b[N];
double p[N], q[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d", &n);
    mii_t m;
    for (int i = 0; i < n; i++) {
      scanf("%lf%d%d", p+i, a+i, b+i);
      p[i] /= 100.;
      q[i] = 1.-p[i];
      m[a[i]] = m[b[i]] = 1;
    }
    if (m.size() < n) {
      printf("%f\n", 0.);
      continue;
    }
    int r = 1, sl = 1<<n;
    for (mii_i i = m.begin(); i != m.end(); i++) i->second = r++;
    for (int i = 0; i < n; i++) {
      a[i] = m[a[i]]-1;
      b[i] = m[b[i]]-1;
    }
    double rv = 0.;
    for (int s = 0; s < sl; s++) {
      int h[16] = {0}, yes = 1;
      double t = 1.;
      for (int j = 0; j < n; j++) {
        int k = s>>j&1;
        if (k) {
          if (h[a[j]]) yes = 0;
          h[a[j]] = 1;
          t *= p[j];
        } else {
          if (h[b[j]]) yes = 0;
          h[b[j]] = 1;
          t *= q[j];
        }
      }
      if (yes) rv += t;
    }
    printf("%f\n", rv);
  }
  return 0;
}
