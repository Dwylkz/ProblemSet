#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;

LL n;

LL askf(int g, int f) {
  LL rv = 0;
  if (g&1) {
    rv = -1;
    for ( ; f--; ) rv *= 10;
    rv /= 2;
  } else if (f&1) {
    rv = -45;
    for ( ; --f; ) rv *= 10;
  }
  return rv;
}
LL askp(LL p, int f) {
  LL rv = 0, d = 0, o = 1;
  for (int t = p; t; t /= 10) d++, o *= 10;
  for (int t = p, i = 0; t; t %= o, o /= 10, i ^= 1)
    if (i&1) rv -= t/o;
    else rv += t/o;
  for (int i = 0; i < f; i++) rv *= 10;
  if (f+d&1) {
  } else rv += askf(d+f, f);
  return rv;
}
LL askn(LL n) {
  return 0;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%lld", &n); ) {
    printf("%lld\n", askn(n));
  }
  return 0;
}
