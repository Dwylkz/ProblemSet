#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
using namespace std;
const int MAXN = 1010;

int qmod(int a, int b, int c)
{
	int r = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			r = r * a % c;
		}
		a = a * a % c;
	}
	return r;
}

int main()
{
#if 0
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int p;
	while (~scanf("%d", &p)) {
		int r = 0;
		for (int x = 1; x < p; x++) {
			int c = 0;
			for (int i = 1; i < p; i++) {
				int t = qmod(x, i, p) - 1;
				if (t % p == 0) {
					c++;
					if (i == p - 1 && c == 1) {
						r++;
					}
				}
			}
		}
		printf("%d\n", r);
	}
	return 0;
}
