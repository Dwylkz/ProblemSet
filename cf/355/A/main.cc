#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int k, d;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &k, &d); ) {
    if (k > 1 && !d) {
      puts("No solution");
    } else {
      printf("%d", d);
      for (int i = 1; i < k; i++) putchar('0');
      puts("");
    }
  }
  return 0;
}
