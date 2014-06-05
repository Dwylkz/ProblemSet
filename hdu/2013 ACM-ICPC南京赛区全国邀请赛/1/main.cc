#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2e2+10;

int n, m, a[N];
bool b[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
      b[i] = 0;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      int bi;
      scanf("%d", &bi);
      b[bi-1] = 1;
    }
    m = 0;
    for (int i = 0; i < n; i++) m += b[i];
    int g = 0, s = 0, f = 0;
    double p = 1.0*m/n, q = 1.0-p;
    for (int i = 0; i < n; i++) {
      if (b[i]) {
        s += a[i];
        if (!a[i]) f = 1;
      } else {
        g += a[i];
      }
    }
    if (!m) {
      printf("%.2lf\n", 1.0*g/n);
      continue;
    } else if (n == m) {
      puts(s? "inf": "0.00");
      continue;
    }
    printf("%.2f\n", 1.0*g/n+p*p*(1.0*g+(1.0*n-m)*s/(q*m))/(q*m));
  }
  return 0;
}
