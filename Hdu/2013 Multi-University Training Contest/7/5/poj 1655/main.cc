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
#define _flpt(c, a, b, x...) {\
  _fl(c, (a), (b)) _pt(x);\
  _pt("\n");\
}
#define _itflpt(c, a, b, x...) {\
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
    int v, to;
  };
  struct vertice {
    int sz, fp, b;
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
  void add(int u, int v)
  {
    edge t = {v, L[u]};
    L[u] = _sz(E);
    E._pub(t);
  }
}
using namespace graph;

int n;

int dfs_size(int u = 0, int p = -1)
{
  V[u].sz = 1;
  V[u].fp = p<0? -1: E[p].v;
  _efl(i, u, L, E) if (i != p) 
    V[u].sz += dfs_size(E[i].v, i^1);
  return V[u].sz;
}
int mx;
void dfs_heart(int u = 0, int p = -1)
{
  V[u].b = 0;
  if (p != -1) {
    V[u].b = max(V[u].b, V[E[p].v].sz-V[u].sz);
    V[u].sz += V[E[p].v].sz-V[u].sz;
  }
  _efl(i, u, L, E) if (i != p) {
    V[u].b = max(V[u].b, V[E[i].v].sz);
    dfs_heart(E[i].v, i^1);
  }
  if (V[mx].b > V[u].b) mx = u;
}

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  for (scanf("%d", &T); T--; ) {
    scanf("%d", &n);
    init(n);
    _fl(i, 0, n-1) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      add(u, v);
      add(v, u);
    }
    mx = 0;
    dfs_size();
    dfs_heart();
    printf("%d %d\n", mx+1, V[mx].b);
  }
  return 0;
}
