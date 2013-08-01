#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 3e5 + 10,
      maxm = 64;
typedef unsigned long long LL;

char s[maxn];
LL dp[2][maxm], dpi;

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%s", s); ) {
    int sl = strlen(s), i, ans;
    for (i = 0; i < sl && s[i] == '0'; i++) ans++;
    memset(dp, dpi = 0, sizeof(dp));
    dp[dpi][(s[i]-'0')%maxm] = 1;
    for (i++; i < sl; i++) {
      dpi ^=1 ;
      memcpy(dp[dpi], dp[!dpi], sizeof(dp[!dpi]));
      for (int j = 0; j < maxm; j++) {
        dp[dpi][(j*10+s[i]-'0')%maxm] += dp[!dpi][j];
      }
    }
    printf("%llu\n", dp[dpi][0]+ans);
  }
  return 0;
}
