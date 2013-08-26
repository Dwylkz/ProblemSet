#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3+10;

int n, m, a[N], b[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    for (int i = 0; i < m; i++) scanf("%d", b+i);
    int ans = 0x7fffffff;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        ans = min(ans, abs(a[i]-b[j]));
    printf("%d\n", ans);
  }
  return 0;
}
