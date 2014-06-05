#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 5e5+10;
typedef long long LL;
const LL inf = 0x7f7f7f7f7f7f7f7f;

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

struct st_t {
  int u, e;
  st_t(int _u = 0, int _e = 0): u(_u), e(_e) {}
} st[N];
int vis[N], ra[N];
LL f[N], g[N];
void dfs(int u) {
  int top = 0;
  st[++top] = st_t(u, L[u]);
  for ( ; top; ) {
    int u = st[top].u, &e = st[top].e;
    if (e == L[u]) {
      vis[u] = 1;
      f[u] = g[u] = -inf;
    }
    for ( ; ~e; e = E[e].to)
      if (!vis[E[e].v]) break;
    if (~e) {
      int v = E[e].v;
      ra[v] = e^1;
      st[++top] = st_t(v, L[v]);
      e = E[e].to;
    } else {
      for (e = L[u]; ~e; e = E[e].to)
        if (e != ra[u]) {
          int v = E[e].v;
          LL w = E[e].w;
          if (f[v] == -inf) f[v] = w;
          else f[v] = max(w, f[v]+w);
          if (f[u] == -inf) {
            f[u] = f[v];
            g[u] = g[v];
          } else {
            g[u] = max(g[u], g[v]);
            g[u] = max(g[u], f[u]+f[v]);
            f[u] = max(f[u], f[v]);
          }
        }
      g[u] = max(g[u], f[u]);
      top--;
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
      add(--u, --v, w);
      add(v, u, w);
    }
    LL mx = -inf;
    memset(ra, -1, sizeof(ra));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
      if (!vis[i]) {
        dfs(i);
        mx = max(mx, g[i]);
      }
    cout << mx << endl;
  }
  return 0;
}
