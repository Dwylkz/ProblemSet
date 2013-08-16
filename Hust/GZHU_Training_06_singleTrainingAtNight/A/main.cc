#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;

int n, m;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; scanf("%d%d", &n, &m), n|m; ) {
    LL ans = 0;
    if (n > m) swap(n, m);
    if (!n) {
      puts("0");
    } else if (n < 2) {
      ans = m*(m-1);
    } else {
      for (int i = 0; i < m; i++) {
        ans += min(i, n-1)+min(n-1, m-i-1)+n+m-2;
      }
      ans *= n;
    }
    cout << ans << endl;
  }
  return 0;
}
