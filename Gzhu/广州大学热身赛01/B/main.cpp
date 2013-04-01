#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
using namespace std;

char b[1001];

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int count = 0;

	while (~scanf("%s", b)) {
		if (!strcmp(b, "###")) {
			printf("%d\n", count);
			count = 0;
			continue;
		}
		int lb = strlen(b);
		for (int i = 0; i < lb; i++) {
			if (isdigit(b[i]) || isalpha(b[i])) {
				while (i < lb && (isdigit(b[i]) || isalpha(b[i]))) i++;
				count++;
				i--;
			}
			else count++;
		}
	}
	return 0;
}
