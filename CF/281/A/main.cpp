#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
using namespace std;
const int MAXN = 1010;

char b[MAXN];

int main()
{
#if 0
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	while (~scanf("%s", &b)) {
		if (islower(b[0])) {
			b[0] -= 32;
		}
		puts(b);
	}
	return 0;
}
