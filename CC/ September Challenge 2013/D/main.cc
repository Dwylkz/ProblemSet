#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
typedef long long LL;

int n;
LL x, s[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) scanf("%lld", s+i);
    scanf("%lld", &x);
    sort(s, s+n, greater<int>());
    LL rv = 0, d = 0;
    for (int i = 0; i < n; i++) {
      if (s[i]+d >= 0) continue;
      LL up = 0-(s[i]+d);
      if (x < n-i) rv += up*x;
      else rv += up*(n-i);
      d += up;
    }
    printf("%lld\n", rv);
  }
  return 0;
}
