#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
typedef bitset<17> bs_t;
const int N = 17;
const int M = 1<<N;

int n, g[N];
LL f[M];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int Case = 1; T--; Case++) {
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
      g[i] = 0;
      for (int j = 0, b; j < n; j++) {
        scanf("%1d", &b);
        if (b) g[i] |= 1<<j;
      }
    }
    f[0] = 1;
    int sl = 1<<n;
    for (int s = 1; s < sl; s++) {
      f[s] = 0;
      for (int i = 0; i < n; i++)
        if (s>>i&1) {
          int x = s^(1<<i), w = g[0];
          for (int j = 0; j < n; j++)
            if (x>>j&1) w |= g[j+1];
          if (w>>i&1) f[s] += f[x];
        }
    }
#if 0
    puts("g:");
    for (int i = 0; i <= n; i++)
      printf("\t%d\n", g[i]);
    puts("f:");
    for (int i = 0; i < sl; i++)
      printf("\t%s %lld\n", bs_t(i).to_string().data(), f[i]);
#endif
    printf("Case %d: %lld\n", Case, f[sl-1]);
  }
  return 0;
}
