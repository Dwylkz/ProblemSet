#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < (b); c++)
#define Print(a, n) \
  printf("%6s: ", #a);\
  Rep(i, 0, n) {\
    if (i && i % 10 == 0) {\
      printf("\n%8s", "");\
    }\
    printf("%10d", a[i]);\
  }\
  puts("");
typedef long long LL;
const int maxn = 1e6 + 10;

LL x, y, m;

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	for ( ; cin >> x >> y >> m; ) {
		if (x + y < 0 && 0 <= m) {
			puts("-1");
		} else {
		}
	}
	return 0;
}
