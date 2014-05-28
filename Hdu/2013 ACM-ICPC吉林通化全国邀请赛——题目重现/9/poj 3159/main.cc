#include <cstdio>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 3e4+10;
const int inf = 0x7fffffff;

struct edge_t {
  int v, to, w;
};
vector<edge_t> E;
int L[N];
void init() {
  E.clear();
  memset(L, -1, sizeof(L));
}
void add(int u, int v, int w) {
  edge_t t = {v, L[u], w};
  L[u] = E.size();
  E.push_back(t);
}

int n, m;

int dis[N], inq[N];
void spfa(int u) {
  stack<int> q;
  q.push(u);
  dis[u] = 0;
  inq[u] = 1;
  for ( ; q.size(); ) {
    u = q.top();
    q.pop();
    inq[u] = 0;
    for (int e = L[u]; ~e; e = E[e].to) {
      int v = E[e].v, w = E[e].w;
      if (dis[v]-w <= dis[u]) continue;
      dis[v] = dis[u]+w;
      if (!inq[v]) {
        inq[v] = 1;
        q.push(v);
      }
    }
  }
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    init();
    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      add(u, v, w);
    }
    for (int u = 1; u <= n; u++) {
      dis[u] = inf;
      inq[u] = 0;
    }
    spfa(1);
    printf("%d\n", dis[n]);
  }
  return 0;
}
