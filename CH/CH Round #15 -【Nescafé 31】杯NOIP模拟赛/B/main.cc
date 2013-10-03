#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 3e4+10;

struct edge_t {
  int v, to, w;
};
vector<edge_t> E;
int L[N];
void init() {
  E.clear();
  memset(L, -1 , sizeof(L));
}
void add(int u, int v, int w) {
  edge_t t = {v, L[u], w};
  L[u] = E.size();
  E.push_back(t);
}
void badd(int u, int v, int w) {
  add(u, v, w), add(v, u, w);
}

int n, m, r[N];

int result, limit[N], bound[N], dist[N], inqueue[N], relax[N];
void spfa(int u) {
  stack<int> q;
  memset(inqueue, 0, sizeof(inqueue));
  memset(relax, 0, sizeof(relax));
  memset(dist, 0x3f, sizeof(dist));
  dist[u] = 0;
  inqueue[u] = 1;
  for (q.push(u); q.size(); ) {
    inqueue[u = q.top()] = 0, q.pop();
    for (int e = L[u]; ~e; e = E[e].to) {
      int v = E[e].v, w = E[e].w;
      if (dist[v] <= dist[u]+w) continue;
      dist[v] = dist[u]+w;
      if (dist[v] >= limit[v]) continue;
      bound[v] = min(bound[v], dist[v]);
      if (!relax[v]) {
        result++;
        relax[v] = 1;
      }
      if (!inqueue[v]) {
        q.push(v);
        inqueue[v];
      }
    }
  }
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    for (int i = 0; i < n; i++) scanf("%d", r+i);
    init();
    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      u--, v--;
      badd(u, v, w);
    }
    result = 0;
    memset(limit, 0x3f, sizeof(limit));
    for (int rank = 10; rank; rank--) {
      memset(bound, 0x3f, sizeof(bound));
      for (int u = 0; u < n; u++)
        if (rank == r[u]) spfa(u);
      for (int u = 0; u < n; u++)
        limit[u] = min(limit[u], bound[u]);
    }
    for (int i = 0; i < n; i++) printf("limit[%d]=%d\n", i, limit[i]);
    printf("%d\n", result);
  }
  return 0;
}
