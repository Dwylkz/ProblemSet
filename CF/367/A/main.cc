#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int N = 1e5+10;

char s[N];
int m, h[N][3];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%s", s); ) {
    memset(h, 0, sizeof(h));
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
      h[i][s[i]-'x']++;
      if (i) {
        for (int j = 0; j < 3; j++)
          h[i][j] += h[i-1][j];
      }
    }
    scanf("%d", &m);
    for ( ; m--; ) {
      int l, r;
      scanf("%d%d", &l, &r);
      l--, r--;
      if (r-l+1 < 3) {
        puts("YES");
        continue;
      }
      int t[3], mn = ~1u>>1;
      for (int i = 0; i < 3; i++) {
        t[i] = h[r][i]-(l? h[l-1][i]: 0);
        mn = min(mn, t[i]);
      }
      for (int i = 0; i < 3; i++) t[i] -= mn;
      if (t[0] < t[1]) swap(t[0], t[1]);
      if (t[1] < t[2]) swap(t[1], t[2]);
      if (t[0] < 2 &&  t[1] < 2 && t[2] < 2) puts("YES");
      else puts("NO");
    }
  }
  return 0;
}
