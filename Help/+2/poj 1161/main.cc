#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 3e5+500+10;

int n, m, f[N];
int find(int x) {
  if (x != f[x]) f[x] = find(f[x]);
  return f[x];
}
void join(int x, int y) {
  x = find(x), y = find(y);
  if (x > y) swap(x, y);
  if (x == y) return ;
  f[y] = x;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m), n|m; ) {
    for (int i = 0; i < n+m; i++) f[i] = i;
    for (int k, i = 1; i <= m; i++) {
      scanf("%d", &k);
      for (int u; k--; ) {
        scanf("%d", &u);
        if (u) u += m;
        join(i, u);
      }
    }
    int rv = 1;
    for (int i = m+1; i < m+n; i++)
      rv += !find(i);
    printf("%d\n", rv);
  }
  return 0;
}
