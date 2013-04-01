#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 10e5 + 10;
typedef int AI[MAXN];

AI p;
int n, s, t;

int main()
{
#if 0
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int n;
	while (~scanf("%d%d%d", &n, &s, &t)) {
		for (int i = 0; i < n; i++) {
			scanf("%d", p + i);
			p[i]--;
		}
		s--;
		t--;
		int cnt = 0, c = s;
		bool yes = 0;
		do {
			if (c == t) {
				yes = 1;
				break;
			}
			c = p[c];
			cnt++;
		} while (c != s);
		if (!yes) {
			cnt = -1;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
