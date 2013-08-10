#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 5e6 + 10;
typedef long long LL;

int n, a[101];

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) {
      int w;
      scanf("%d", &w);
      a[w]++;
    }
    int f = 0;
    for (int i = 0; i < 101; i++) 
      for (int j = 0; j < a[i]; j++) {
        if (f) putchar(' ');
        f = 1;
        printf("%d", i);
      }
    puts("");
  }
  return 0;
}
