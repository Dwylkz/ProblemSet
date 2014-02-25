#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+10;

int n, a[N];

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    reverse(a, a+n);
    int ret = 0;
    for (int i = 1; i < n; i++)
      if (a[i] > a[i-1]) {
        ret = n-i;
        break;
      }
    printf("%d\n", ret);
  }
  return 0;
}
