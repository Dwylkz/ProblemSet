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
namespace Dwylkz{
	//Type
	typedef unsigned int UI;
	typedef long long LL;
	typedef long double LD;
	//Constant
	const LL INFL = ~0ull >> 1;
	const int INFI = 300000;
	const int MAXN = 400005;
	const int MOD = 1e5;
	//Array
	typedef int AI[MAXN];
	typedef bool AB[MAXN];
	typedef double AD[MAXN];
	typedef LL ALL[MAXN];
	typedef LD ALD[MAXN];
}
using namespace Dwylkz;
//STL
#define MS(c, a) memset(c, a, sizeof c)
//Syntax
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
//DEBUG
#define FK puts("Fu*k here!")

double D;
int n;
AB dp;

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lf%d", &D, &n);
		MS(dp, 0);
		dp[MOD] = 1;
		Rep(i, 0, n){
			double dm;
			scanf("%lf", &dm);
			int id = dm * MOD;
			if (dm > 0) Nre(j, INFI - 1, -1) if (dp[j])
				if (j + id < INFI) dp[j + id] = 1;
			if (dm < 0) Rep(j, 0, INFI) if (dp[j])
				dp[j - id] = dp[j];
		}
		double res = 0;
		Rep(i, 0, INFI) if (dp[i])
		{
			double dm = 1.0 * (i - MOD) / MOD;
			if (abs(dm - D) < abs(res - D)) res = dm;
		}
		printf("%.4lf\n", res);
	}
	return 0;
}
