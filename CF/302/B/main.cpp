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
int n, m, n1, p1, c[maxn], t[maxn], v[maxn];
int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d", c + i, t + i);
		}
		for (int i = 0; i < m; i++) {
			scanf("%d", v + i);
		}
		int j = 0, tt = 0;
		for (int i = 0; i < n; i++) {
			for ( ; j < m && v[j] <= tt + c[i] * t[i]; j++) {
				printf("%d\n", i + 1);
			}
			tt += c[i] * t[i];
			if (j == m) {
				break;
			}
		}
	} 
	return 0;
}
