#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3+10;

struct cube {
  int x, y, z;
  friend bool operator < (cube lhs, cube rhs) {
    if (lhs.x != rhs.x) return lhs.x < rhs.x;
    if (lhs.y != rhs.y) return lhs.y < rhs.y;
    return lhs.z < rhs.z;
  }
  friend bool operator > (cube lhs, cube rhs) {
    return lhs.x > rhs.x && lhs.y > rhs.y && lhs.z > rhs.z;
  }
  void input() {
    scanf("%d%d%d", &x, &y, &z);
    int v[3] = {x, y, z};
    sort(v, v+3);
    x = v[0];
    y = v[1];
    z = v[2];
  }
} c[N];

int f[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int n; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) c[i].input();
    sort(c, c+n);
    memset(f, 0, sizeof(f));
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int tmp = 0;
      for (int j = 0; j < i; j++)
        if (c[i] > c[j]) tmp = max(tmp, f[j]);
      f[i] = tmp+1;
      ans = max(ans, f[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
