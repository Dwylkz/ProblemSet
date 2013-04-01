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
using namespace std;
#define MS(c, a) memset(c, a, sizeof c)
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
#define MAXN (2020)
#define MOD (100000007)
typedef long long LL;

LL dp[MAXN][MAXN][3];
int n, k;

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif
	dp[1][1][0] = dp[1][2][1] = dp[1][1][2] = dp[1][2][2] = 1;
	Rep(i, 2, 1010) Rep(j, 1, i * 2 + 1)
	{
		int k = i - 1;
		dp[i][j][0] = (dp[k][j][0] + dp[k][j - 1][2] + 2 * dp[k][j][1]) % MOD;
		dp[i][j][1] = (2 * dp[k][j - 1][2] + dp[k][j][1]) % MOD;
		if (j > 2) dp[i][j][1] = (dp[i][j][1] + dp[k][j - 2][2]) % MOD;
		dp[i][j][2] = (dp[i][j][0] + dp[i][j][1]) % MOD;
	}
#if 0
	Rep(i, 1, 6)
	{
		Rep(j, 1, 2 * i + 1) printf("(%3lld, %3lld)", dp[i][j][0], dp[i][j][1]);
		puts("");
	}
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		printf("%lld\n", dp[n][k][2]);
	}
	return 0;
}
