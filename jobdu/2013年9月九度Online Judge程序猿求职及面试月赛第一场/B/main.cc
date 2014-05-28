#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <complex>
using namespace std;
typedef map<int, int> mii_t;
#define _i(t) t::iterator
const int N = 2e5+10;

typedef complex<double> cd_t;
typedef vector<cd_t> vcd_t;
struct b2_fft_t {
  vcd_t c;
  void brc(vcd_t &x) {
    int l;
    for (l = 1; l < x.size(); l <<= 1) {}
    c.resize(l);
    for (int i = 0; i < c.size(); i++) {
      int to = 0;
      for (int o = l>>1, t = i; o; o >>= 1, t >>= 1)
        if (t&1) to += o;
      c[to] = i < x.size()? x[i]: cd_t(0., 0.);
    }
  }
  void fft(int on) {
    double dpi = acos(-1.)*on;
    for (int m = 1; m < c.size(); m <<= 1) {
      cd_t wn(cos(dpi/m), sin(dpi/m));
      for (int j = 0; j < c.size(); j += m<<1) {
        cd_t w = 1.;
        for (int k = j; k < j+m; k++, w *= wn) {
          cd_t u = c[k], t = w*c[k+m];
          c[k] = u+t, c[k+m] = u-t;
        }
      }
    }
    if (~on) return ;
    for (int i = 0; i < c.size(); i++)
      c[i] /= c.size()*1.;
  }
  void operator () (vcd_t &x) {
    brc(x), fft(1), x = c;
  } 
  void operator [] (vcd_t &x) {
    brc(x), fft(-1), x = c;
  }
} fft;

struct n_t {
  int v, i;
  n_t &input(int _i) {
    i = _i;
    scanf("%d", &v);
    return *this;
  }
  friend bool operator < (const n_t &lhs, const n_t &rhs) {
    return lhs.v < rhs.v;
  }
};
n_t a[N];
int m, n, k, s[N], cc[2][N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d", &m, &n, &k); ) {
    for (int i = 0; i < m; i++) a[i].input(0);
    for (int i = m; i < m+n; i++) a[i].input(1);
    int l = n+m;
    sort(a, a+n);
    mii_t m, d, t;
    for (int i = 0; i < l; i++) m[a[i].v] = 1;
    int r = 0;
    for (_i(mii_t) i = m.begin(); i != m.end(); i++) i->second = ++r;
    r <<= 1;
    vcd_t x[2] = {vcd_t(r, 0), vcd_t(r, 0)};
    memset(cc, 0, sizeof(cc));
    for (int i = 0; i < l; i++) {
      int j = m[a[i].v]-1;
      cc[a[i].i][j]++;
      x[a[i].i][j] += 1;
      if (a[i].i) d[j] = a[i].v;
    }
#if 1
    for (int i = 0; i < r; i++) printf(" %d", cc[0][i]);
    puts("");
    for (int i = 0; i < r; i++) printf(" %d", cc[1][i]);
    puts("");
#endif
    fft(x[0]), fft(x[1]);
    for (int i = 0; i < r; i++) x[0][i] *= x[1][i];
    fft[x[0]];
    for (int i = 0; i < r; i++) {
      s[i] = x[0][i].real()+0.5;
      if (i) s[i] += s[i-1];
    }
    int id = lower_bound(s, s+r, k)-s;
    k -= s[id-1];
    for (int i = 0; i < l; i++)
      if (!a[i].i) {
        _i(mii_t) j = d.find(id-(m[a[i].v]-1));
        if (j == d.end()) continue;
        t[a[i].v+j->second] = cc[0][m[a[i].v]-1]*cc[1][j->first];
      }
    for (_i(mii_t) i = t.begin(); i != t.end(); i++) {
      if (k <= i->second) {
        printf("%d\n", i->first);
        break;
      } else k -= i->second;
    }
#if 1
    printf("id = %d\n", id);
    for (int i = 0; i < r; i++) printf(" %3d", s[i]);
    puts("");
#endif
  }
  return 0;
}
