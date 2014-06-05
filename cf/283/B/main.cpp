#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2 * 10e5 + 10;
typedef int AI[MAXN];

char s[MAXN];
AI I;

int main()
{
#if 0
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int n;
	while (~scanf("%d", &n)) {
		scanf("%s", s);
		memset(I, 0, sizeof(I));
		int i = 0;
		for (int j = 0; j < n; j++) {
			I[j] += i;
			if (s[j] == 'I') {
				i++;
			}
		}
		int r = 0;
		i = 0;
		for (int j = n - 1; -1 < j ; j--) {
			I[j] += i;
			if (s[j] != 'F' && !I[j]) {
				r++;
			}
			if (s[j] == 'I') {
				i++;
			}
		}
		printf("%d\n", r);
	}
	return 0;
}
