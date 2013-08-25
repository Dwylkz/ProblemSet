#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 10+10;
typedef long long LL;

int n;
char a[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%s", a); ) {
    int l = strlen(a), bl = 1<<l;
    LL ans = 0;
    for (int i = 0; i < l; i++) a[i] -= '0';
    for (int s = 1; s < bl; s++) {
      int w = 0;
      for (int i = s; i; i -= -i&i) w++;
      for (int i = 0; i < l; i++) {
        LL tmp = a[i]-(a[i] > 1);
        if (s&(1<<i)) {
          if (a[i] >= 1) tmp = 1;
          else tmp = 0;
        }
        for (int k = i+1; k < l; k++)
          if (~s&(1<<k)) tmp *= 9;
        ans += tmp*w;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
