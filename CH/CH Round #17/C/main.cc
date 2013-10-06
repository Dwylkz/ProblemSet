#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 2e4+10;
const int P = 1e5+10;
typedef pair<pair<int, int>, int> ppi_t;
#define _x first.first
#define _y first.second
#define _b second

/* Graph
 * */
template<int N> struct graph_t {
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
    add(u, v, w);
    add(v, u, 0);
  }
};
typedef graph_t<N> graph_i;

/* Shortest Augment Path
 * */
template<class edge_t, int N> struct sap_t {
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
};
typedef sap_t<graph_i::edge_t, N> sap_i;

graph_i graph;
sap_i sap;
ppi_t p[P];
int n, m, t;

void build(int src, int snk) {
  graph.init();
  for (int i = 0; i < n; i++) graph.badd(src, i, 1);
  for (int i = 0; i < m; i++) graph.badd(i, snk, 1);
  for (int i = 0; i < t; i++) if (p[i]._b) {
    int u = p[i]._x, v = p[i]._y;
    graph.badd(u, v, 1);
  }
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d", &n, &m, &t); ) {
    for (int i = 0; i < t; i++) {
      scanf("%d%d", &p[i]._x, &p[i]._y);
      p[i]._x--, p[i]._y--;
      p[i]._b = 1;
    }
    int src = n+m, snk = src+1, V = snk+1;
    build(src, snk);
    int maxf = sap(graph.E, graph.L, V, src, snk);
    vector<int> result;
    for (int i = 0; i < t; i++) {
      p[i]._b = 0;
      build(src, snk);
      if (sap(graph.E, graph.L, V, src, snk) < maxf-1)
        result.push_back(i);
      p[i]._b = 1;
    }
    printf("%d\n", (int)result.size());
    for (int i = 0; i < result.size(); i++)
      printf("%d%c", result[i]+1, i < result.size()-1? ' ': '\n');
    if (!result.size()) puts("");
  }
  return 0;
}
