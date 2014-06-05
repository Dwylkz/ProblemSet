#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
using namespace std;
const int maxn = 100;
typedef long long LL;
#define Rep(c, a, b) for (int c = a; c < (b); c++)
int k;
int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d", &k)) {
		LL n = 0;
		for (int i = 0; i < k; i++) {
			int ai;
			scanf("%d", &ai);
			n += ai;
		}
		printf("%I64d\n", n);
	} 
	return 0;
}
