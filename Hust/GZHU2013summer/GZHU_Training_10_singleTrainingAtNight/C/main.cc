#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;

int n, a[N], f[N], g[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    f[0] = a[0];
    for (int i = 1; i < n; i++) f[i] = f[i-1]&a[i];
    g[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--) g[i] = g[i+1]&a[i];
    int yes = -1;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      if (!i) sum = g[i+1];
      else if (i == n-1) sum = f[i-1];
      else sum = f[i-1]&g[i+1];
      if (sum == a[i]) {
        yes = a[i];
        break;
      }
    }
    if (yes >= 0) printf("%d\n", yes);
    else puts("CAUTION: NO BIRDLIKE");
  }
  return 0;
}
