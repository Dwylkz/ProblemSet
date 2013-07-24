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
int n, k;
int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	for ( ; ~scanf("%d%d", &n, &k); ) {
		if ((n - 1) * n / 2 <= k) {
			puts("no solution");
		} else {
			for (int i = 0; i < n; i++) {
				printf("%d %d\n", i, n * n - i * n);
			}
		}
	} 
	return 0;
}
