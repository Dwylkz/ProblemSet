#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 16;
const int S = 1<<N;

/* e(i) = [b0...bn] represent whether j is/isn't i's neighbor.
 * c(s = [s0...sn]) = [b0b1...bn] represent whether j is/isn't covered when we choose [s0...sn].
 * f(s = [s0...sn]) = represent maximum number of destoried servers when we choose [s0...sn].
 * i, j in [0, n)
 * */
int n, e[N], c[S], f[S];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int Case = 1; ~scanf("%d", &n), n; Case++) {
    int sl = 1<<n;
    for (int m, i = 0; i < n; i++) {
      scanf("%d", &m);
      e[i] = 1<<i;
      for (int j; m--; ) {
        scanf("%d", &j);
        e[i] |= 1<<j;
      }
    }
    for (int s = 0; s < sl; s++) {
      c[s] = 0;
      for (int i = 0; i < n; i++)
        if (s>>i&1) c[s] |= e[i];
    }
    memset(f, 0, sizeof(f));
    for (int s = 0; s < sl; s++)
      for (int b = s; b; b = (b-1)&s)
        if (c[b] == sl-1) f[s] = max(f[s], f[s^b]+1);
    printf("Case %d: %d\n", Case, f[sl-1]);
  }
  return 0;
}
