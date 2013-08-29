#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct fc_t {
  double eps;
  fc_t() {
    eps = 1e-8;
  }
  bool e(double lhs, double rhs) {
    return abs(lhs-rhs) < eps;
  }
  bool l(double lhs, double rhs) {
    return lhs+eps < rhs;
  }
  bool g(double lhs, double rhs) {
    return lhs-eps > rhs;
  }
} fc;

struct pt_t {
  double x, y;
  pt_t(double _x = 0, double _y = 0) {
    x = _x, y = _y;
  }
  double operator [] (int b) {
    return b? x*x+y*y: sqrt(x*x+y*y);
  }
  friend pt_t operator + (const pt_t &lhs, const pt_t &rhs) {
    return pt_t(lhs.x+rhs.x, lhs.y+rhs.y);
  }
  friend pt_t operator - (const pt_t &lhs, const pt_t &rhs) {
    return pt_t(lhs.x-rhs.x, lhs.y-rhs.y);
  }
  friend double operator * (const pt_t &lhs, const pt_t &rhs) {
    return lhs.x*rhs.x+lhs.y*rhs.y;
  }
  friend double operator % (const pt_t &lhs, const pt_t &rhs) {
    return lhs.x*rhs.y-lhs.y*rhs.x;
  }
  pt_t &input() {
    scanf("%lf%lf", &x, &y);
    return *this;
  }
};

struct asort_t {
  bool cmpl(pt_t lhs, pt_t rhs) {
    return fc.l(lhs.y, rhs.y) || (fc.e(lhs.y, rhs.y) && fc.l(lhs.x, rhs.x));
  }
  static pt_t o;
  static bool cmp(pt_t lhs, pt_t rhs) {
    double c = (lhs-o)%(rhs-o);
    if (!fc.e(c, 0.0)) return fc.g(c, 0.0);
    return fc.g((lhs-o)[1], (rhs-o)[1]);
  }
  void operator () (vector<pt_t> &p) {
    int mn = 0;
    for (int i = 0; i < p.size(); i++)
      if (cmpl(p[i], p[mn])) mn = i;
    swap(p[0], p[mn]);
    o = p[0];
    sort(p.begin()+1, p.end(), cmp);
  }
} asort;
pt_t asort_t::o;

struct ch_t {
  vector<pt_t> p;
  double l;
  ch_t(vector<pt_t> &ps) {
    asort(p = ps);
    vector<pt_t> s(p.begin(), p.begin()+2);
    ps.clear();
    for (int i = 2; i < p.size(); i++) {
      for ( ; fc.g((s[s.size()-2]-s.back())%(p[i]-s.back()), 0.0); )
        ps.push_back(s.back()), s.pop_back();
      s.push_back(p[i]);
    }
    p = s;
    for (int i = l = 0; i < p.size(); i++)
      l += (p[(i+1)%p.size()]-p[i])[0];
  }
};

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int n; ~scanf("%d", &n), n; ) {
    vector<pt_t> p;
    for (int i = 0; i < n; i++) p.push_back(pt_t().input());
    if (p.size() < 3) printf("%.2f\n", (p.back()-p[0])[0]);
    else printf("%.2f\n", ch_t(p).l);
  }
  return 0;
}
