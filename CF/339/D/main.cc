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
const int N = (1<<17)+10;

int n, m,s[N<<1];
int push(int k, int c, int L, int R, int x = 1) {
  int rv = 0;
  if (L == R) s[x] = c;
  else {
    int m = L+R>>1, d;
    if (k <= m) d = push(k, c, L, m, x<<1);
    else d = push(k, c, m+1, R, x<<1|1);
    if (d&1) s[x] = s[x<<1]^s[x<<1|1];
    else s[x] = s[x<<1]|s[x<<1|1];
    rv = d^1;
  }
  return rv;
}

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    memset(s, 0, sizeof(s));
    n = 1<<n;
    for (int i = 1; i <= n; i++) {
      int a;
      scanf("%d", &a);
      push(i, a, 1, n);
    }
    for ( ; m--; ) {
      int p, a;
      scanf("%d%d", &p, &a);
      push(p, a, 1, n);
      printf("%d\n", s[1]);
    }
  }
	return 0;
}
