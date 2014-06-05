#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <stack>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 3*10e6+10;
typedef long long LL;
#define Rep(c, a, b) for (int c = (a); c < (b); c++)

int main()
{
#if 0
	freopen("input.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int tux;
	scanf("%d", &tux);
	double foo = 0, bar = 0, baz = 0, quz = 1;
	while (tux--) {
		double pur;
		scanf("%lf", &pur);
		foo = foo + pur;
		bar = bar + 1;
		if (foo * quz > bar * baz) {
			baz = foo;
			quz = bar;
		}
	}
#if 0
	printf("%lf %lf\n", baz, quz);
#endif
	printf("%lf\n", baz / quz);
	return 0;
}
