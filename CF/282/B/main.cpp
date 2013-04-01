#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 10e6+10;
typedef int AI[MAXN];

struct egg {
	int a, g, id;
	friend bool operator < (egg p, egg q) {
		return p.a < q.a;
	}
};

egg e[MAXN];
int n, c[MAXN];

int main()
{
#if 0
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	while (~scanf("%d", &n)) {
		int sa = 0, sg = 0;

		for (int i = 0; i < n; i++) {
			scanf("%d%d", &e[i].a, &e[i].g);
			sa += e[i].a;
			e[i].id = i;
			c[i] = 0;
		}
		sort(e, e + n);
		for (int i = 0; i < n; i++) {
			if (500 < sa - sg) {
				sa -= e[i].a;
				sg += e[i].g;
				c[i] = 1;
			}
			else break;
		}
		if (sa - sg <= 500) {
			for (int i = 0; i < n; i++) {
				putchar(c[i]? 'G': 'A');
			}
			puts("");
		}
		else {
			puts("-1");
		}
	}
	return 0;
}
