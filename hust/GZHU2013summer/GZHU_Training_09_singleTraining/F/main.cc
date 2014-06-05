#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int N = 2e3+10;

int n, m, f[N], a[N], c[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m), n || m; ) {
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    for (int i = 0; i < n; i++) scanf("%d", c+i);
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 0; i < n; i++) {
      for (int k = c[i], o = 1; k; o <<= 1) {
        if (o > k) o = k;
        k -= o;
        for (int j = m; j >= o*a[i]; j--)
          f[j] |= f[j-o*a[i]];
      }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) ans += f[i];
    printf("%d\n", ans);
  }
  return 0;
}
