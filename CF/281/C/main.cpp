#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
#include <cmath>
using namespace std;
const double EPS = 10e-6;
const double PI = acos(-1.0);

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	double w, h, a;

	while (~scanf("%lf%lf%lf", &w, &h, &a)) {
		a = min(180.0 - a, a);
		double  l = sqrt(w * w + h * h) / 2.0,
				b = asin(sqrt(h * h / (w * w + h * h))), x, y;
#if 1
		printf("%lf, %lf\n", l, b);
#endif

		if (PI / a - 2.0 * b < EPS) {
			x = l * sin(b - a / 2.0);
			y = h - x - x / cos(a);
			printf("%lf\n", (x * x * tan(x) + y * y / tan(a)) / 2.0);
		}
		else {
		}
	}
	return 0;
}
