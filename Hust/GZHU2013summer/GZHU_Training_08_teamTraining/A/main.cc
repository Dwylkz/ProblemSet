#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e3+10;

int n;
double s, m[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%lf", &n, &s); ) {
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
      scanf("%lf", m+i);
    }
    sort(m, m+n);
    double t = 0.0;
    int cd = 0;
    for (int i = 0; i < n; i++) {
      for ( ; t < m[i]; t += 5.0) cd ^= 1;
      if (cd) ans += 60+s*0.2; 
      else if (m[i] == t) ans += 60+s*0.2;
    }
    printf("%.1lf\n", ans);
  }
  return 0;
}
