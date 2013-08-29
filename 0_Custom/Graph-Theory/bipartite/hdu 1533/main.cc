#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;
const int N = 500+10;
const int inf = 0x3f3f3f3f;

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

struct km_t {
  vector<edge_t> E;
  typedef int kmia_t[N];
  kmia_t mat, lta, rta, sla, lvi, rvi;
  int n, *L;
  int dfs(int u) {
    lvi[u] = 1;
    for (int e = L[u]; ~e; e = E[e].to) {
      int v = E[e].v, w = E[e].w;
      if (!rvi[v]) {
        int t = lta[u]+rta[v]-w;
        if (!t) {
          rvi[v] = 1;
          if (mat[v] == -1 || dfs(mat[v])) {
            mat[v] = u;
            return 1;
          }
        } else if (t < sla[v]) sla[v] = t;
      }
    }
    return 0;
  }
  int operator () (vector<edge_t> &_E, int _L[N], int _n) {
    E = _E, L = _L, n = _n;
    memset(lta, 0, sizeof(lta));
    memset(rta, 0, sizeof(rta));
    memset(mat, -1, sizeof(mat));
    for (int u = 0; u < n; u++)
      for (int e = L[u]; ~e; e = E[e].to)
        if (lta[u] < E[e].w) lta[u] =  E[e].w;
    for (int u = 0; u < n; u++) {
      for (int e = L[u]; ~e; e = E[e].to) sla[E[e].v] = inf;
      for ( ; ; ) {
        memset(lvi, 0, sizeof(lvi));
        memset(rvi, 0, sizeof(rvi));
        if (dfs(u)) break;
        int mn = inf;
        for (int v = 0; v < n; v++)
          if (!rvi[v]) mn = min(mn, sla[v]);
        for (int v = 0; v < n; v++) {
          if (lvi[v]) lta[v] -= mn;
          if (rvi[v]) rta[v] += mn;
          else sla[v] -= mn;
        }
      }
    }
    int rv = 0;
    for (int v = 0; v < n; v++) if (~mat[v])
        for (int e = L[mat[v]]; ~e; e = E[e].to)
          if (E[e].v == v) {
            rv += E[e].w;
            break;
          }
    return rv;
  }
} km;

vector<int> M, H;
int n, m, h;

void G_init()
{
  int w;
  h = H.size();
  init();
  for (int u = 0; u < h; u++)
    for (int v = 0; v < h; v++)
    {
      int w = abs(M[u] / m - H[v] / m) + abs(M[u] % m - H[v] % m);
      add(u, v, -w);
    }
}


int main() {
#if 1
  freopen("input.in", "rt", stdin);
#endif
  char buf[N];

  while (scanf("%d%d", &n, &m), n || m) {
    H.clear();
    M.clear();
    for (int i = 0; i < n; i++) {
      scanf("%s", buf);
      for (int j = 0; j < m; j++) {
        if (buf[j] == 'H') H.push_back(i * m + j);
        if (buf[j] == 'm') M.push_back(i * m + j);
      }
    }
    G_init();
    printf("%d\n", -km(E, L, h));
  }

  return 0;
}
