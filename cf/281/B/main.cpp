#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
#include <cmath>
using namespace std;
const int INFI = ~0u>>1;

int x, y, n;

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
#if 0
	printf("%d", INFI);
#endif
	while (~scanf("%d%d%d", &x, &y, &n)) {
		int ma = 0, mb = 1;
		double min = INFI, xy = 1.0 * x / y;

		for (int b = 1; b <= n; b++) {
			double a = 1.0 * b *  xy;
			int ca = a + 1, fa = a;

#if 0
			printf("%lf %d %d\n", a, ca, fa);
#endif
			double tmin = abs(1.0 * x / y - 1.0 * fa / b);

			if (tmin < min) {
				min = tmin;
				ma = fa;
				mb = b;
			}
			tmin = abs(1.0 * x / y - 1.0 * ca / b);
			if (tmin < min) {
				min = tmin;
				ma = ca;
				mb = b;
			}
#if 0
			printf("%d/%d\n", ma, mb);
#endif
		}
		printf("%d/%d\n", ma, mb);
	}
	return 0;
}
