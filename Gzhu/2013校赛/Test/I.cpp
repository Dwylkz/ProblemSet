//Kimady::S.X.Dwylkz
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
//Namespace
namespace dtd{
	//Constant
	const long long INFLL = ~0uLL>>1;
	const int INFI = ~0u>>1;
	const int MAXN = 100;
	const int MAXM = 100;
	const int MOD = 1e+7;
	//Type Definition
	typedef unsigned int UI;
	typedef long long LL;
	typedef long double LD;
	typedef int AI[MAXN];
	typedef bool AB[MAXN];
	typedef double AD[MAXN];
	typedef LL ALL[MAXN];
	typedef LD ALD[MAXN];
	typedef AI AI2[MAXM];
	typedef AB AB2[MAXM];
	typedef AD AD2[MAXM];
	typedef ALL ALL2[MAXM];
	typedef ALD ALD2[MAXM];
}
using namespace std;
using namespace dtd;
//Macro
#define Bug puts("Here")

void enumeral()
{
	int m = 100;
	for (int i = 10; i < m; i++) {
		printf("%6d:", i);
		for (int j = i; j < 10 * i; j++) {
			if (j - j / 10 == i) {
				printf("%6d", j);
			}
			if (i < j - j / 10) {
				break;
			}
		}
		puts("");
	}
}

//Global
LL n;
//Main
int main()
{
#if 0
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif
	//enumeral();
	while (~scanf("%d", &n)) {
		long long m = n + n / 9;
		if (n % 9) {
			printf("%lld", m);
		} else {
			printf("%lld %lld", m - 1, m);
		}
		puts("");
	}
	return 0;
}
