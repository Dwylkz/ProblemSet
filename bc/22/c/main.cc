#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

const double EPS = 1e-8;
const double PI = acos(-1.0);
const double G = 9.8;

int h, v;

double F(double ang)
{
  double hv = cos(ang)*v;
  double vv = sin(ang)*v;
  double t1 = vv/G;
  double t2 = sqrt(2*(vv*t1-G*t1*t1/2.0+h)/G);
  return hv*(t1+t2);
}

int main()
{
  int kase;
  scanf("%d", &kase);
  while (kase--) {
    scanf("%d%d", &h, &v);
    double l = 0.0, r = PI/2;
    while (l < r-EPS) {
      double d = (r-l)/3.0;
      double ll = l+d;
      double rr = r-d;
      if (F(ll) < F(rr))
        l = ll;
      else
        r = rr;
    }
    printf("%.2f\n", F(l));
  }
  return 0;
}
