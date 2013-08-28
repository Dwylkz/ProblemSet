#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 5e2+10;

struct jfs_t {
  int f[N], e[N], r[N];
  void init( int n) {
    for (int i = 0; i < n; i++)
      f[i] = i, r[i] = 1;
    memset(e, 0, sizeof(e));
  }
  int find(int x) {
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
  }
  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      e[x]++;
      return 0;
    }
    f[x] = y;
    e[y] += e[x]+1;
    r[y] += r[x];
    return 1;
  }
} jfs;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int n, m, T = 1; ~scanf("%d%d", &n, &m), n||m; ) {
    printf("Case %d: ", T++);
    jfs.init(n);
    for ( ; m--; ) {
      int u, v;
      scanf("%d%d", &u, &v);
      jfs.join(--u, --v);
    }
    int cc = 0, t = 0;
    for (int i = 0; i < n; i++)
      if (jfs.f[i] == i) {
        cc++;
        t += jfs.e[i] == jfs.r[i]-1;
      }
    if (cc == 1) {
      if (t) printf("There is one tree.");
      else printf("No trees.");
    } else {
      if (t == 1) printf("There is one tree.");
      else if (t > 1) printf("A forest of %d trees.", t);
      else printf("No trees.");
    }
    puts("");
  }
  return 0;
}
