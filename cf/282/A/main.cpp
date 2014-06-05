#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
using namespace std;
const int MAXN = 1010;

int main()
{
#if 0
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int n;

	while (~scanf("%d", &n)) {
		int x = 0;;

		while (n--) {
			char op[4];

			scanf("%s", op);
			for (int i = 0; i < 3; i++) {
				if (op[i] == '+') {
					x++;
					break;
				} 
				else if (op[i] == '-') {
					x--;
					break;
				}
			}
		}
		printf("%d\n", x);
	}
	return 0;
}
