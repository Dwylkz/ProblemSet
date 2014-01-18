#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e4+10;
const int D = 10+10;
const int oo = 0x3f3f3f3f;

struct Edge {
  int v, to, w, b;
};
vector<Edge> E;
int L[N];
void init() {
  E.clear();
  memset(L, -1, sizeof(L));
}
void add(int u, int v, int w, int b) {
  Edge t = {v, L[u], w, b};
  L[u] = E.size();
  E.push_back(t);
}

int n, m, k, d;

int dis[N][D], inQ[N];
void spfa() {
  vector<int> q(1, 0);
  memset(inQ, 0, sizeof(inQ));
  memset(dis, 0x3f, sizeof(dis));
  dis[0][0] = 0;
  inQ[0] = 1;
  for (int h = 0; h < q.size(); h++) {
    int u = q[h];
    inQ[u] = 0;
    for (int e = L[u]; ~e; e = E[e].to) {
      int v = E[e].v, w = E[e].w, b = E[e].b; 
      for (int i = 0; i <= d; i++) {
        if (dis[v][i+b]-w > dis[u][i]) {
          dis[v][i+b] = dis[u][i]+w;
          if (!inQ[v]) {
            inQ[v] = 1;
            q.push_back(v);
          }
        }
      }
    }
  }
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int ks = 1; ks <= T; ks++) {
    printf("Case %d: ", ks);
    scanf("%d%d%d%d", &n, &m, &k, &d);
    init();
    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      add(u, v, w, 0);
    }
    for (int i = 0; i < k; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      add(u, v, w, 1);
    }
    spfa();
    int ret = oo;
    for (int i = 0; i <= d; i++)
      ret = min(ret, dis[n-1][i]);
    if (ret != oo) printf("%d\n", ret);
    else puts("Impossible");
  }
  return 0;
}

