#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 110;
const int inf32 = 0x7fffffff;
int n, m, d, mat[maxn][maxn], num[maxn * maxn], nl;
int iabs(int x) {
	return x < 0? -x: x;
}
int imin(int p, int q) {
	return p < q? p: q;
}
int stastic(int ave) {
#if 0
	printf("ave = %d\n", ave);
#endif
	int step = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			step += abs(mat[i][j] - ave);
		}
	}
	return step;
}
int main()
{
#if 0
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	while (~scanf("%d%d%d", &n, &m, &d)) {
		int sum = 0, mod;
		bool yes = 1;
		nl = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", mat[i] + j);
				if (!i && !j) {
					mod = mat[i][j] % d;
				} else {
					if (mat[i][j] % d != mod) {
						yes = 0;
					}
				}
				mat[i][j] /= d;
				sum += mat[i][j];
				num[nl++] = mat[i][j];
			}
		}
		if (!yes) {
			puts("-1");
			continue;
		}
		sort(num, num + nl);
		int res = 0x7fffffff;
		for (int i = nl / 2; i <= nl / 2 + 1; i++) {
			res = min(res, stastic(num[i]));
		}
		printf("%d\n", res);
	}
	return 0;
}
