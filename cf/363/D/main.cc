#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;

int n, m, a, b[N], p[N];

int look(int x) {
  int rem = 0;
  reverse(b, b+x);
  for (int i = 0; i < x; i++)
    rem += max(0, p[i]-b[i]);
  reverse(b, b+x);
  return rem <= a;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d", &n, &m, &a); ) {
    for (int i = 0; i < n; i++) scanf("%d", b+i);
    for (int i = 0; i < m; i++) scanf("%d", p+i);
    sort(b, b+n, greater<int>());
    sort(p, p+m);
    int l = 0, r = min(n, m)+1;
    for ( ; l < r; ) {
      int m = l+r>>1;
      if (look(m)) l = m+1;
      else r = m;
    }
    int result = -a;
    for (int i = 0; i < l-1; i++) result += p[i];
    printf("%d %d\n", l-1, max(result, 0));
  }
  return 0;
}
