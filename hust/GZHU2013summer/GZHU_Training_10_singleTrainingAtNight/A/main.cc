#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;
const int mod = 1e8+7;

int f[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int n; ~scanf("%d", &n); ) {
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for ( ; n--; ) {
      int w;
      scanf("%d", &w);
      for (int i = N-1; i >= w; i--)
        f[i] = (f[i]+f[i-w])%mod;
    }
    for (int i = 1; i < N; i++)
      if (f[i]) printf("%d %d\n", i, f[i]);
  }
  return 0;
}
