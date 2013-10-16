#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;
const int N = 3e5+10;

int n, m, c[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    set<int> a;
    for (int i = 1; i <= n; i++) a.insert(i);
    fill(c+1, c+n+1, 0);
    for (int i = 0; i < m; i++) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      set<int>::iterator j = a.lower_bound(x), k, b = a.upper_bound(y);
      for ( ; j != b; ) {
        k = j++;
        c[*k] = z;
        a.erase(k);
      }
      c[z] = 0;
      a.insert(z);
    }
    for (int i = 1; i <= n; i++)
      printf("%d%c", c[i], i < n? ' ': '\n');
  }
  return 0;
}
