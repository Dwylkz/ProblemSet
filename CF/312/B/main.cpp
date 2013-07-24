#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
#define Rep(c, a, b) for (int c = a; c < (b); c++)
int a, b, c, d;
int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	for ( ; ~scanf("%d%d%d%d\n", &a, &b, &c, &d); ) {
		double s = (double)a / b,
			   z = (double)c / d;
		printf("%f\n", s / (1 - (1.0 - s) * (1.0 - z)));
	} 
	return 0;
}
