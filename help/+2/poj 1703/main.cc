#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 3e5+10;

struct jfs_t {
  int f[N], r[N];
  void init(int n) {
    for (int i = 0; i < n; i++) f[i] = i, r[i] = 1;
  }
  int find(int x) {
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
  }
  int join(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return 0;
    if (r[x] < r[y]) f[x] = y, r[y] += r[x];
    else f[y] = x, r[x] += r[y];
    return 1;
  }
};

jfs_t zkl;
int n, m;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d%d", &n, &m);
    zkl.init(n<<1);
    for ( ; m--; ) {
      char op[10];
      int x, y;
      scanf("%s%d%d", op, &x, &y);
      x = --x<<1, y = --y<<1;
      if (*op == 'A') {
        if (zkl.find(x) == (zkl.find(y)^1)) puts("In different gangs.");
        else if (zkl.find(x) == zkl.find(y)) puts("In the same gang.");
        else puts("Not sure yet.");
      } else {
        zkl.join(x|1, y);
        zkl.join(x, y|1);
      }
    }
  }
  return 0;
}
