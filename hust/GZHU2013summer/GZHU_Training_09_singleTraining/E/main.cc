#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 120+10;

int n, k, f[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d%d", &n, &k);
    memset(f, 0, sizeof(f));
    f[0] = 1;
    int b = 0;
    for (int i = 0; i < n; i++) {
      int w;
      scanf(b? ",%d": "%d", &w);
      b = 1;
      for (int j = k; j >= w; j--)
        f[j] += f[j-w];
    }
    printf("%d\n", f[k]);
  }
  return 0;
}
