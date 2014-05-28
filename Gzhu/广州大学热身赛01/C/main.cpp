#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
using namespace std;

char b[100010];

void carryplus1(char *s, int h, int &o)
{
	b[h]++;
	for (int i = h; i < o; i++) {
		if (b[i] > 9) {
			b[i + 1]++;
			b[i] %= 10;
		}
		else break;
	}
	if (b[o]) o++;
}

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	while (~scanf("%s", b)) {
		int lb = strlen(b);
		for (int i = 0; i < lb / 2; i++) {
			swap(b[i], b[lb - i - 1]);
		}
#if 0
		printf("reverse test: %s\n", b);
#endif
		for (int i = 0; i < lb; i++) {
			b[i] -= '0';
		}
		b[lb] = 0;
		carryplus1(b, 0, lb);
#if 0
		printf("plus test: ");
		for (int i = 0; i < lb; i++) {
			printf("%d", b[i]);
		}
		putchar('\n');
#endif
		while (1) {
			bool yes = 1;
			for (int i = 0; i < lb / 2; i++) {
				if (b[i] != b[lb - i - 1]) {
					yes = 0;
					break;
				}
			}
			if (yes) break;
			for (int i = 0; i < lb / 2; i++) {
				if (b[i] > b[lb - i - 1]) {
					b[i] = b[lb - i - 1];
					carryplus1(b, i + 1, lb);
				}
				else if (b[i] < b[lb - i - 1]) {
					b[i] = b[lb - i - 1];
				}
			}
		}
		for (int i = lb - 1; i > -1; i--) {
			printf("%d", b[i]);
		}
		putchar('\n');
	}
	return 0;
}
