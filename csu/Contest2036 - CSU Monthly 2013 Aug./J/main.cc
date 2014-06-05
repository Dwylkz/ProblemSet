#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 2e3+10;
const int inf = 0x7f7f7f7f;

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

struct spfa_t {
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
} spfa;

int n, m, a, b, g[N][N];

bool check(int m) {
  init();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (g[i][j] <= m) add(i, j, g[i][j]);
  spfa(E, L, n, a);
  return spfa.d[b] != inf;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d%d", &n, &m, &a, &b); ) {
    a--, b--;
    memset(g, 0x7f, sizeof(g));
    for ( ; m--; ) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      u--, v--;
      g[u][v] = g[v][u] = w;
    }
#if 0
    printf("L = %d, R = %d\n", L, R);
#endif
    int L = 0, R = 1e5+10;
    for ( ; L < R; ) {
      int m = L+R>>1;
      if (check(m)) R = m;
      else L = m+1;
    }
    check(L);
#if 0
    printf("ub = %d\n", L);
#endif
    printf("%d\n", spfa.d[b]);
  }
  return 0;
}
