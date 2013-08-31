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
  for ( ; ~scanf("%d", &n), n; ) {
    printf("%d", n);
    for ( ; n > 9; ) {
      int t = 1;
      for (int i = n; i; i /= 10) t *= i%10;
      n = t;
      printf(" %d", n);
    }
    puts("");
  }
  return 0;
}
