#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e4+10;
const int K = 10+10;
const int inf = 1e8+10;

namespace graph {
  struct edge_t {
    int v, to, w;
  };
  vector<edge_t> E;
  int L[N];
  void init(int n) {
    E.clear();
    memset(L, -1, sizeof(int)*n);
  }
  void add(int u, int v, int w) {
    edge_t t = {v, L[u], w};
    L[u] = E.size();
    E.push_back(t);
  }
}
using namespace graph;

int n, s, k; 

int dp[N][2][K], ra[N], h[K], l[N];
void dfs(int u) {
  int *fu = dp[u][0], *gu = dp[u][1], is = 1;
  fill(fu, fu+K, 0);
  fill(gu, gu+K, 0);
  l[u] = 0;
  for (int e = L[u]; ~e; e = E[e].to) {
    if (e == ra[u]) continue;
    int v = E[e].v, w = E[e].w;
    is = 0;
    ra[v] = e^1;
    dfs(v);
    int *fv = dp[v][0], *gv = dp[v][1];
    fill(h+1, h+K, inf<<4);
    for (int r = k; r >= 1; r--) {
      for (int i = min(r, l[v]); i >= 1; i--) {
        int j = max(l[u] > 0, min(r-i, l[u])), x = max(0, j-(r-i)), y = max(0, i-(r-j));
        // 1. u first
        h[r] = min(h[r], fu[i]+gu[x]+j*w+fv[j]);
        // 2. v first
        h[r] = min(h[r], fv[j]+gv[y]+(j+y)*w+fu[i]);
      } // i = robot send to v
    } // r = robot amount
    memcpy(fu, h, sizeof(h));
    fill(h+1, h+K, inf<<4);
    for (int b = 1; b <= k; b++) {
      for (int i = min(l[u], b); i >= 0; i--) {
        h[b] = min(h[b], gu[i]+gv[b-i]+(b-i)*w);
      } // i = amount of robot which return from u
    } // b = the number of robot coming back
    memcpy(gu, h, sizeof(h));
    l[u] += l[v];
  }
  l[u] += is;
#if 1
  printf("out %d l = %d:\n", u, l[u]);
  printf("f: ");
  for (int i = 0; i <= k; i++) printf("%4d", fu[i] == inf? -1: fu[i]);
  puts("");
  printf("g: ");
  for (int i = 0; i <= k; i++) printf("%4d", gu[i] == inf? -1: gu[i]);
  puts("\n");
#endif
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d", &n, &s, &k); ) {
    init(n);
    for (int i = 0; i < n-1; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      add(--u, --v, w);
      add(v, u, w);
    }
    memset(ra, -1, sizeof(ra));
    dfs(--s);
    printf("%d\n", dp[s][0][k]);
  }
  return 0;
}
