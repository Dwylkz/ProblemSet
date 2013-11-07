#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int N = 50+10;
const int inf = 0x3f3f3f3f;

struct graph_t {
  struct edge_t {
    int v, to;
  };
  vector<edge_t> e;
  vector<int> h;
  void init(int n) {
    e.clear();
    h.resize(n);
    fill(h.begin(), h.end(), -1);
  }
  void add(int u, int v) {
    edge_t t = {v, h[u]};
    h[u] = e.size();
    e.push_back(t);
  }
  int &operator () (int x) {
    return h[x];
  }
  edge_t &operator [] (int x) {
    return e[x];
  }
};

graph_t g;
int n, k, q;
double a[N];

int dp[N][N][N], leaf[N];
int dfs(int u) {
  int sum = 0, (*fu)[N] = dp[u];
  memset(fu, 0, sizeof(dp[0]));
  for (int e = g(u); ~e; e = g[e].to) {
    int v = g[e].v, (*fv)[N] = dp[v];
    dfs(v);
    int tmp[N][N];
    memset(tmp, 0x3f, sizeof(tmp));
    for (int s = sum+leaf[v]; s <= k; s++)
      for (int l = sum; l <= s-leaf[v]; l++) {
        int r = s-l, cost = ceil(a[u]/(l+r));
        for (int i = 0; i <= q; i++)
          for (int j = 0; j <= q; j++) {
            int angry = min(i+j, q), harm = fu[l][i]+fv[r][j];
            tmp[s][angry] = min(tmp[s][angry], harm);
            if (angry == q) tmp[s][0] = min(tmp[s][0], harm);
          }
      }
    memcpy(fu, tmp, sizeof(tmp));
    sum += leaf[v];
  }
  if (!sum) {
    leaf[u] = 1;
    for (int i = 1; i <= k; i++)
      fu[i][min(q, (int)ceil(a[u]/i))] = ceil(a[u]/i);
  } else {
    leaf[u] = sum;
    for (int i = sum; i <= k; i++)
      for (int j = 1; j <= q; j++)
        fu[i][j] = min(inf, fu[i][j]+(int)ceil(a[u]/i));
  }
  int result = inf;
  for (int i = 0; i <= q; i++)
    result = min(result, fu[k][i]);
  return result;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d", &n, &k, &q); ) {
    int rt = 0;
    g.init(n);
    for (int i = 0; i < n; i++) {
      int f;
      scanf("%lf%d", a+i, &f);
      if (f) g.add(f-1, i);
      else rt = i;
    }
    printf("%d\n", dfs(rt));
  }
  return 0;
}
