#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 5e4 + 10;
typedef long long LL;

bool d[maxn];
int n;

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    memset(d, 0, sizeof(d));
    d[0] = 1;
    for (int i = 0; i < n; i++) {
      int w;
      scanf("%d", &w);
      for (int j = maxn-1; 0 <= j; j--)
        if (d[j]) d[j+w] = 1;
    }
    int T;
    scanf("%d", &T);
    int i;
    for (i = T+1; !d[i] && i < maxn; i++) ;
    if (i == maxn) i = -1;
    printf("%d\n", i);
  }
  return 0;
}
