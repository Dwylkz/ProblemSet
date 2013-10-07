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
    int v, to, w, id;
  };
  vector<edge_t> E;
  int L[N];
  void init() {
    E.clear();
    memset(L, -1, sizeof(L));
  }
  void add(int u, int v, int w, int id) {
    edge_t t = {v, L[u], w, id};
    L[u] = E.size();
    E.push_back(t);
  }
  void badd(int u, int v, int w, int id = -1) {
    add(u, v, w, id);
    add(v, u, 0, id);
  }
};
typedef graph_t<N> graph_i;
typedef graph_i::edge_t edge_t;

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
typedef sap_t<edge_t, N> sap_i;

template<class edge_t, int N> struct scc_t {
  typedef int ia_t[N];
  int time, V, *L, cc;
  ia_t dfn, low, in, pushed;
  vector<edge_t> *E;
  vector<int> st;
  void dfs(int u) {
    dfn[u] = low[u] = time++;
    st.push_back(u);
    pushed[u] = 1;
    for (int e = L[u]; ~e; e = (*E)[e].to) {
      int v = (*E)[e].v;
      if (~dfn[v] && pushed[v]) low[u] = min(low[u], dfn[v]);
      else dfs(v), low[u] = min(low[u], low[v]);
    }
    if (dfn[u] == low[u]) {
      for ( ; ; ) {
        u = st.back();
        st.pop_back();
        pushed[u] = 0;
        in[u] = cc;
        if (dfn[u] == low[u]) break;
      }
      cc++;
    }
  }
  void operator () (vector<edge_t> *_E, int *_L, int _V) {
    E = _E;
    L = _L;
    V = _V;
    for (int i = 0; i < V; i++)
      dfn[i] = low[i] = -1, pushed[i] = 0;
    st.clear();
    time = cc = 0;
    for (int u = 0; u < V; u++) dfs(u);
  }
};
typedef scc_t<edge_t, N> scc_i;

scc_i scc;
graph_i graph;
vector<edge_t> &E = graph.E;
int *L = graph.L;
sap_i sap;
ppi_t p[P];
int n, m, t;
vector<int> g[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d", &n, &m, &t); ) {
    for (int i = 0; i < t; i++) {
      scanf("%d%d", &p[i]._x, &p[i]._y);
      p[i]._x -= 1;
      p[i]._y += n-1;
      p[i]._b = 0;
    }
    int src = n+m, snk = src+1, V = snk+1;
    graph.init();
    for (int i = 0; i < n; i++) graph.badd(src, i, 1);
    for (int i = 0; i < m; i++) graph.badd(n+i, snk, 1);
    for (int i = 0; i < t; i++) {
      int u = p[i]._x, v = p[i]._y;
      graph.badd(u, v, 1, i);
    }
    sap(graph.E, graph.L, V, src, snk);
    for (int u = 0; u < V; u++) g[u].clear();
    for (int u = 0; u < V; u++)
      for (int e = L[u]; ~e; e = E[e].to) {
        if (~E[e].id && (~e&1) && !E[e].w) p[E[e].id]._b = 1;
        if (E[e].w) g[u].push_back(E[e].v);
        else g[E[e].v].push_back(u);
      }
    graph.init();
    for (int u = 0; u < V; u++)
      for (int i = 0; i < g[u].size(); i++)
        graph.add(u, g[u][i], 0, -1);
    scc(&graph.E, L, V);
    vector<int> result;
    for (int i = 0; i < t; i++)
      if (!(p[i]._b || scc.in[p[i]._x] == scc.in[p[i]._y]))
        result.push_back(i);
    printf("%d\n", (int)result.size());
    for (int i = 0; i < result.size(); i++)
      printf("%d%c", result[i]+1, result.size()? ' ': '\n');
    if(!result.size()) puts("");
  }
  return 0;
}
