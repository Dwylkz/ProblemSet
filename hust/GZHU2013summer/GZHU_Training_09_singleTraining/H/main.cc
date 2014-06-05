#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3+10;

int n, f[N], w[6] = {1, 5, 10, 20, 50, 100};

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  f[0] = 1;
  for (int i = 0; i < 6; i++) {
    for (int j = w[i]; j < N; j++)
      f[j] += f[j-w[i]];
  }
#if 0
  for (int i = 0; i <= 10; i++)
    printf("%d ", f[i]);
  puts("");
#endif
  for ( ; ~scanf("%d", &n); ) {
    if (n == 0) printf("0\n");
    else printf("%d\n", f[n]);
  }
  return 0;
}
