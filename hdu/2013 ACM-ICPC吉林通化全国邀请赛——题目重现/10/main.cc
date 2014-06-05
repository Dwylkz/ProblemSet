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
    if (n == 1) {
      puts("1 1");
      continue;
    }
    printf("%d %d\n", n%2011, (n*3+1)%2011);
  }
  return 0;
}
