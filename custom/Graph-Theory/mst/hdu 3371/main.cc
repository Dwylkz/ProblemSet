#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 5e2+10;
const int M = 25e3+10;

struct ujs_t {
  int f[N];
  void init(int n) {
    for (int i = 0; i < n; i++) f[i] = i;
  }
  int find(int x) {
    if (x == f[x]) return x;
    return f[x] = find(f[x]);
  }
  int join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    f[x] = y;
    return 1;
  }
};

struct edge_t {
  int u, v, w;
  void input() {
    scanf("%d%d%d", &u, &v, &w);
  }
  friend bool operator < (const edge_t &lhs, const edge_t &rhs) {
    return lhs.w < rhs.w;
  }
};

ujs_t ujs;
edge_t e[M];
int n, m, k;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
      e[i].input();
      e[i].u--;
      e[i].v--;
    }
    ujs.init(n);
    int sum = 0;
    for (int i = 0; i < k; i++) {
      int u, t;
      scanf("%d%d", &t, &u);
      for (int j = 1; j < t; j++) {
        int v;
        scanf("%d", &v);
        if (ujs.join(u-1, v-1)) sum++;
        u = v;
      }
    }
    if (sum == n-1) {
      puts("0");
      continue;
    }
    int result = 0;
    sort(e, e+m);
    for (int i = 0; i < m; i++)
      if (ujs.join(e[i].u, e[i].v)) {
        result += e[i].w;
        if (++sum == n-1) break;
      }
    if (sum < n-1) puts("-1");
    else printf("%d\n", result);
  }
  return 0;
}
