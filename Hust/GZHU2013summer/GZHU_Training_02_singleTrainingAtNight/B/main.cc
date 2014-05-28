#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 5e4 + 10;
const double eps = 1e-8;
typedef long long LL;

int main()
{
#if 1
	freopen("input.in", "r", stdin);
#endif
  int T = 1;
  double x, y, z, x1, y1, x2, y2;
	for ( ; ~scanf("%lf%lf%lf%lf%lf%lf%lf", &x, &y, &z, &x1, &y1, &x2, &y2); ) {
    double dx = x1-x2,
           dy = y1-y2,
           A = dy,
           B = -dx,
           C = y2*dx-x2*dy,
           d = (A*x+B*y+C);
    d = d*d;
    z = z*z*(A*A+B*B);
    printf("%s %d: ", (T&1)? "CASE": "Case", T);
    if (d == z) printf("Tangent");
    else if (d > z) printf("Away");
    else printf("Intersect");
    for (int i = 0; i < T; i++) putchar('.');
    puts("");
    T++;
	}
	return 0;
}
