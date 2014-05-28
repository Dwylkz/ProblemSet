#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e6+10;

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

int n;
int bfs() {
  vector<int> q(1, 0), f(n, 0), g(n, 0), r(n, -1);
  for (int h = 0; h < q.size(); h++) {
    int u = q[h];
    for (int e = L[u]; ~e; e = E[e].to) {
      if (e == r[u]) continue;
      int v = E[e].v;
      r[v] = e^1;
      q.push_back(v);
    }
  }
  for (int h = q.size()-1; h >= 0; h--) {
    int u = q[h], yes = 1;
    f[u] = g[u] = 1;
    for (int e = L[u]; ~e; e = E[e].to) {
      if (e == r[u]) continue;
      int v = E[e].v;
      f[u] = max(f[u], max(f[v], g[u]+g[v]));
      g[u] = max(g[u], g[v]+1);
    }
  }
  return f[0]>>1;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    init();
    for (int u, v, i = 0; i < n-1; i++) {
      scanf("%d%d", &u, &v);
      add(u, v), add(v, u);
    }
    printf("%d\n", bfs());
  }
  return 0;
}
