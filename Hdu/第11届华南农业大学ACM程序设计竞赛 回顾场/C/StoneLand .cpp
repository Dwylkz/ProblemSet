#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory.h>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define MS(c, a) memset(c, a, sizeof c)
#define MAXN (1000001)
#define INFI (0x7fffffff)

int n, dp[MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int T;

    Clr(dp, MAXN, INFI);
    dp[0] = 0;
    dp[1] = 1;
    Rep(i, 1, MAXN)
    {
        if (i + 1 < MAXN) dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        for (int j = i + i, k = 1; j < MAXN; j += i, k++)
            dp[j] = min(dp[j], dp[i] + k + 2);
    }
    scanf("%d", &T);
    Rep(C, 0, T)
    {
        scanf("%d", &n);
        printf("Case %d: %d\n", C + 1, dp[n]);
    }

    return 0;
}
