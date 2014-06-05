#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 5e4 + 10;
typedef long long LL;

int L, T, n, p[maxn];

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d", &L, &T, &n); ) {
    int mn = 0, *pp = p;
    for (int i = 0; i < n; i++) {
      int j, o;
      char op[2];
      scanf("%d%s", &j, op);
      if (op[0] == 'L') {
        mn = max(mn, j);
        j -= T;
      } else {
        mn = max(mn, L-j);
        j += T;
      }
      *pp++ = j;
    }
    sort(p, p + n);
    for (int i = 0; i < n; i++)
      if (p[i] <= 0 || L <= p[i]) puts("fell off");
      else printf("%d\n", p[i]);
    printf("%d\n", mn);
  }
  return 0;
}
