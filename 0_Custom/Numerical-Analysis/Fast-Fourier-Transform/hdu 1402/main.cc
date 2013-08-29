#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <complex>
#include <vector>
using namespace std;
const int N = 5e4+10;

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

char a[N], b[N];

int main() {
#if 1
  freopen("input.in", "rt", stdin);
#endif
  int l1, l2, i, l;
  for ( ; ~scanf("%s %s",a,b); ) {
    int l1 = strlen(a), l2 = strlen(b), l = 1;
    vcd_t op1, op2;
    for ( ; l < l1*2 || l < l2*2; l <<= 1) {}
    for (int i = 0; i < l1; i++) op1.push_back(a[l1-1-i]-'0');
    for (int i = l1; i < l; i++) op1.push_back(0.);
    fft(op1);
    for (int i = 0; i < l2; i++) op2.push_back(b[l2-1-i]-'0');
    for (int i = l2; i < l; i++) op2.push_back(0.);
    fft(op2);
    for (int i = 0; i < l; i++) op1[i] *= op2[i];
    fft[op1];
    vector<int> c(op1.size());
    for (int i = 0 ; i < l; i++) c[i] = op1[i].real()+0.5;
    for (int i = 0; i < l; i++) {
      c[i+1] += c[i] / 10;
      c[i] %= 10;
    }
    l = l1+l2-1;
    for ( ; c[l] <= 0 && l > 0; ) l--;
    for (int i = l; i >= 0; i--) printf("%d", c[i]);
    puts("");
  }
  return 0;
}
