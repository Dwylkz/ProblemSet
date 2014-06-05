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
      int quo = n/l, rem = n%l;
      if (!rem) puts("Yes");
      else if (r-l < 1) puts("No");
      else if (rem%(r-l)) puts(rem/(r-l) < quo? "Yes": "No");
      else puts(rem/(r-l) <= quo? "Yes": "No");
    }
  }
  return 0;
}
