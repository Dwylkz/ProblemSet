#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
const double G = 9.8;
const double Pi = acosl(-1.);
const double D2A = Pi/180;
const double A2D = 180/Pi;

double v, d;

int main() {
#if 1
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ks = 1; T--; ks++) {
    printf("Case #%d: ", ks);
    scanf("%lf%lf", &v, &d);
    double s = (long double)G*d/v/v;
    printf("%.7f\n", A2D*0.5*asin(s));
  }
  return 0;
}
