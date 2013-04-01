#include <iostream>
#include <cstdlib>
using namespace std;
#define sq(x) ((x) * (x))

int main()
{
	int T;
	double h1, r1, x1, y1, z1, h2, r2, x2, y2, z2, x3, y3, z3;
	double xp, yp, zp, d, t, dt;

	scanf("%d", &T);
	while (T--)
	{
		scanf("%lf%lf%lf%lf%lf", &h1, &r1, &x1, &y1, &z1);
		scanf("%lf%lf%lf%lf%lf", &h2, &r2, &x2, &y2, &z2);
		scanf("%lf%lf%lf", &x3, &y3, &z3);
		z1 += h1 - r1;
		z2 += 0.9 * h2 - r2;
		d = sq(x3) + sq(y3) + sq(z3);
		t = (x3 * (x1 - x2) + y3 * (y1 - y2) + z3 * (z1 - z2)) / d;
		xp = x3 * t + x2;
		yp = y3 * t + y2;
		zp = z3 * t + z2;
		dt = sq(r1) - sq(xp - x1) - sq(yp - y1) - sq(zp - z1);
		puts(dt >= 0? "YES": "NO");
	}

	return 0;
}