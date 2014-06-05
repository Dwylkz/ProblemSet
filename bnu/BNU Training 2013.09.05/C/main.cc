#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int n;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    int k, n;
    scanf("%d%d", &k, &n);
    int rv = 0, re = 0;
    for (int a = 1; a <= n/3; a++) {
      int b = (n-a+1)/2;
      rv += a;
    }
    for (int a = 1; a < n/3; a++) {
      int b = (n-a+1)/2+1;
      rv += a-1;
    }
    printf("%d %d\n", k, rv+re);
  }
  return 0;
}
