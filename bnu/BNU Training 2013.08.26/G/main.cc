#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 3e3+10;

int n, s[N], h[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n), n; ) {
    for (int i = 1; i <= n; i++) {
      int a;
      scanf("%d", &a);
      h[a] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", s+i);
      int mn = h[s[i]], mx = mn;
      for (int j = i-1; j >= 1; j--) {
        mn = min(mn, h[s[j]]);
        mx = max(mx, h[s[j]]);
        ans += mx-mn == i-j;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
