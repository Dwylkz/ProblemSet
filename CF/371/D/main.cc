#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2e5+10;

int n, a[N], r[N], m;

int f[N];
void init(int n) {
  for (int i = 0; i < n; i++) f[i] = i;
}
int find(int x) {
  if (x != f[x]) f[x] = find(f[x]);
  return f[x];
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
      r[i] = a[i];
    }
    init(n+1);
    scanf("%d", &m);
    for ( ; m--; ) {
      int op, x, y;
      scanf("%d%d", &op, &x);
      x--;
      if (op < 2) {
        scanf("%d", &y);
        for ( ; ; ) {
          x = find(x);
          if (!y || x == n) break;
          int delta = min(r[x], y);
          r[x] -= delta;
          y -= delta;
          if (!r[x]) f[x] = x+1;
        }
      } else printf("%d\n", a[x]-r[x]);
    }
  }
  return 0;
}
