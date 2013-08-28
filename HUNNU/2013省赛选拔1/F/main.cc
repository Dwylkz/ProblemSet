#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
const int N = 1e4+10;

struct t_t {
  string s;
  int n, d;
  t_t(int m, int se) {
    s = "";
    s += '0'+m/10;
    s += '0'+m%10;
    s += ':';
    s += '0'+se/10;
    s += '0'+se%10;
    n = (m/10==9)+(m%10==9)+(se/10==9)+(se%10==9);
    d = m*60+se;
  }
  friend bool operator < (t_t lhs, t_t rhs) {
    return lhs.d < rhs.d;
  }
};
set<t_t> v[6];

void init() {
  for (int i = 0; i < 100; i++)
    for (int j = 0; j < 100; j++) {
      t_t t(i, j);
      v[t.n].insert(t);
    }
  v[5].insert(t_t(99, 99));
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  init();
  for (int m, s; ~scanf("%2d:%2d", &m, &s), m||s; ) {
    int t = m*60+s, l = 9*t+1, r = 11*t-1;
    l = l/10+(l%10 > 0);
    r /= 10;
    set<t_t>::iterator ans = v[5].begin();
    for (int i = 4; i >= 0; i--) {
      set<t_t>::iterator lrv = v[i].end(), rrv = lrv;
      t_t tt(99, 99);
      tt.d = t;
      rrv = v[i].lower_bound(tt);
      if (rrv->d > r) rrv = v[i].end();
      for (int L = l, R = t; L < R; ) {
        int m = L+R>>1;
        tt.d = m;
        set<t_t>::iterator j = v[i].lower_bound(tt);
        if (j != v[i].end() && j->d <= t) {
          lrv = j;
          L = m+1;
        } else R = m;
      }
      if (lrv != v[i].end() && rrv == v[i].end()) ans = lrv; 
      else if (lrv == v[i].end() && rrv != v[i].end()) ans = rrv;
      else if (lrv != v[i].end() && rrv != v[i].end()) {
        int d1 = abs(lrv->d-t), d2 = abs(rrv->d-t);
        if (d1 == d2) {
          if (lrv->s < rrv->s) ans = lrv;
          else ans = rrv;
        } else if (d1 < d2) ans = lrv;
        else ans = rrv;
      }
      if (ans != v[5].begin()) break;
    }
    printf("%s\n", ans->s.data());
  }
  return 0;
}
