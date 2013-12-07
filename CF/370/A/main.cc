#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int r1, c1, r2, c2;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d%d", &r1, &c1, &r2, &c2); ) {
    int dr = abs(r1-r2), dc = abs(c1-c2),
        r = (dr>0)+(dc>0),
        b = (r1+c1)%2 == (r2+c2)%2? dr == dc? 1: 2: 0,
        s = max(dr, dc);
    printf("%d %d %d\n", r, b, s);
  }
  return 0;
}
