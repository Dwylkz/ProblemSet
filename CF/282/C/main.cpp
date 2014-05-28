#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
using namespace std;
const int MAXN = 10e6+10;

char a[MAXN], b[MAXN];

int main()
{
#if 0
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	while (~scanf("%s%s", a, b)) {
		int ca0 = 0, ca1 = 0, cb0 = 0, cb1 = 0,
			la = strlen(a), lb = strlen(b); 

		if (la != lb) {
			puts("NO");
		}
		else {
			for (int i = 0; i < la; i++) {
				ca0 += (a[i] == '0');
			}
			ca1 = la - ca0;
			for (int i = 0; i < lb; i++) {
				cb0 += (b[i] == '0');
			}
			cb1 = lb - cb0;
			bool yes = 1;
			while (ca1 != cb1) {
#if 0
				printf("ca0 = %d, ca1 = %d, cb0 = %d, cb1 = %d\n",
						ca0, ca1, cb0, cb1);
#endif
				if (ca1 < cb1) {
					if (0 < ca0  && 0 < ca1) {
						ca0--;
						ca1++;
					}	
					else {
						yes = 0;
						break;
					}
				}
				else {
					if (1 < ca1) {
						ca0++;
						ca1--;
					}
					else {
						yes = 0;
						break;
					}
				}
			}
			puts(yes? "YES": "NO");
		}
	}

	return 0;
}
