#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 5e4 + 10;
typedef long long LL;

int n, h[30];

int main()
{
#if 1
	freopen("input.in", "r", stdin);
#endif
	for ( ; ~scanf("%d\n", &n); ) {
    int T = 0;
    for ( ; n--; ) {
      if (T) puts("");
      memset(h, 0, sizeof(h));
      for (int c; (c = getchar()) != '\n'; )
        h[c-'A']++;
      for (int i = 0; i < 26; i++) {
        printf("%c: ", i+'A');
        for (int j = 0; j < h[i]; j++)
          putchar('*');
        puts("");
      }
      T++;
    }
	}
	return 0;
}
