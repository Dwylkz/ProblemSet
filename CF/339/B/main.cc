#include <map>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int N = 2e3 + 10;
typedef long long LL;

int n, m;

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    LL ans = 0, s = 0;
    for ( ; m--; ) {
      int a;
      scanf("%d", &a);
      a--;
      ans += (a-s+n)%n;
      s = a;
    }
    printf("%lld\n", ans);
  }
	return 0;
}
