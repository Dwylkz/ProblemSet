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
#define _bw (1)
#define _bm ((1<<_bw)-1)
#define _ls(x, y) ((x)<<((y)*_bw))
#define _rs(x, y) ((x)>>((y)*_bw))
#define _gb(x, y) (_rs((x), (y))&_bm)
#define _cb(x, y) ((x)&~_ls(1, (y)))
#define _lb(x) (-x&x)
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
  typedef map<string, int> MSI;
  typedef vector<int> VI;
  typedef vector<LL> VLL;
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

struct card {
  int t, n;
  friend bool operator == (card lhs, card rhs)
  {
    return lhs.t == rhs.t || lhs.n == rhs.n;
  }
};
typedef vector<card> VC;

CA line;

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; gets(line), line[0] != '#'; ) {
    VC deck;
    for (char s[10], *i = line; ~sscanf(i, "%s", s); i += _sl(s)+1)
      deck._pub((card){s[1], s[0]});
    for (char s[10], *i = (gets(line), line); ~sscanf(i, "%s", s); i += _sl(s)+1)
      deck._pub((card){s[1], s[0]});
#if 0
    _flpt("card:\n", i, 0, _sz(deck), "\t%c %c\n", deck[i].t, deck[i].n);
#endif
    vector<VC> table;
    _fl(i, 0, _sz(deck)) {
      table._pub(VC(1, deck[i]));
      _wait() {
        int flag = 1, k;
        _fl(j, 0, _sz(table))
          if (j-2>=0 && table[j].back() == table[j-2].back()
              || j-1 >= 0 && table[j].back() == table[j-1].back()) {
            int id = j;
            _wait() if (id-2 >= 0 && table[j].back() == table[id-2].back()) id -= 2;
            else if (id-1 >= 0 && table[j].back() == table[id-1].back()) id--;
            else break;
            table[id]._pub(table[j].back());
            table[j]._pob();
            if (!_sz(table[j])) table.erase(table.begin()+j);
            flag = 0;
            break;
          }
        if (flag) break;
      }
    }
    printf("%d pile%sremaining: ", _sz(table), _sz(table)>1? "s ": " ");
    _fl(i, 0, _sz(table)) printf("%d%c", _sz(table[i]), i<_sz(table)-1? ' ': '\n');
  }
  return 0;
}
