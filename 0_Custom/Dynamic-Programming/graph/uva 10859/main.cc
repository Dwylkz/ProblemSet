#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3+10;
const int inf = 0x3f3f3f3f;

struct edge_t {
  int v, to;
};
vector<edge_t> E;
int L[N];
void init() {
  E.clear();
  memset(L, -1, sizeof(L));
}
void add(int u, int v) {
  edge_t t = {v, L[u]};
  L[u] = E.size();
  E.push_back(t);
}

/* f(u, [place/unplace]): the minimun value=light_number*N+roads_with_one_light
 *                        when we place/unplace a light on node u. */
int n, m, f[N][2], t[2], ra[N];

void dfs(int u) {
  f[u][0] = 0;
  f[u][1] = N;
  for (int e = L[u]; ~e; e = E[e].to)
    if (e != ra[u]) {
      int v = E[e].v;
      ra[v] = e^1;
      dfs(v);
      t[0] = t[1] = inf;
      t[0] = min(t[0], f[u][0]+f[v][1]+1);
      t[1] = min(t[1], f[u][1]+f[v][0]+1);
      t[1] = min(t[1], f[u][1]+f[v][1]);
      memcpy(f[u], t, sizeof(t));
    }
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d%d", &n, &m);
    init();
    for (int u, v, i = 0; i < m; i++) {
      scanf("%d%d", &u, &v);
      add(u, v), add(v, u);
    }
    memset(ra, -1, sizeof(ra));
    int ans = 0;
    for (int u = 0; u < n; u++)
      if (ra[u] == -1) {
        dfs(u);
        ans += min(f[u][0], f[u][1]);
      }
    printf("%d %d %d\n", ans/N, m-ans%N, ans%N);
  }
  return 0;
}
