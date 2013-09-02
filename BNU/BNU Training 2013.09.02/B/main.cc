#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3+10;

struct g_t {
  int p, j;
  void input() {
    scanf("%d%d", &p, &j);
  }
  friend bool operator < (g_t lhs, g_t rhs) {
    if (lhs.p != rhs.p) return lhs.p > rhs.p;
    return lhs.j < rhs.j;
  }
} g[N];

int n, b[N], f[N][2], p[N][2];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d\n", &T);
  for ( ; T--; ) {
    char t[30];
    scanf("%d%s", &n, t);
    for (int i = 0; i < n; i++) g[i].input();
    sort(g, g+n);
    int s = 0, vp = 0, vj = 0;
    if (*t == 'P') {
      s = 1;
      vp += g[0].p;
    }
    f[n-1][0] = 0, f[n-1][1] = g[n-1].j;
    for (int i = n-2; i >= s; i--) {
      f[i][0] = max(f[i+1][0], f[i+1][1]);
      f[i][1] = max(f[i+1][0]+g[i].j, f[i+1][1]-g[i+1].j);
    }
#if 1
    printf("f:\n");
    for (int i = 0; i < n; i++)
      printf("\tj = %4d, %4d %4d\n", g[i].j, f[i][0], f[i][1]);
#endif
    printf("%d %d\n", vp, max(f[s][0], f[s][1]));
  }
  return 0;
}
