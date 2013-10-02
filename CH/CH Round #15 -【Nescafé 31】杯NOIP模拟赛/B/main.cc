#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 3e4+10;

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
};
/* Shortest Path Fast Algorithm && Heap Dijkstra
 * */
template<class edge_t, int N> struct spfa_t {
  int d[N], b[N], c[N], s[N], mx[N];
  int operator () (vector<edge_t> &E, int *L, int n, int u) {
    memset(d, 0x7f, sizeof(d));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    d[s[s[0] = 1] = u] = 0;
    b[u] = c[u] = 1;
    for ( ; s[0]; ) {
      b[u = s[s[0]--]] = 0;
      for (int e = L[u]; ~e; e = E[e].to) {
        int v = E[e].v, w = E[e].w;
        if (d[v]-w > d[u]) {
          d[v] = d[u]+w;
          if (!b[v]) {
            if ((c[v] += b[v] = 1) > n) return 0;
            s[++s[0]] = v;
          }
        }
      }
    }
    return 1;
  }
  struct node {
    int u, w;
    node (int _u = 0, int _w = 0): u(_u), w(_w) {}
    friend bool operator < (const node &lhs, const node &rhs) {
      return lhs.w > rhs.w;
    }
  };
  void operator () (vector<edge_t> &E, int *L, int u) {
    memset(d, 0x7f, sizeof(d));
    memset(b, 0, sizeof(b));
    priority_queue<node> q;
    for (q.push(node(u, d[u] = 0)); q.size(); ) {
      u = q.top().u, q.pop();
      if (b[u]++) continue;
      for (int e = L[u]; ~e; e = E[e].to) {
        int v = E[e].v, w = E[e].w;
        if (b[u] && d[v]-w > d[u])
          q.push(node(v, d[v] = d[u]+w));
      }
    }
  }
};

typedef graph_t<N> graph_i;
typedef spfa_t<graph_i::edge_t, N> spfa_i;

struct city_t {
  int d, r;
  city_t(int _d = 0, int _r = 0):
    d(_d), r(_r) {}
  friend bool operator < (const city_t &lhs, const city_t &rhs) {
    return lhs.d == rhs.d? lhs.r < rhs.r: lhs.d < rhs.d;
  }
};

graph_i graph;
spfa_i spfa;
int n, m, r[N];
city_t c[N];


int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    for (int i = 0; i < n; i++) scanf("%d", r+i);
    graph.init();
    for (int i = 0; i < m; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      u--, v--;
      graph.add(u, v, w);
      graph.add(v, u, w);
    }
    int rv = 0;
    for (int u = 0; u < n; u++) {
      spfa(graph.E, graph.L, u);
      for (int i = 0; i < n; i++)
        c[i] = city_t(spfa.d[i], r[i]);
      sort(c, c+n);
      for (int i = 0, mx = 0; i < n; i++)
        if (mx <= c[i].r) {
          rv++;
          mx = max(mx, c[i].r);
        } else break;
    }
    printf("%d\n", rv);
  }
  return 0;
}
