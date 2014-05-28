// #pragma comment(linker, "/STACK:65535000")
#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < (b); c++)
const int maxn = 1000 + 10;
typedef long long LL;
const LL ub = 1e17;

int n, m, b[maxn][maxn], r[maxn], c[maxn];

int main()
{
  recursive(1e7);
#if 1
	freopen("input.txt", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    memset(b, 0, sizeof(b));
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    for ( ; m--; ) {
      int i, j;
      scanf("%d%d", &i, &j);
      i--; j--;
      b[i][j] = 1;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (b[i][j]) r[i] = c[j] = 1;
      }
    }
#if 0
    for (int i = 0; i < n; i++) {
      printf(" %d", r[i]);
    }
    puts("");
    for (int i = 0; i < n; i++) {
      printf(" %d", c[i]);
    }
    puts("");
#endif
    int ans1 = 0;
    for (int i = 1; i < n - 1; i += 2) ans1 += !r[i];
    for (int i = 2; i < n - 1; i += 2) ans1 += !c[i];
    int ans2 = 0;
    for (int i = 1; i < n - 1; i += 2) ans2 += !c[i];
    for (int i = 2; i < n - 1; i += 2) ans2 += !r[i];
    printf("%d\n", max(ans1, ans2));
  }
	return 0;
}
