#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
//STL-Alias
#define UN(c, a) unique(c, a)
#define MS(c, a) memset(c, a, sizeof c)
#define FLC(c, a ,b) fill(c, c + a, b)
#define LOS(c, a, b) lower_bound(c, a, b)
#define UPS(c, a, b) upper_bound(c, a, b)
//Syntax-Alias
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
//DEBUG
#define FK puts("Fu*k here!")
#define PA(s, c, a, b, p, f){\
	printf(s);\
	Rep(c, a, b) printf(p, (f));\
	puts("");}
//Constant
#define MAXN (17)
#define INFI (0x7fffffff)
#define MOD (1000000007)
#define HW "Hello, world!"
//Type-Alias
typedef long long LL;
typedef long double LD;
typedef int AI[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];

char s[1000010];
int main()
{
	while (~scanf("%s", s)) {
		int h = 0, l = strlen(s), hl = strlen(HW);
		bool yes = 1;;
		for (int i = 0; i < l / 2; i++) {
			if (s[i] != s[l - i - 1]) {
				yes = 0;
				break;
			}
		}

		for (int i = 0; i < l; i++) {
			if (s[i] == 'H') {
				h++;
			}
#if 0
			if (s[i] == 'H') {
				puts("H");
			} else {
				puts(s);
			}
#endif
		}
		puts(~h & 1? "Yes": "No");
	}
	return 0;
}
