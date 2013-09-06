#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 64+10;
typedef long long LL;

LL n, c[N][N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int i = c[0][0] = 1; i < N; i++)
    for (int j = c[i][0] = 1; j <= i; j++) 
      c[i][j] = c[i-1][j]+c[i-1][j-1];
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%lld", &n);
    int L = 1, R = 70;
    for ( ; L < R; ) {
      LL m = L+R>>1;
      if (c[m][(m+1)>>1] >= n) R = m;
      else L = m+1;
    }
    printf("%d\n", R);
  }
  return 0;
}
