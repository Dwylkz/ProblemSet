#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int t, n, l, r;

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &t); ) {
    while (t--) {
      scanf("%d%d%d", &n, &l, &r);
      int quot = n/l, rem = n%l;
      if (!quot) puts("No");
      else {
      }
    }
  }
  return 0;
}
