#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int a, b;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &a, &b); ) {
    int af[3] = {0}, bf[3] = {0}, p[3] = {2, 3, 5};
    for (int i = 0; i < 3; i++) {
      for ( ; a%p[i] == 0; a /= p[i]) af[i]++;
      for ( ; b%p[i] == 0; b /= p[i]) bf[i]++;
    }
    if (a != b) {
      puts("-1");
      continue;
    }
    int res = 0;
    for (int i = 0; i < 3; i++)
      res += max(af[i], bf[i])-min(af[i], bf[i]);
    printf("%d\n", res);
  }
  return 0;
}
