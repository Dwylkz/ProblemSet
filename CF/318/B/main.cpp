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

char h[] = "heavy",
     m[] = "metal",
     s[maxn];
int hp[maxn], mp[maxn];

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	for ( ; ~scanf("%s", s); ) {
    memset(hp, 0, sizeof(hp));
    memset(mp, 0, sizeof(mp));
    int ls = strlen(s);
    for (int i = 0, j; i < ls; i++) {
      for (j = 0; i < ls && j < 5 && s[i] == h[j]; i++, j++) {}
      if (j == 5) {
        hp[i - j + 1] = 1;
      }
      if (j) {
        i--;
      }
      for (j = 0; i < ls && j < 5 && s[i] == m[j]; i++, j++) {}
      if (j == 5) {
        mp[i - j + 1] = 1;
      }
      if (j) {
        i--;
      }
    }
    for (int i = 1; i <= ls; i++) {
      mp[i] += mp[i - 1];
    }
#if 0
    Print(hp, ls + 1);
    Print(mp, ls + 1);
#endif
    LL res = 0;
    for (int i = 1; i <= ls; i++) {
      res += (hp[i]? 1: 0) * (mp[ls] - mp[i + 4]);
    }
    cout << res << endl;
	} 
	return 0;
}
