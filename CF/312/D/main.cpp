#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
#define Rep(c, a, b) for (int c = a; c < (b); c++)
struct Cat {
	int h, t, f;
};
Cat c[maxn];
int n, m, p, t[maxn];

LL Check(int x, int f = 0, LL res = 0) {
	for (int i = 0; i < m; i++) {
		if (c[i].f && c[i].t <= x + t[c[i].h]) {
			res += x + t[c[i].h] - c[i].t;
			if (f) {
				c[i].f = 0;
			}
		}
	}
	return 0;
}

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	for ( ; ~scanf("%d%d%d", &n, &m, &p); ) {
		memset(t, 0, sizeof(t));
		for (int i = 1; i < n; i++) {
			scanf("%d", t + i);
			t[i] += t[i - 1];
		}
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &c[i].h, &c[i].t);
			c[i].f = 0;
		}
		LL res = 0;
		int low = 0, upp = 1e9;
		for (int i = 0; i < p; i++) {
			int L = low, R = upp;
			for ( ; L < R; ) {
				int M = L + R >> 1;
				if (Check(M) <= M) {
					R = M;
				} else {
					L = M + 1;
				}
			}
			res += Check(L);
			low = L;
		}
		printf("%lld\n", res);
	} 
	return 0;
}
