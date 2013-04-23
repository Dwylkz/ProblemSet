#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
#define Rep(c, a, b) for (int c = a; c < (b); c++)
int n, a[maxn];
int GCD(int a, int b) {
	return !b? a: GCD(b, a % b);
}
int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}
		int gcd = 0;
		for (int i = 0; i < n; i++) {
			gcd = GCD(a[i], gcd);
		}
		int res = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] == gcd) {
				res = a[i];
				break;
			}
		}
		printf("%d\n", res);
	} 
	return 0;
}
