#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
using namespace std;
const int maxn = 10e5 + 10;
int w[maxn];
int main()
{
#if 0
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", w + i);
		}
		w[0] = w[n + 1] = 0;
		scanf("%d", &m);
		while (m--) {
			int x, y;
			scanf("%d%d", &x, &y);
			w[x - 1] += y - 1;
			w[x + 1] += w[x] - y;
			w[x] = 0;
		}
		for (int i = 1; i <= n; i++) {
			printf("%d\n", w[i]);
		}
	}
	return 0;
}
