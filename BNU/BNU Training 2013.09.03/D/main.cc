#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int N = 1e4+10;
const int M = 1e3+10;

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
    gap[dis[snk] = 0] = V;  
//     vector<int> q(1, snk);
//     for (int h = 0; h < q.size(); h++)
//       for (int i = L[q[h]]; i != -1; i = E[i].to)
//         if (E[i].w && dis[E[i].v] < 0) {
//           gap[dis[E[i].v] = dis[q[h]]+1]++;
//           q.push_back(E[i].v);
//         }
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

int n, m, t[N], p[N], g[M][M];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int blank = 0; ~scanf("%d%d", &n, &m), n||m; blank = 1) {
    if (blank) puts("");
    int st = 0, sp = 0, no = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", t+i);
      if (t[i] > m) no = 1;
      st += t[i];
    }
    for (int i = 0; i < m; i++) {
      scanf("%d", p+i);
      if (p[i] > n) no = 1;
      sp += p[i];
    }
    if (st != sp || no) {
      puts("Impossible");
      continue;
    }
    int src = n+n*m+m, snk = src+1;
    init();
    for (int i = 0; i < n; i++) {
      badd(src, i, t[i]);
      for (int j = 0; j < m; j++) {
        badd(i, n+i*m+j, 1);
        badd(n+i*m+j, n+n*m+j, 1);
      }
    }
    for (int i = 0; i < m; i++) badd(n+n*m+i, snk, p[i]);
    if (sap(E, L, snk+1, src, snk) == sp) {
      memset(g, 0, sizeof(g));
      for (int u = 0; u < n; u++)
        for (int e = L[u]; ~e; e = E[e].to)
          if (~e&1 && !E[e].w) g[u][(E[e].v-n)%m] = 1;
#if 0
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
          putchar(g[i][j]? 'Y': 'N');
        puts("");
      }
      puts("--------------------");
#endif
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (g[i][j]) {
            for (int r = i+1; r < n; r++)
              if (!g[r][j]) {
                for (int c = j+1; c < m; c++)
                  if (j != c && !g[i][c] && g[r][c]) {
                    swap(g[i][j], g[r][j]);
                    swap(g[i][c], g[r][c]);
                    goto here;
                  }
              }
here: ;
          }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
          putchar(g[i][j]? 'Y': 'N');
        puts("");
      }
    } else puts("Impossible");
  }
  return 0;
}
