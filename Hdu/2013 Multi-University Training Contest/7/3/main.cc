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
#define _fi first
#define _se second
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
  typedef pair<int, int> PII;
}
using namespace dwylkz;

PII kmp(char *s, const char *p, int *f, int o)
{
  int sl = strlen(s), pl = strlen(p);
  PII rv(0, 0);
  for (int i = 0, j = -1; (o&1) && i<pl; i++) {
    for (j -= (j>=0); j!=-1 && p[i]!=p[j+1]; j = f[j]);
    f[i] = (j<0 || p[i]==p[j])? j++: -1;
  }
  for (int i = -1, j = -1; (o&2) && i<sl-1; i++) {
    for ( ; j!=-1 && s[i+1]!=p[j+1]; j = f[j]);
    if (s[i+1]==p[j+1] && ++j==pl-1) {
      rv._fi++;
      rv._se = i+1;
    }
  }
  return rv;
}

CA s, b;
IA f;


int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%s%s", s, b); ) {
    string p(b);
    kmp(s, p.data(), f, 1);
#if 1
    int l = _sl(p);
    _flpt(i, 0, l, "%d%c", f[i], i<l-1? ' ': '\n');
#endif
    string b = "";
    _sfl(i, s)
      if (isalpha(*i)) b += *i;
      else {
        string w = "";
        for (i++; *i && isalpha(*i); i++) w += *i;
        int t = 0;
        for (i++; *i && isdigit(*i); i++) t = t*10+*i-'0';
        i--;
#if 0
        _pt("get %s %d times\n", w.data(), t);
#endif
      }
  }
  return 0;
}
