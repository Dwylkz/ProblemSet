#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int n;

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    int ret = !n? 1: n < 2? 4: (n-1)*4+4,
        a = n+1>>1, b = n+1-a;
    if (n > 1 && 1ll*a*a+1ll*b*b <= 1ll*n*n)
      ret += 4;
    printf("%d\n", ret);
  }
  return 0;
}
