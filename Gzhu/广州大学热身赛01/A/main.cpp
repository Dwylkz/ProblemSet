#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
using namespace std;

int n;

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	while (~scanf("%d", &n)) {
		while (n--) {
			char b[80<<1];
			scanf("%s", b);
			int lb = strlen(b);
			bool cl = 0;
			for (int i = 0; i < lb; i++) {
				if (b[i] == '!') {
					cl ^= 1;
				}
				else {
					if (!cl) {
						putchar(b[i]);
					}
					else {
						if (isupper(b[i])) {
							putchar(b[i] + 32);
						}
						else putchar(b[i] - 32);
					}
				}
			}
			putchar('\n');
		}
	}
	return 0;
}
