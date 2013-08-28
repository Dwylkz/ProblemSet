// BEGIN CUT HERE

// END CUT HERE
#line 5 "GameInDarknessDiv2.cpp"
#if 1006100106
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
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
#define _pt(x...) fprintf(stderr, "" x)
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
  typedef pair<int, int> II;
int logn(LL x, LL n, LL o = 1, int rv = 0)
{
  for ( ; o <= x; o *= n) rv++;
  return rv-1;
}
int bitnum(LL x, int rv = 0)
{
  for ( ; x; x -= _lb(x)) rv++;
  return rv;
}
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


class GameInDarknessDiv2 {
	static const int N = 25e2+10;
	public:
  int f[2][55][55];
  bool check(int x, int y, int n, int m) {
    return 0 <= x && x < n && 0 <= y && y < m;
  }
	string check(vector <string> field, vector <string> moves) {
		int xa = 0, ya = 0, xb = 0, yb = 0, n = field.size(), m = field[0].length();
    const int mv[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<string> &g = field;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (g[i][j] == 'A')
          xa = i, ya = j;
        else if (g[i][j] == 'B')
          xb = i, yb = j;
    string ms = "";
    for (int i = 0; i < moves.size(); i++) ms += moves[i];
    int mn = ms.length();
    for (int i = 0; i < mn; i++)
      if (ms[i] == 'R') ms[i] = 0;
      else if (ms[i] == 'D') ms[i] = 1;
      else if (ms[i] == 'L') ms[i] = 2;
      else ms[i] = 3;
    int r = 0;
    memset(f, 0, sizeof(f));
    f[0][xb][yb] = 1;
    for (int k = 0; k < mn; k++) {
      g[xa][ya] = '.';
      xa += mv[(int)ms[k]][0], ya += mv[(int)ms[k]][1];
      if (g[xa][ya] == 'B') return "Alice wins";
      else g[xb][yb] = '.';
      g[xa][ya] = 'B';
      f[r][xa][ya] = 0;
      int sum = 0;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (f[r][i][j])
            for (int l = 0; l < 4; l++) {
              int tx = i+mv[l][0], ty = j+mv[l][1];
              if (!check(tx, ty, n, m) || g[tx][ty] != '.') continue;
              f[!r][tx][ty] = 1;
              sum++;
            }
      memset(f[r], 0, sizeof(f[r]));
      r ^= 1;
      if (!sum) return "Alice wins";
    }
    return "Bob wins";
	}
};
