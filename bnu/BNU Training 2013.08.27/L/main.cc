#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 402+10;

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
void badd(int u, int v, int w) {
  add(u, v, w), add(v, u, 0);
}

struct sap_t {
  int dis[N], gap[N], _L[N], se[N];
  int operator () (vector<edge_t> &E, int *L, int V, int src, int snk) {
    int mxf = 0, te = 0;
    memcpy(_L, L, sizeof(L));  
    memset(dis, -1, sizeof(dis));
    memset(gap, 0, sizeof(gap));  
    gap[dis[snk] = 0] = 1;  
    vector<int> q(1, snk);
    for (int h = 0; h < q.size(); h++)
      for (int i = L[q[h]]; i != -1; i = E[i].to)
        if (E[i].w && dis[E[i].v] < 0) {
          gap[dis[E[i].v] = dis[q[h]]+1]++;
          q.push_back(E[i].v);
        }
    for (int u = src; dis[src] < V; ) {
      for (int &i = _L[u]; i != -1; i = E[i].to)
        if (E[i].w && dis[u] == dis[E[i].v] + 1) break;  
      if (_L[u] != -1) {
        u = E[se[te++] = _L[u]].v;
        if (u == snk) {
          int _i = 0, mf = 0x7fffffff;
          for (int i = 0; i < te; i++)
            if (E[se[i]].w < mf) {
              mf = E[se[i]].w;
              _i = i;
            }
          for (int i = 0; i < te; i++) {
            E[se[i]].w -= mf;
            E[se[i]^1].w += mf;
          }
          mxf += mf;
          u = E[se[te = _i]^1].v;
        }
        continue;
      }
      int md = V;
      _L[u] = -1;
      for (int i = L[u]; i != -1; i = E[i].to)
        if (E[i].w && dis[E[i].v] < md) {
          md = dis[E[i].v];
          _L[u] = i;
        }
      if (!--gap[dis[u]]) break;
      gap[dis[u] = md+1]++;
      if (u != src) u = E[se[te---1]^1].v;
    }
    return mxf;
  }
} sap;

int n, m;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    init();
    for (int i = 0; i < n; i++) {
      badd(n+m, i, 1);
      int j;
      scanf("%d", &j);
      for ( ; j--; ) {
        int u;
        scanf("%d", &u);
        badd(i, n+u-1, 1);
      }
    }
    for (int i = 0; i < m; i++) badd(n+i, n+m+1, 2);
    if (sap(E, L, n+m+2, n+m, n+m+1) == m*2) {
      puts("YES");
      for (int i = 0; i < m; i++) {
        printf("2");
        for (int e = L[n+i]; ~e; e = E[e].to)
          if (E[e].w) printf(" %d", E[e].v+1);
        puts("");
      }
    } else puts("NO");
  }
  return 0;
}
