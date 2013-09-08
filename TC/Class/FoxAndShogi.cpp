#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef long long ll_t;
#define _be begin()
#define _en end()
#define _i(t) t::iterator
typedef vector<int> vi_t;
typedef vector<string> vs_t;
typedef map<int, int> mii_t;
typedef pair<int, int> pii_t;
#define _fi first
#define _se second
const int N = 50+10;
const int mod = 1e9+7;

struct edge_t {
  int v, to;
};
vector<edge_t> E;
int L[N];
void init() {
  E.clear();
  memset(L, -1, sizeof(L));
}
void add(int u, int v) {
  edge_t t = {v, L[u]};
  L[u] = E.size();
  E.push_back(t);
}

struct trvl_t {
  typedef void (*t_f)(int, int);
  void rtc(int r, int n, int c, int m, t_f f) {
    for (int i = r; i < n; i++)
      for (int j = c; j < m; j++) f(i, j);
  }
  void ctr(int r, int n, int c, int m, t_f f) {
    for (int j = c; j < m; j++) 
      for (int i = r; i < n; i++) f(i, j);
  }
  void pth(int r, int n, int c, int m, int dr, int dc, t_f f) {
    for (int i = 0; i < n; i++)
      if (0 <= r+dr && r+dr < n && 0 <= c+dc && c+dc < m)
        f(r+dr, c+dc);
  }
} trvl;

class FoxAndShogi {
  public:
    vs_t b;
    int n, m, c[N][N];
    void init() {
      for (int i = c[0][0] = 1; i < N; i++)
        for (int j = c[i][0] = 1; j < N; j++)
          c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
    }
    int go(int j) {
      int rv = 1;
      for (int i = 0; i < n; i++)
        if (b[i][j] != 'U') {
          int cnt = 0, ce = 0;
          string t = "";
          for (int k = i; k < n; k++)
            if (b[k][j] != '.') {
              if (b[k][j] == 'D') i = k;
              break;
            }
          for ( ; i < n && b[i][j] != 'U'; i++) {
            cnt++;
            ce += b[i][j] != '.';
            t += b[i][j];
          }
          for ( ; i < n && b[i][j] != 'D'; i++) {
            cnt++;
            ce += b[i][j] != '.';
            t += b[i][j];
          }
          for (int k = i-1; k >= 0; k--)
            if (b[k][j] != '.') {
              if (b[k][j] == 'U') cnt -= i-1-k;
              break;
            }
          i--;
          rv = 1ll*rv*c[cnt][ce]%mod;
#if 1
          printf("in %d, %d: %d, %d, %s\n", i, j, cnt, ce, t.data());
#endif
        }
      return rv;
    }
    int differentOutcomes(vector <string> board) {
      init();
      b = board, n = b.size(), m = b[0].size();
      int rv = 1;
      for (int i = 0; i < m; i++)
        rv = (1ll*rv*go(i))%mod;
      return rv;
    }
};
