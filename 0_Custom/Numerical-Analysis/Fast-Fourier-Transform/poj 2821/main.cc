#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <complex>
using namespace std;
const int N = (1<<20);

typedef complex<double> cd_t;
typedef vector<cd_t> vcd_t;
struct mb_fft_t {
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
    double dpi = 2.0*acos(-1.)*on;
    for (int m = 1; m < c.size(); m <<= 1) {
      cd_t wn(cos(dpi/(m<<1)), sin(dpi/(m<<1)));
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

int main()
{
#if 1
  freopen("input.in", "rt", stdin);
#endif
  for (int n; ~scanf("%d", &n); ) {
    vcd_t b, c;
    for (int i = 0; i < n; i++) {
      double f;
      scanf("%lf", &f);
      b.push_back(f);
    }
    for (int i = 0; i < n; i++) {
      double f;
      scanf("%lf", &f);
      c.push_back(f);
    }
    fft(b), fft(c);
    for (int i = 0; i < c.size(); i++) c[i] /= b[i];
    fft[c];
    for (int i = 0; i < n; i++) printf("%.4f\n", c[i].real());
  }

  return 0;
}
