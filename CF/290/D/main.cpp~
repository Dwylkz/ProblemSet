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
//Type-Alias
typedef long long LL;
typedef long double LD;
typedef int AI[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];

int main()
{
#if 0
	freopen("input.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	char s[100];
	int a, sl;
	scanf("%s%d", s, &a);
	sl = strlen(s);
	for (int i = 0; i < sl; i++) {
		if (s[i] < 'a') {
			s[i] += 32;
		}
	}
	for (int i = 0; i < sl; i++) {
		char b = s[i];
		if (b < a + 97) {
			s[i] = b - 32;
		}
	}
	printf("%s\n", s);
	return 0;
}
