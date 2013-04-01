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
//STL
#define MS(c, a) memset(c, a, sizeof c)
//Syntax
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
//DEBUG
#define FK puts("Fu*k here!")
//Type
typedef unsigned int UI;
typedef long long LL;
typedef long double LD;
//Constant
const LL INFL = ~0ull >> 1;
const int INFI = ~0u >> 1;
const int MAXN = 4;
const int MOD = 1000000007;
//Array
typedef int AI[MAXN];
typedef bool AB[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	int s[4];
	while (~scanf("%d%d%d%d", s, s + 1, s + 2, s + 3))
	{
		sort(s, s + 4);
		int l = unique(s, s + 4) - s;
		printf("%d\n", 4 - l);
	}
	return 0;
}
