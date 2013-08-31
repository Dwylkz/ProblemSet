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
const int N = 1<<17;

int s[N<<1];
#define _ls L, m, x<<1
#define _rs m+1, R, x<<1|1
void put(int x, int c) {
  for (s[x += N] = c, x >>= 1; x; x >>= 1)
    s[x] = max(s[x<<1], s[x<<1|1]);
}
int ask(int l, int r, int L = 0, int R = N-1, int x = 1) {
  if (l <= L && R <= r) return s[x];
  int rv = 0, m = L+R>>1;
  if (l <= m) rv = max(rv, ask(l, r, _ls));
  if (m < r) rv = max(rv, ask(l, r, _rs));
  return rv;
}

int x, y, f[N];

int main() {
#if 1
	freopen("input.txt", "r", stdin);
#endif
  for (int n; ~scanf("%d", &n); ) {
    int res = 0;
    for (int a, i = 0; i < n; i++) {
      scanf("%d", &a);
      int t = ask(0, a-1)+1;
      res = max(res, t);
      put(a,t);
    }
    printf("%d\n", res);
  }
	return 0;
}
