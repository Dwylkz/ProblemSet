#if 1|dwylkz
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
#define _fl(c, a, b) for (int c = (a); c < (b); c++)
#define _fln(c, a, b, n) for (int c = (a); c < (b); c += (n))
#define _rfl(c, a, b) for (int c = (a)-1; (b) <= c; c--)
#define _rfln(c, a, b, n) for (int c = (a)-1; (b) <= c; c -= (n))
#define _efl(c, a, L, E) for (int c = (L)[a]; c != -1; c = (E)[c].to)
#define _refl(c, a, L, E) for (int &c = (L)[a]; c != -1; c = (E)[c].to)
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
#endif
using namespace std;
namespace dwylkz {
  const int N = 1e4+10;
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

namespace lct {
  struct node {
    node *c[2], *p;
    int rev;
    int type()
    {
      if (!p || p->c[0] != this && p->c[1] != this) return 2;
      return p->c[0] != this;
    }
    node *set()
    {
      swap(c[0], c[1]);
      rev ^= 1;
      return this;
    }
    node *push()
    {
      if (rev) {
        for (int i = 0; i < 2; i++)
          if (c[i]) c[i]->set();
        rev = 0;
      }
      return this;
    }
    node *update()
    {
      return this;
    }
    node *rotate()
    {
      node *y = p;
      int b = type(), pb = p->type();
      if (pb < 2) y->p->push();
      y->push();
      if (push()->p = y->p, pb < 2) p->c[pb] = this;
      if (y->c[b] = c[!b]) c[!b]->p = y;
      return c[!b] = y, y->update()->p = this;
    }
    node *splay()
    {
      for ( ; type() < 2; type() < 2? rotate(): 0)
        type() == p->type()? p->rotate(): rotate();
      return update();
    }
    node *end(int b)
    {
      node *x = this;
      for ( ; x->push()->c[b]; x = x->c[b]) ;
      return x;
    }
  } pool[N], *top;
  node *init()
  {
    return top = pool;
  }
  node *make_tree()
  {
    return &(*top++ = (node){0, 0, 0, 0});
  }
  node *access(node *x)
  {
    for (node *y = x, *z = 0; y; z = y, y = y->update()->p)
      y->splay()->c[1] = z;
    return x;
  }
  node *find_root(node *x)
  {
    return access(x)->splay()->end(0)->splay();
  }
  node *cut(node *x)
  {
    access(x);
    x->c[0] = 0;
    return x;
  }
  node *join(node *x, node *y)
  {
    access(x)->p = y;
    return access(x);
  }
  node *rooting(node *x)
  {
    return access(x)->splay()->set();
  }
}
using namespace lct;

int n, m;

lct::node *rt[N];

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    init();
    for (int i = 0; i < n; i++) rt[i] = make_tree();
    char op[10];
    for (int x, y; m--; ) {
      scanf("%s%d%d", op, &x, &y);
      if (x > y) swap(x, y);
      if (op[0] == 'C') {
        rooting(rt[x]);
        join(rt[x], rt[y]);
      } else if (op[0] == 'D') {
        rooting(rt[x]);
        cut(rt[y]);
      } else puts(find_root(rt[x-1]) == find_root(rt[y-1])? "Yes": "No");
    }
  }
  return 0;
}
