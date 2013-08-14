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
#define _bw (2)
#define _bm ((1<<_bw)-1)
#define _ls(x, y) ((x)<<((y)*_bw))
#define _rs(x, y) ((x)>>((y)*_bw))
#define _gb(x, y) (_rs((x), (y))&_bm)
#define _sb(x, y, z) ((x)&~_ls(_bm, (y))|_ls((z), (y)))
#define _lb(x) (-x&x)
#define _mp make_pair
  const int N = 5e4+10;
  const int MOD = 1e9+7;
  const double EPS = 1e-8;
  typedef long long LL;
  typedef unsigned long long ULL;
  typedef unsigned char UC;
  typedef int IA[N];
  typedef char CA[N];
  typedef LL LLA[N];
  typedef map<int, int> MII;
  typedef map<LL, int> MLLI;
  typedef map<string, int> MSI;
  typedef vector<int> VI;
  typedef vector<LL> VLL;
  typedef vector<string> VS;
  typedef pair<int, LL> ILL;
char *lltoa(LL x)
{
  static char ib[20];
  char s = x < 0? (x *= -1, 1): 0, *i = ib;
  for ( ; x; x /= 10) *i++ = x%10+'0';
  if (s) *i++ = '-';
  for (int j = 0, l = _sl(ib); j < l/2; j++)
    swap(ib[j], ib[l-j-1]);
  return ib;
}
}
using namespace dwylkz;
namespace graph {
#define _efl(c, a, L, E) for (int c = (L)[a]; c != -1; c = (E)[c].to)
#define _refl(c, a, L, E) for (int &c = (L)[a]; c != -1; c = (E)[c].to)
  struct edge {
    int v, to;
  };
  struct vertice {
    int sz, b;
    LL p;
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

int n, k;

VLL p;
#define _show(x) _flpt("\t", __i, 0, k, "%lld ", _gb(x, __i));
LL ltt(LL x, LL t = 0)
{
  _fl(j, (t = 0), k) {
    LL o = 0;
    for ( ; !(x%p[j]); x /= p[j]) o++;
    t = _sb(t, j, o%3);
  }
  return t;
}
LL tba(LL lhs, LL rhs)
{
  _fl(i, 0, k) lhs = _sb(lhs, i, (_gb(lhs, i)+_gb(rhs, i))%3);
  return lhs;
}
LL tne(LL x, LL rv = 0)
{
  _fl(i, 0, k) rv = _sb(rv, i, (3-_gb(x, i))%3);
  return rv;
}

VI vis;
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
VLL dis;
void dfs_dis(int u, LL d)
{
  LL sum = tba(V[u].p, d);
#if 0
  _pt("\tin %d\n", u);
  _flpt("\tlhs\t", j, 0, k, "%lld ", _gb(d, j));
  _flpt("\trhs\t", j, 0, k, "%lld ", _gb(V[u].p, j));
  _flpt("\tsum\t", j, 0, k, "%lld%c", _gb(sum, j), j<k-1? ' ': '\n');
#endif
  dis._pub(sum);
  vis[u] = 1;
  _efl(i, u, L, E) if (!vis[E[i].v])
    dfs_dis(E[i].v, sum);
  vis[u] = 0;
}
int dac(int u = 0)
{
  dfs_size(heart = u);
  dfs_heart(u);
  int rv = !V[u = heart].p;
  MLLI com;
  com[0]++;
  vis[u] = 1;
  _efl(i, u, L, E) if (!vis[E[i].v]) {
    dis.clear();
    dfs_dis(E[i].v, 0);
    _fl(j, 0, _sz(dis)) {
      _it(MLLI) it = com.find(tne(tba(dis[j], V[u].p)));
      if (it == com.end()) continue;
      rv += it->second;
    }
    _fl(j, 0, _sz(dis)) com[dis[j]]++;
  }
#if 0
  _pt("get heart %d rv = %d\n", u, rv);
#endif
  _efl(i, u, L, E) if (!vis[E[i].v]) rv += dac(E[i].v);
  vis[u] = 0;
  return rv;
}

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  char ib[20];
  for ( ; ~scanf("%d", &n); ) {
    init(n);
    scanf("%d", &k);
    _fl(i, (p.clear(), 0), k) {
      scanf("%s", ib);
      p._pub(atoll(ib));
    }
    _fl(i, 0, n) {
      scanf("%s", ib);
      V[i].p = ltt(atoll(ib));
    }
    _fl(i, 0, n-1) {
      int u, v;
      scanf("%d%d", &u, &v);
      add(--u, --v);
      add(v, u);
    }
    vis = VI(n, 0);
    printf("%d\n", dac());
  }
  return 0;
}
