#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int n, m;

/* jc(x): as the last x-th man who was kicked out. */
int jc(int x) {
  int f = (m-1)%x;
  for (int i = x+1; i <= n; i++) f = (f+m)%i;
  return f+1;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d%d", &n, &m);
    printf("%d %d %d\n", jc(3), jc(2), jc(1));
  }
  return 0;
}
