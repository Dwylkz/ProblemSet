#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 2e3+10;

int n, k, s[N];

int t[N];
int look(int x) {
  memcpy(t, s, sizeof(s));
  for (int i = 0; i < k; i++) {
    int mi = 1;
    for (int j = 2; j < n; j++)
      if (abs(t[j]-t[j-1]) > abs(t[mi]-t[mi-1]))
        mi = j;
    if (abs(t[mi]-t[mi-1]) > x)
      if (t[mi] > t[mi-1]) t[mi] = t[mi-1]+x;
      else t[mi] = t[mi-1]-x;
  }
  for (int i = 1; i < n; i++)
    if (abs(t[i]-t[i-1]) > x) return 0;
  return 1;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &k); ) {
    for (int i = 0; i < n; i++) scanf("%d", s+i);
    if (n <= 1) {
      puts("0");
      continue;
    }
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
      r = max(r, abs(s[i]-s[i-1]));
    for ( ; l < r; ) {
      int m = l+r>>1;
      if (look(m)) r = m;
      else l = m+1;
    }
    printf("%d\n", l);
  }
  return 0;
}
