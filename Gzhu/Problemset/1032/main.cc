#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int MOD = 1e9+7;

int n, k;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &k); ) {
    int result = 0;
    for (int i = 0; i < k; i++)
      result = 1ll*result*n%MOD+n;
    printf("%d\n", result%MOD);
  }
  return 0;
}
