#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10e5 + 10;
int n, sx[maxn], sy[maxn];
vector<int> x, y; 
int main()
{
#if 0
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d", &n)) {
		x.clear();
		y.clear();
		for (int i = 0; i < n; i++) {
			int t, w;
			scanf("%d%d", &t, &w);
			if (t == 1) {
				x.push_back(w);
			} else {
				y.push_back(w);
			}
		}
		sort(x.begin(), x.end(), greater<int>());
		sort(y.begin(), y.end(), greater<int>());
		sx[0] = sy[0] = 0;
		for (int i = 1; i <= x.size(); i++) {
			sx[i] = sx[i - 1] + x[i - 1];
		}
		for (int i = 1; i <= y.size(); i++) {
			sy[i] = sy[i - 1] + y[i - 1];
		}
#if 0
		printf("x: ");
		for (int i = 0; i < x.size(); i++) {
			printf("%4d", x[i]);
		}
		puts("");
		printf("y: ");
		for (int i = 0; i < y.size(); i++) {
			printf("%4d", y[i]);
		}
		puts("");
		printf("sx: ");
		for (int i = 0; i < x.size(); i++) {
			printf("%4d", sx[i]);
		}
		puts("");
		printf("sy: ");
		for (int i = 0; i < y.size(); i++) {
			printf("%4d", sy[i]);
		}
		puts("");
#endif
		int result = 0x7fffffff;
		for (int i = 0; i <= x.size(); i++) {
			for (int j = 0; j <= y.size(); j++) {
				int w = sx[x.size()] + sy[y.size()] - sx[i] - sy[j],
					tt = i + j * 2;
#if 0
				printf("%d <= %d?\n", w, tt);
#endif
				if (w <= tt) {
					result = min(result, tt);
				}
			}
		}
		printf("%d\n", result);
	}
	return 0;
}
