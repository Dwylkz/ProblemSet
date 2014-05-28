#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 18+1;

LL l, r, dp[N][10];

void init() {
  dp[0][0] = 1;
  for (int i = 1; i < N; i++)
    for (int j = 0; j < 10; j++)
      for (int k = 0; k < 10; k++)
          dp[i][(j+k)%10] += dp[i-1][j];
  dp[0][0] = 1;
}
LL sum(LL x) {
  if (x < 10) return x >= 0;
  LL rv = 0, o = 1, d = 1;
  x++;
  for (LL t = x; t > 9; t /= 10) o *= 10, d++;
  for (LL t = x, p = 0; d--;  p = (p+t/o)%10, t %= o, o /= 10)
    for (int i = 0; i < t/o; i++)
      rv += dp[d][(10-(p+i)%10)%10];
  return rv;
}
LL look(LL x, LL y) {
  int rv = 0;
  for (int i = x; i <= y; i++) {
    int t = 0;
    for (int j =  i; j; j /= 10) t += j%10;
    rv += t%10 == 0;
  }
  return rv;
}
void test(int l, int r) {
  for (int i = 0; i < l; i++)
    for (int j = i; j < r; j++) {
      LL a = look(i, j), b = sum(j)-sum(i-1);
      if (a != b) printf("[%d, %d], %lld %lld\n", i, j, a, b);
    }
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  init();
//   test(1000, 1000);
  int T;
  scanf("%d", &T);
  for (int ks = 1; T--; ks++) {
    scanf("%lld%lld", &l, &r);
    printf("Case #%d: %lld\n", ks, sum(r)-sum(l-1));
  }
  return 0;
}
