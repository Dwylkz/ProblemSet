#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int r, h;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &r, &h); ) {
    int rv = h/r*2, rm = r-(1.*h-(h/r)*r);
    if (rm <= (1.-sqrt(3.)/2.)*r) rv += 3;
    else if (rm <= r/2) rv += 2;
    else rv += 1;
    printf("%d\n", rv);
  }
  return 0;
}
