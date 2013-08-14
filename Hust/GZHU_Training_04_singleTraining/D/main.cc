#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 5e4 + 10;
typedef long long LL;

double fac(int n, double rv = 1.0)
{
  for (int i = 2; i <=n; i++) rv *= i;
  return rv;
}

int n;

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    double rv = 0.0;
    for (int i = 0, l = 1<<n; i < l; i++) {
      int w = 0;
      for (int j = i; j; j-=-j&j) w++;
      if (w&1) rv -= fac(n-w); 
      else rv += fac(n-w);
    }
    printf("%.2lf%%\n", rv/fac(n)*100.0);
  }
  return 0;
}
