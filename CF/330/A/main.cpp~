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
int n, m, n1, p1, a[maxn];
int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d%d", &n, &m)) {
		n1 = p1 = 0;
		Rep(i, 1, n + 1) {
			int ai;
			scanf("%d", &ai);
			if (ai == -1) {
				p1++;
			} else {
				n1++;
			}
		}
		if (p1 < n1) {
			swap(p1, n1);
		}
		while (m--) {
			int l, r;
			scanf("%d%d", &l, &r);
			l = r - l + 1;
			if (l == 1 || (l & 1)) {
				puts("0");
				continue;
			}
			l = l / 2;
			puts((l <= n1 && l <= p1)? "1": "0");
		}
	} 
	return 0;
}
