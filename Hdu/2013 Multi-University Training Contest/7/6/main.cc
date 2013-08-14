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
  const int N = 1e6+10;
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

struct server {
  VI load;
  int id;
  friend bool operator < (server lhs, server rhs) {
    return _sz(lhs.load) < _sz(rhs.load);
  }
};
int n, m;

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    vector<VI> p(m);
    vector<server> c(n);
    _fl(i, 0, n) c[i].id = i;
    _fl(i, 0, m) {
      c[i%n].load._pub(i);
      p[i]._pub(i%n);
    }
    sort(c.begin(), c.end());
    _fl(i, 0, n) {
      int rm = _sz(c[i].load), j = 0;
      _wait(rm) {
        if (c[i].id != c[j%n].id) {
          rm--;
          p[c[i].load[rm]]._pub(c[j%n].id);
        }
        j++;
      }
    }
    _fl(i, 0, m) {
      VI v(n, 0);
      _fl(j, 0, _sz(p[i])) v[p[i][j]] = 1;
      _fl(j, 0, n) if (!v[j]) p[i]._pub(j);
    }
    _fl(i, 0, m) _fl(j, 0, _sz(p[i]))
      printf("%d%c", p[i][j]+1, j<_sz(p[i])-1? ' ': '\n');
  }
  return 0;
}
