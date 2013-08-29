#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3+10;

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

struct bgm_t {
  int vis[N], pre[N], lma[N], rma[N];
  bool bfs(vector<edge_t> &E, int *L, int u) {
    vector<int> q(1, u);
    memset(vis, 0, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    for (int h = 0; h < q.size(); h++) {
      u = q[h];
      for (int e = L[u]; ~e; e = E[e].to) {
        int v = E[e].v;
        if (!vis[v]) {
          vis[v] = 1;
          if (rma[v] == -1) {
            for ( ; ~u; ) {
              rma[v] = u;
              swap(v, lma[u]);
              u = pre[u];
            }
            return 1;
          } else {
            pre[rma[v]] = u;
            q.push_back(rma[v]);
          }
        }
      }
    }
    return 0;
  }
  int operator () (vector<edge_t> &E, int *L, int V) {
    int mmat = 0;
    memset(lma, -1, sizeof(lma));
    memset(rma, -1, sizeof(rma));
    for (int u = 0; u < V; u++)
      mmat += bfs(E, L, u);
    return mmat;
  }
} bgm;

int k, n, m;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d", &k, &m, &n), k; ) {
    init();
    for (int i = 0; i < k; i++) {
      int u, v;
      scanf("%d%d", &u, & v);
      u--, v--;
      add(u, v+m);
      add(v+m, u);
    }
    printf("%d\n", bgm(E, L, m));
  }
  return 0;
}
