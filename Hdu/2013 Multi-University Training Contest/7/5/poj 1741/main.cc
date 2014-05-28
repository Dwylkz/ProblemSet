#if 1|include
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#endif
using namespace std;
namespace dwylkz {
#define _fl(c, a, b) for (int c = (a); c < (b); c++)
#define _fln(c, a, b, n) for (int c = (a); c < (b); c += (n))
#define _rfl(c, a, b) for (int c = (a)-1; (b) <= c; c--)
#define _rfln(c, a, b, n) for (int c = (a)-1; (b) <= c; c -= (n))
#define _ms(c, a) memset((c), (a), sizeof(c))
#define _mc(c, a) memcpy((c), (a), sizeof(a))
#define _sl(c) strlen(c)
#define _sfl(c, a) for (char *c = (a); *c; c++)
#define _rsort(c, a, b) sort((c), (a), greater<b>())
#define _it(c) c::iterator
#define _itfl(c, a, b) for (_it(c) a = (b).begin(); a != (b).end(); a++)
#define _sz(c) ((int)c.size())
#define _ep(c) (c).empty()
#define _pub push_back
#define _pob pop_back
#define _lob lower_bound
#define _upb upper_bound
#define _uni(c, a) unique((c), (a))
#define _pt(x...) fprintf(stderr,""x)
#define _flpt(h, c, a, b, x...) {\
  _pt(h);\
  _fl(c, (a), (b)) _pt(x);\
  _pt("\n");\
}
#define _itflpt(h, c, a, b, x...) {\
  _pt(h);\
  _itfl(c, (a), (b)) _pt(x);\
  _pt("\n");\
}
#define _wait(x...) for( ; x; )
#define _ls(x, y) ((x)<<(y))
#define _rs(x, y) ((x)>>(y))
#define _gb(x, y) (_rs((x), (y))&1)
#define _sb(x, y) ((x)|_ls(1, (y)))
#define _cb(x, y) ((x)&~_ls(1, (y)))
#define _lb(x) (-x&x)
  const int N = 2e4+10;
  const int MOD = 1e9+7;
  const double EPS = 1e-8;
  typedef long long LL;
  typedef unsigned long long ULL;
  typedef unsigned char UC;
  typedef int IA[N];
  typedef char CA[N];
  typedef LL LLA[N];
  typedef map<int, int> MII;
  typedef map<string, int> MSI;
  typedef vector<int> VI;
  typedef vector<string> VS;
}
using namespace dwylkz;
namespace graph {
#define _efl(c, a, L, E) for (int c = (L)[a]; c != -1; c = (E)[c].to)
#define _refl(c, a, L, E) for (int &c = (L)[a]; c != -1; c = (E)[c].to)
  struct edge {
    int v, to, w;
  };
  struct vertice {
    int sz, b;
  };
  typedef vector<vertice> VV;
  typedef vector<edge> VE;
  VV V;
  VE E;
  VI L;
  void init(int n)
  {
    E.clear();
    L = VI(n, -1);
    V = VV(n);
  }
  void add(int u, int v, int w)
  {
    edge t = {v, L[u], w};
    L[u] = _sz(E);
    E._pub(t);
  }
}
using namespace graph;

int n, k;

VI vis, dis;
int heart;
int dfs_size(int u = 0)
{
  vis[u] = V[u].sz = 1;
  _efl(i, u, L, E) if (!vis[E[i].v]) 
    V[u].sz += dfs_size(E[i].v);
  vis[u] = 0;
  return V[u].sz;
}
void dfs_heart(int u = 0, int f = -1)
{
  vis[u] = 1;
  V[u].b = 0;
  if (f != -1) {
    V[u].b = max(V[u].b, V[f].sz-V[u].sz);
    V[u].sz += V[f].sz-V[u].sz;
  }
  _efl(i, u, L, E) if (!vis[E[i].v]) {
    V[u].b = max(V[u].b, V[E[i].v].sz);
    dfs_heart(E[i].v, u);
  }
  if (V[heart].b > V[u].b) heart = u;
  vis[u] = 0;
}
void dfs_dis(int u, int rd = 0)
{
  vis[u] = 1;
  dis._pub(rd);
  _efl(i, u, L, E) if (!vis[E[i].v])
    dfs_dis(E[i].v, rd+E[i].w);
  vis[u] = 0;
}
int count(int u, int d)
{
  int rv = 0;
  dis.clear();
  dfs_dis(u, d);
  sort(dis.begin(), dis.end());
  for (int i = 0, j = _sz(dis)-1; i < j; i++) {
    for ( ; i < j && dis[i]+dis[j] > k; j--) {}
    rv += j-i;
  }
  return rv;
}
int dac(int u = 0)
{
  int rv = 0;
  dfs_size(heart = u);
  dfs_heart(u);
  u = heart;
  rv += count(u, 0);
  vis[u] = 1;
  _efl(i, u, L, E) if (!vis[E[i].v])
    rv += dac(E[i].v) - count(E[i].v, E[i].w);
  vis[u] = 0;
  return rv;
}

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &k), n||k; ) {
    init(n);
    _fl(i, 0, n-1) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      u--, v--;
      add(u, v, w);
      add(v, u, w);
    }
    vis = VI(n, 0);
    printf("%d\n", dac());
  }
  return 0;
}
