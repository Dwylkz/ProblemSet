#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3+10;

char s[N];
/* f[n]: means the minimum partition which makes all parts is palindromes. */
int f[N];

int judge(char *l, char *r) {
  for ( ; l < r; l++, r--) if (*l != *r) return 0;
  return 1;
}
int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%s", s);
    memset(f, 0x3f, sizeof(f));
    int sl = strlen(s);
    for (int i = 0; i < sl; i++) {
      f[i] = 1+(i? f[i-1]: 0);
      for (int j = 0; j < i; j++)
        if (judge(s+j, s+i)) f[i] = min(f[i], (j? f[j-1]: 0)+1);
    }
    printf("%d\n", f[sl-1]);
  }
  return 0;
}
