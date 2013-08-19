#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;
const int M = 512;
typedef map<int, int> MII;
typedef long long LL;

struct ask_t {
  int l, r, i;
  friend bool operator < (ask_t lhs, ask_t rhs) {
    if (lhs.r == rhs.r) return lhs.l < rhs.l;
    return lhs.r < rhs.r;
  }
  void input(int _i) {
    i = _i;
    scanf("%d%d", &l, &r);
  }
};

int n, m, s[N], h[N];
LL ans[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    MII pm;
    for (int i = 1; i <= n; i++) {
      scanf("%d", s+i);
      pm[s[i]] = 1;
    }
    int rank = 1;
    for (MII::iterator i = pm.begin(); i != pm.end(); i++)
      i->second = rank++;
    for (int i = 1; i <= n; i++) s[i] = pm[s[i]];
    scanf("%d", &m);
    vector<ask_t> va[M];
    for (int i = 0; i < m; i++) {
      ask_t a;
      a.input(i);
      va[a.l/M].push_back(a);
    }
    int bl = n/M+(n%M>0)+1;
    for (int i = 0; i < bl; i++) {
#define _cube(x) (1LL*x*x*x)
#define _bf(x, y) {\
      sum -= _cube(h[s[x]]);\
      h[s[x]]y;\
      sum += _cube(h[s[x]]);}
      memset(h+1, 0, sizeof(int)*n);
      sort(va[i].begin(), va[i].end());
      int lb = 1, rb = 1;
      LL sum = 0;
      for (int j = 0; j < va[i].size(); j++) {
        for ( ; rb < va[i][j].r+1; rb++) _bf(rb, ++);
        if (lb < va[i][j].l) {
          for ( ; lb < va[i][j].l; lb++) _bf(lb, --);
        } else if (lb > va[i][j].l) {
          for ( ; lb > va[i][j].l; lb--) _bf(lb-1, ++);
        }
        ans[va[i][j].i] = sum;
      }
    }
    for (int i = 0; i < m; i++) printf("%lld\n", ans[i]);
  }
  return 0;
}
