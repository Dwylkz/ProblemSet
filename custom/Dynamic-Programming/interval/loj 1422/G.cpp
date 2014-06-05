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
#define MAXN (110)
#define INFI (0x7fffffff)

int n, C[MAXN], dp[MAXN][MAXN];

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif
	int T;
	scanf("%d", &T);
	Rep(Cas, 1, T + 1)
	{
		scanf("%d", &n);
		MS(dp, 0);
		Rep(i, 1, n + 1) 
		{
			if (i) scanf("%d", C + i);
			dp[i][i] = 1;
		}
		Rep(i, 1, n) Rep(j, 1, n  - i + 1)
		{
			dp[j][i + j] = dp[j][i + j - 1] + 1;
			Rep(k, j, j + i) if (C[i + j] == C[k])
				dp[j][i + j] = min(dp[j][i + j], dp[j][k - 1] + dp[k][i + j - 1]);
		}
		printf("Case %d: %d\n", Cas, dp[1][n]);
	}
	return 0;
}
