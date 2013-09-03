#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int n, m, k;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d", &n, &k, &m), n|m|k; ) {
    int rv = 0;
    for (int l = 2; l <= n; l++) rv = (rv+k)%l;
    rv = (rv+m-k+1)%n;
    for ( ; rv <= 0; rv += n) ;
    printf("%d\n", rv);
  }
  return 0;
}
