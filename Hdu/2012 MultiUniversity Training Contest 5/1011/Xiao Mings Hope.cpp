#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (100)

int dp[MAXN][MAXN];

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif
	int n;

	dp[0][0] = 1;
	#if 0
	Rep(i, 1, MAXN)
	{
		int codd = 1;
		dp[i][0] = 1;
		Rep(j, 1, MAXN)
		{
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			if (dp[i][j] & 1) codd++;
		}
		int ti = i;
		while (ti)
		{
		    printf("%d", ti & 1);
		    ti >>= 1;                                                                                                                                                                                                                                                                                                                                                                                                                         1;
		}
		printf(": %d\n", codd);
	}
	#endif
	while (~scanf("%d", &n))
	{
        int o = 1;
        while (n)
        {
            if (n & 1) o <<= 1;
            n >>= 1;
        }
        printf("%d\n", o);
	}
	return 0;
}
