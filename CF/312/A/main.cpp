#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
#define Rep(c, a, b) for (int c = a; c < (b); c++)
int n;
char b[maxn];
int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	for ( ; ~scanf("%d\n", &n); ) {
		for ( ; n--; ) {
			scanf("%[^\n]\n", b);
			bool r = !strncmp(b, "miao.", 5),
				 f = !strncmp(b + strlen(b) - 5, "lala.", 5);
			if (r && f || !r && !f) {
				puts("OMG>.< I don't know!");
			} else if (f) {
				puts("Freda's");
			} else if (r) {
				puts("Rainbow's");
			}
		}
	} 
	return 0;
}
