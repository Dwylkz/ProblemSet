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
typedef long long LL;
const int maxn = 2e5 + 10;

int n, k, l[maxn << 1], lm[maxn << 1], rm[maxn << 1];

LL s[maxn << 1];

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &k); ) {
    for (int i = 0; i < n; i++) {
      scanf("%d\n", l + i);
    }
    memset(s, 0, sizeof(s));
    for (int i = n - 1; n - k <= i; i--) {
      s[n - k] += l[i];
    }
    for (int i = n - k - 1; 0 <= i; i--) {
      s[i] = l[i] + s[i + 1] - l[i + k];
    }
#if 0
    for (int i = 0; i < n; i++) {
      printf(" %lld", s[i]);
    }
    puts("");
#endif
    lm[0] = 0;
    for (int i = 1; i <= n - k; i++) {
      if (s[i] > s[lm[i - 1]]) {
        lm[i] = i;
      } else {
        lm[i] = lm[i - 1];
      }
    }
    rm[n - k] = n - k;
    for (int i = n - k - 1; 0 <= i; i--) {
      if (s[i] > s[rm[i + 1]]) {
        rm[i] = i;
      } else {
        rm[i] = rm[i + 1];
      }
    }
#if 0
    puts("lm:");
    for (int i = 0; i <= n - k; i++) {
      printf(" %d", lm[i]);
    }
    puts("");
    puts("rm:");
    for (int i = 0; i <= n - k; i++) {
      printf(" %d", rm[i]);
    }
    puts("");
#endif

    int al = 0, ar = 0 + k;
    LL ans = s[0] + s[0 + k];
    for (int i = 0; i <= n - k; i++) {
      if (k <= i) {
        if (ans < s[lm[i - k]] + s[i]
            || ans == s[i] + s[lm[i - k]] && lm[i - k] < al
            || ans == s[i] + s[lm[i - k]] && lm[i - k] == al && i < ar) {
          ans = s[i] + s[lm[i - k]];
          al = lm[i - k];
          ar = i;
        }
      }
      if (i <= n - k - k) {
        if (ans < s[i] + s[rm[i + k]]
            || ans == s[i] + s[rm[i + k]] && i < al
            || ans == s[i] + s[rm[i + k]] && i == al && rm[i + k] < ar) {
          ans = s[rm[i + k]] + s[i];
          al = i;
          ar = rm[i + k];
        }
      }
    }
    printf("%d %d\n", al + 1, ar + 1);
  }
	return 0;
}
