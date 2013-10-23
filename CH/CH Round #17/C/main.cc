#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 2e4+10;
const int P = 1e5+10;

struct graph_t {
  struct edge_t {
    int v, to, w, id;
  };
  vector<edge_t> e;
  vector<int> h;
  edge_t &operator [] (int x) {
    return e[x];
  }
  int &operator () (int x) {
    return h[x];
  }
  int size() {
    return h.size();
  }
  void init(int n) {
    e.clear(), h.resize(n);
    fill(h.begin(), h.end(), -1);
  }
  void add(int u, int v, int w = 0, int id = -1) {
    edge_t t = {v, h[u], w, id};
    h[u] = e.size();
    e.push_back(t);
  }
  void badd(int u, int v, int w = 0, int id = -1) {
    add(u, v, w, id);
    add(v, u, 0, id);
  }
};

struct sap_t {
  vector<int> dis, gap;
  int dfs(graph_t &g, int src, int snk, int u, int f = ~1u>>1) {
    if (u == snk) return f;
    int rf = f, md = g.size()-1;
    for (int e = g(u); ~e; e = g[e].to) {
      int v = g[e].v, w = g[e].w;
      if (!w) continue;
      md = min(md, dis[v]);
      if (dis[u] != dis[v]+1) continue;
      int df = dfs(g, src, snk, v, min(w, f));
      g[e].w -= df, g[e^1].w += df;
      if (gap[src] == g.size() || !(rf -= df)) return f;
    }
    if (!--gap[dis[u]]) gap[src] = g.size();
    else gap[dis[u] = md+1]++;
    return f-rf;
  }
  int operator () (graph_t &g, int src, int snk) {
    dis.clear(), gap.clear();
    for (int i = g.size()<<1; i; i--)
      dis.push_back(-1), gap.push_back(0);
    vector<int> q(gap[dis[snk] = 0] = 1, snk);
    for (int h = 0; h < q.size(); h++)
      for (int e = g(q[h]); ~e; e = g[e].to)
        if (g[e^1].w && !~dis[g[e].v])
          gap[dis[g[e].v] = dis[q[h]]+1]++, q.push_back(g[e].v);
    for (int i = 0; i < g.size(); i++)
      if (!~dis[i]) gap[dis[i] = 0]++;
    int result = 0;
    for ( ; gap[src] < g.size(); ) result += dfs(g, src, snk, src);
    return result;
  }
};

struct scc_t {
  int time, cc;
  vector<int> dfn, low, in, pushed, st;
  void dfs(graph_t &g, int u) {
    st.push_back(u), pushed[u] = 1;
    dfn[u] = low[u] = time++;
    for (int e = g(u); ~e; e = g[e].to) {
      int v = g[e].v;
      if (!~dfn[v]) dfs(g, v), low[u] = min(low[u], low[v]);
      else if (pushed[v]) low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
      for ( ; ; ) {
        in[u = st.back()] = cc;
        st.pop_back(), pushed[u] = 0;
        if (dfn[u] == low[u]) break;
      }
      cc++;
    }
  }
  void operator () (graph_t &g) {
    dfn.clear(), low.clear(), in.clear(), pushed.clear(), st.clear();
    for (int i = 0; i < g.size(); i++)
      dfn.push_back(-1), low.push_back(-1), in.push_back(-1), pushed.push_back(0);
    for (int u = time = cc = 0; u < g.size(); u++)
      if (!~dfn[u]) dfs(g, u);
  }
};

struct pair_t {
  int x, y, b;
  void input() {
    scanf("%d%d", &x, &y);
    b = 0;
  }
};

scc_t scc;
sap_t sap;
graph_t g[2];
pair_t p[P];
int n, m, t;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d", &n, &m, &t); ) {
    for (int i = 0; i < t; i++) {
      p[i].input();
      p[i].x += -1;
      p[i].y += n-1;
    }
    int src = n+m, snk = src+1;
    g[0].init(snk+1);
    for (int i = 0; i < n; i++) g[0].badd(src, i, 1);
    for (int i = 0; i < m; i++) g[0].badd(n+i, snk, 1);
    for (int i = 0; i < t; i++) g[0].badd(p[i].x, p[i].y, 1, i);
    sap(g[0], src, snk);
    g[1].init(snk+1);
    for (int u = 0; u < g[0].size(); u++)
      for (int e = g[0](u); ~e; e = g[0][e].to) {
        if (!g[0][e].w && ~g[0][e].id && ~e&1) p[g[0][e].id].b = 1;
        if (g[0][e].w) g[1].add(u, g[0][e].v);
        else g[1].add(g[0][e].v, u);
      }
    scc(g[1]);
    vector<int> result;
    for (int i = 0; i < t; i++)
      if (!(p[i].b || scc.in[p[i].x] == scc.in[p[i].y]))
        result.push_back(i);
    printf("%d\n", (int)result.size());
    for (int i = 0; i < result.size(); i++)
      printf("%d%c", result[i]+1, i < result.size()-1? ' ': '\n');
  }
  return 0;
}
