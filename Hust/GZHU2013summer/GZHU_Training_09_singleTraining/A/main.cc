#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 10+10;
typedef long long LL;

int n;

LL askf(int f) {
  LL rv = 1;
  for (int i = 0; i < f-1; i++) rv *= 10;
  return f*rv;
}
LL askp(int p, int f) {
  LL rv = p;
  for (int i = 0; i < f; i++) rv *= 10;
  return rv+askf(f);
}
LL askn(LL n) {
  LL rv = 0, f = 0, o = 1;
  if (n < 10) return n >= 1;
  for (LL t = ++n; t > 9; t /= 10, o *= 10) f++;
  for (LL t = n, p = 0; t; p += (t/o == 1), t %= o, o /= 10, f--)
    for (int i = 0, l = t/o; i < l; i++) rv += askp(p+(i == 1), f);
  return rv;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    printf("%lld\n", askn(n));
  }
  return 0;
}
