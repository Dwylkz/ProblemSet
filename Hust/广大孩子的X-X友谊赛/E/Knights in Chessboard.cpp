#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (400)

int m, n, dp[MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int T, i, ans;

    scanf("%d", &T);
    dp[i = 1] = 2;
    while (i <= 200)
    {
        i++;
        dp[i] = dp[i - 1] + 2;
        i++;
        dp[i] = dp[i - 1];
        i++;
        dp[i] = dp[i - 1];
        i++;
        dp[i] = dp[i - 1] + 2;
    }
    #if 0
        Rep(i, 0, 201)
            printf("dp[%d] = %d\n", i, dp[i]);
        putchar('\n');
    #endif
    Rep(C, 0, T)
    {
        scanf("%d%d", &m, &n);
        if (m > n) swap(m, n);
        if (m == 1) ans = n;
        else if (m == 2) ans = dp[n];
        else if (m % 2) ans = n / 2 * m + n % 2 * (m / 2 + 1);
        else ans = m * n / 2;
        printf("Case %d: %d\n", C + 1, ans);
    }

    return 0;
}
