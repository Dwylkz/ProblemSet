#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int l, p, v;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int T = 1; ~scanf("%d%d%d", &l, &p, &v), l|p|v; ) {
    int res = v/p*l;
    if (v%p > 0) res += min(v%p, l);
    printf("Case %d: %d\n", T++, res);
  }
  return 0;
}
