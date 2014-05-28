#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int n, i, j;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d", &n, &i, &j); ) {
    i--, j--;
    int round = 1;
    for ( ; i^j^1 ; round++) i >>= 1, j >>= 1;
    printf("%d\n", round);
  }
  return 0;
}
