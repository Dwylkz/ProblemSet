#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = ~1u>>1;
const int N = 1e5+10;

int m, n, a[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &m); ) {
    int q = INF;
    for (int i = 0; i < m; i++) {
      int qi;
      scanf("%d", &qi);
      q = min(q, qi);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    sort(a, a+n, greater<int>());
    int cost = 0;
    for (int i = 0; i < n; i++) {
      for (int b = i+q; i < min(b, n); ) cost += a[i++];
      for (int b = i+2; i < min(b, n); ) i++;
      i--;
    }
    printf("%d\n", cost);
  }
  return 0;
}
