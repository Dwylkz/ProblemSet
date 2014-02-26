#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
typedef map<int, int> MII;
const int MOD = 1e9+7;
const int N = 5e2+10;
const int M = 15e3+10;

int n, a, f[N][M];

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    MII ps;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a);
      for (int j = 2; 1ll*j*j <= a; j++)
        if (a%j == 0) {
          int s = 0;
          while (a%j == 0) {
            a /= j;
            s++;
          }
          ps[j] += s;
        }
      if (a > 1) ps[a]++;
    }
    int ret = 1;
    for (auto p: ps) {
      int s = p.second;
      for (int j = 0; j <= n; j++)
        for (int k = 0; k <= s; k++)
          f[j][k] = 0;
      f[0][s] = 1;
      for (int j = 0; j < n; j++) {
        for (int k = 0; k <= s; k++) {
          f[j+1][0] = (f[j+1][0]+f[j][k])%MOD;
          f[j+1][k+1] = (f[j+1][k+1]-f[j][k]+MOD)%MOD;
        }
        for (int k = 1; k <= s; k++)
          f[j+1][k] = (f[j+1][k]+f[j+1][k-1])%MOD;
      }
      ret = 1ll*ret*f[n][0]%MOD;
    }
    printf("%d\n", ret);
  }
  return 0;
}
