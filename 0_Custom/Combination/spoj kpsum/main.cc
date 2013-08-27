#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;

LL n;

LL askf(int f, int g) {
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
  LL rv = 0;
  return 0;
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
