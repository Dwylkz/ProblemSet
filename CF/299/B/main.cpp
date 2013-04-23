#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 3e5 + 10;
int n, k;
char r[maxn];
int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d%d", &n, &k)) {
		scanf("%s", r);
		int ml = 0;
		for (int i = 1, l = strlen(r); i < l; i++) {
			if (r[i] == '#') {
				int tl = 0;
				for ( ; i < l && r[i] == '#'; i++) {
					tl++;
				}
				i--;
				ml = max(ml, tl);
			}
		}
		puts(ml < k? "YES": "NO");
	}
	return 0;
}
