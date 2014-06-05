#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3+10;

int m, n, t[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d%d", &m, &n);
    int s, d;
    for (int i = 0; i < m; i++) {
      scanf("%d", t+i);
      if (t[i] > 1) {
        s = i;
        if (t[i] == 2) d = 1;
        else d = -1;
      }
    }
    int ans = 0;
    for ( ; n--; ) {
      if (s+d == m || s+d == -1) d *= -1;
      s += d;
      ans += !t[s];
    }
    printf("%d\n", ans);
  }
  return 0;
}
