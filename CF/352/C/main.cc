#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 4e3+10;

int n, r[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    int m = 0;
    for (int i = 0; i < 2*n; i++) {
      scanf("%*d.%d", r+m);
      if (r[m]) m++;
    }
    if (m&1) m++;
    int result = m/2*1000;
    for (int i = 0; i < m; i++) result -= r[i];
    if (result < 0) result *= -1;
    printf("%d.%.3d\n", result/1000, result%1000);
  }
  return 0;
}
