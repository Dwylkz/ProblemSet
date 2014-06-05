#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int INF = ~1u>>1;
const int N = 5e3+10;
const int M = 1e2+10;
const int V = N+M;

struct edge_t {
  int v, to, w;
};
vector<edge_t> E;
int L[V];
void init() {
  E.clear();
  memset(L, -1, sizeof(L));
}
void add(int u, int v, int w) {
  edge_t t = {v, L[u], w};
  L[u] = E.size();
  E.push_back(t);
}
void badd(int u, int v, int w) {
  add(u, v, w);
  add(v, u, 0);
}

int dis[V], head[V];
int bfs(int src, int snk) {
  memset(dis, -1, sizeof(dis));
  vector<int> q(1, snk);
  dis[snk] = 0;
  for (int i = 0; i < q.size(); i++)
    for (int e = L[q[i]]; ~e; e = E[e].to)
      if (E[e^1].w && !~dis[E[e].v]) {
        dis[E[e].v] = dis[q[i]]+1;
        q.push_back(E[e].v);
      }
  return ~dis[src];
}
int dfs(int u, int f, int snk) {
  if (u == snk) return f;
  int rf = f;
  for (int &e = head[u]; ~e; e = E[e].to) {
    int v = E[e].v, &w = E[e].w;
    if (w && dis[u] == dis[v]+1) {
      int df = dfs(v, min(rf, w), snk);
      w -= df;
      E[e^1].w += df;
      if (!(rf -= df)) break;
    }
  }
  return f-rf;
}
int dinic(int src, int snk) {
  int result = 0;
  while (bfs(src, snk)) {
    memcpy(head, L, sizeof(L));
    result += dfs(src, INF, snk);
  }
  return result;
}

int n, m, c[N], h[M];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    memset(h, 0, sizeof(h));
    for (int i = 0; i < n; i++) {
      scanf("%d", c+i);
      h[--c[i]]++;
    }
    init();
    int src = n+m, snk = src+1;
    for (int i = 0; i < n; i++) {
      badd(src, i, 1);
      for (int j = 0; j < m; j++)
        if (c[i] != j) badd(i, n+j, 1);
    }
    for (int i = 0; i < m; i++)
      badd(n+i, snk, h[i]);
    printf("%d\n", dinic(src, snk));
    for (int i = 0; i < n; i++) {
      int r = c[i];
      for (int e = L[i]; ~e; e = E[e].to)
        if ((~e&1) && !E[e].w) r = E[e].v-n;
      printf("%d %d\n", c[i]+1, r+1);
    }
  }
  return 0;
}
