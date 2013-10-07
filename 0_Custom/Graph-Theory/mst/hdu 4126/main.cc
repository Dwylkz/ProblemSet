#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 3e3+10;
const int M = N*N;
const int inf = ~1u>>1;

struct ufs_t {
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

ufs_t ufs;
edge_t e[M];
int n, m, q, use[M], in[N][N], msts[M];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m) && (n|m); ) {
    for (int i = 0; i < m; i++) e[i].input();
    sort(e, e+m);
    for (int i = 0; i < m; i++)
      in[e[i].u][e[i].v] = in[e[i].v][e[i].u] = i;
    memset(use, 0, sizeof(int)*m);
    int mst = 0, count = 0;
    ufs.init(n);
    for (int i = 0; i < m; i++) {
      int u = e[i].u, v = e[i].v, w = e[i].w;
      if (ufs.join(u, v)) {
        mst += w;
        use[i] = 1;
        if (++count == n-1) break;
      }
    }
    for (int i = 0; i < m; i++) if (use[i]) {
      count = msts[i] = 0;
      ufs.init(n);
      for (int j = 0; j < m; j++) if (j != i) {
        int u = e[j].u, v = e[j].v, w = e[j].w;
        if (ufs.join(u, v)) {
          msts[i] += w;
          if (++count == n-1) break;
        }
      }
      if (count != n-1) msts[i] = inf;
    }
    scanf("%d", &q);
    double result = 0.;
    for (int i = 0; i < q; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      int k = in[u][v];
      if (!use[k]) result += mst;
      else result += min(msts[k], mst+w-e[k].w);
    }
    printf("%.4f\n", result/q);
  }
  return 0;
}
