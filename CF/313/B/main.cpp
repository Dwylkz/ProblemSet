#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
#define Rep(c, a, b) for (int c = a; c < (b); c++)
char s[maxn];
int m, sum[maxn];
int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	for ( ; ~scanf("%s\n", s); ) {
    memset(sum, 0, sizeof(sum));
    int sl = strlen(s);
    for (int i = 0; i < sl - 1; i++) {
      sum[i] = (s[i] == s[i + 1]);
    }
    for (int i = 1; i < sl; i++) {
      sum[i] += sum[i - 1];
    }
#if 0
    puts("sum:");
    for (int i = 0; i < sl; i++) {
      printf(" %d\n", sum[i]);
    }
    puts("");
#endif
    for (scanf("%d", &m) ; m--; ) {
      int l, r;
      scanf("%d%d", &l, &r);
      l--;
      r -= 2;
      int res = sum[r] - (l? sum[l - 1]: 0);
      printf("%d\n", res);
    }
	} 
	return 0;
}
