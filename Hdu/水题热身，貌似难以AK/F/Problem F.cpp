#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (51)
#define INFI (10000)
#define X2(x) (x * x)

int n, s;
double dp[MAXN][MAXN], o[MAXN];

int main()
{
#if 0
    freopen("test.txt", "rt", stdin);
#endif

    memset(dp, 0, sizeof dp);
    o[0] = dp[0][0] = 1;
    Rep(i, 1, MAXN) o[i] = o[i - 1] * 2;
    Rep(i, 1, MAXN) Rep(j, 0, MAXN)
    {
        if (!j) dp[i][j] = 1;
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    }
    while (~scanf("%d%d", &n, &s))
    {
        double tp = 0, tsu = 0;
        Rep(i, 0, s + 1)
        {
            tsu += dp[n][i] * o[n - i];
            if (i == s - 1) tp = tsu;
        }
        printf("%.5lf\n", (double)tp / tsu * 100);
    }

    return 0;
}
