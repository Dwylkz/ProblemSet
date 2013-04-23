#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 110;
const int inf32 = 0x7fffffff;
int n, k;
int main()
{
#if 0
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	while (~scanf("%d%d", &n, &k)) {
		if (n < k || (1 < n && k == 1)) {
			puts("-1");
			continue;
		}
		int c[2] = {'a', 'b'}, cnt[2] = {0, 0}, cx = 0;
		for (int i = 0; i < n - max(0, k - 2); i++) {
			putchar(c[cx]);
			cnt[cx]++;
			cx ^= 1;
		}
		int s = 'c';
		for (int i = n - max(0, k - 2); i < n; i++) {
			putchar(s++);
		}
		puts("");
	}
	return 0;
}
