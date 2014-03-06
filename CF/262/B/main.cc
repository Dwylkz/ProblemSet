#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
const int N = 1e5+10;

int n, k, a[N];

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &k); ) {
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    for (int i = 0; k && i < n; i++) {
      if (a[i] >= 0) {
        if (!a[i]) k = 0;
        break;
      }
      a[i] *= -1;
      k--;
    }
    k %= 2;
    sort(a, a+n);
    if (k) a[0] *= -1;
    printf("%d\n", accumulate(a, a+n, 0));
  }
  return 0;
}
