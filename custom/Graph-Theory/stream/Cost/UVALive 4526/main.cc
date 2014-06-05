#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N = 4000+10;
const int inf = 0x7fffffff;

struct edge_t {
  int v, w, c, to;
};
vector<edge_t> E;
int L[N];

void G_ini()
{
  E.clear();
  memset(L, -1, sizeof L);
}

void AE(int u, int v, int w, int c)
{
  edge_t te = {v, w, c, L[u]};
  L[u] = E.size();
  E.push_back(te);
}

struct zkw_t {
  vector<edge_t> E;
  int n, src, snk, mc, mf, dis, vis[N], *L;
  int ap(int u, int f) {
    if (u == snk) {
      mc += dis*f;
      mf += f;
      return f;
    }
    vis[u] = 1;
    int rf = f;
    for (int e = L[u]; e > -1; e = E[e].to)
      if (!vis[E[e].v] && E[e].w && !E[e].c) {
        int df = ap(E[e].v, min(rf, E[e].w));
        E[e].w -= df;
        E[e^1].w += df;
        rf -= df;
        if (!rf) return f;
      }
    return f-rf;
  }
  int ml() {
    int md = inf;
    for (int u = 0; u < n; u++) if (vis[u])
      for (int e = L[u]; ~e; e = E[e].to)
        if (!vis[E[e].v] && E[e].w)
          md = min(md, E[e].c);
    if (md == inf) return 0;
    for (int u = 0; u < n; u++) if (vis[u])
      for (int e = L[u]; ~e; e = E[e].to) {
        E[e].c -= md;
        E[e^1].c += md;
      }
    dis += md;
    return 1;
  }
  int operator () (vector<edge_t> &_E, int *_L, int _n, int _src, int _snk) {
    E = _E, L = _L, n = _n;
    src = _src, snk = _snk;
    mf = mc = dis = 0;
    for ( ; ; ) {
      for ( ; ; ) {
        memset(vis, 0, sizeof vis);
        if (!ap(src, inf)) break;
      }
      if (!ml()) break;
    }
    return mc;
  }
} zkw;

int n;

int main()
{
#if 1
  freopen("input.in", "rt", stdin);
#endif

  int Cas, pi, di, ni;

  scanf("%d", &Cas);
  while (Cas--)
  {
    G_ini();
    scanf("%d", &n);
    int V = 3 * n + 2, src = 3 * n, snk = src + 1;
    for (int i = 0; i < n; i++)
    {
      int num = 3 * i, fpr = num + 1, fsr = fpr + 1, nfp = num + 4;
      scanf("%d%d%d", &pi, &ni, &di);
      AE(src, fsr, ni, pi);
      AE(fsr, src, 0, -pi);
      AE(fpr, num, inf, 0);
      AE(num, fpr, 0, 0);
      AE(fsr, num, inf, 0);
      AE(num, fsr, 0, 0);
      AE(num, snk, di, 0);
      AE(snk, num, 0, 0);
      if (i == n - 1) continue;
      AE(fsr, nfp, inf, 0);
      AE(nfp, fsr, 0, 0);
    }
    printf("%d\n", zkw(E, L, V, src, snk));
  }

  return 0;
}

