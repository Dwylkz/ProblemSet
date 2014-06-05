#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;

LL gcd(LL a, LL b) {
  return b? gcd(b, a%b): a;
}
LL n;

string check(LL n) {
  LL rv = 0;
  for (LL i = 1; i <= n; i++) rv += n/i;
  char buf[100];
  LL g = gcd(rv, n*n);
  sprintf(buf, "%lld/%lld", rv/g, n*n/g);
  return buf;
}

string solve(LL n) {
  LL rv = 0, r = sqrt(1.*n);
  for (int i = 1; i <= r; i++) {
    rv += n/i;
    if (n/(i+1) >= r) rv += i*(n/i-n/(i+1));
  }
  char buf[100];
  LL g = gcd(rv, n*n);
  sprintf(buf, "%lld/%lld", rv/g, n*n/g);
  return buf;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%lld", &n);
    printf("%s\n", solve(n).data());
  }
  return 0;
}
