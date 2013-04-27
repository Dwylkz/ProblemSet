#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
using namespace std;
const int maxn = 1e3 + 10;
char f[maxn];
int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	int l;
	while (~scanf("%d%s", &l, f)) {
#if 0
		printf("%d %s\n", l, f);
#endif
		int s, t;
		for (int i = 0; i < l; i++) {
			if (f[i] != '.') {
#if 0
				printf("start in %d\n", i);
#endif
				if (f[i] == 'L') {
					t = i;
					for (i++; i < l && f[i] == 'L'; i++) {
					}
					s = i;
				} else {
					s = i + 1;
					for (i++; i < l && f[i] == 'R'; i++) {
					}
					if (f[i] == 'L') {
						t = i;
					} else {
						t = i + 1;
					}
				}
				break;
			}
		}
		printf("%d %d\n", s, t);
	}
	return 0;
}
