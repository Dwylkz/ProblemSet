#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (44)
#define MAXM (4)
#define INFI (0x7fffffff)
#define ABS(x) ((x) < 0? ((x) * -1): (x))

int n, p, t, dp[MAXN][MAXM];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    while (scanf("%d", &n), n)
    {
        bool NG = 0;
        int pp = 0, pt = 0, pos = 0, mind = INFI;
        Rep(i, 0, n + 1) Rep(j, 0, MAXM) dp[i][j] = INFI;
        dp[0][0] = 0;
        Rep(i, 0, n)
        {
            scanf("%d%d", &p, &t);
            if (NG) continue;
            Rep(k, 0, MAXM) if (dp[i][k] != INFI)
            {
                if (k < MAXM - 1 && ABS(p - pp) * (k + 1) <= t - pt)
                    dp[i + 1][k + 1] = min(dp[i + 1][k + 1], dp[i][k] + ABS(p - pp));
                if (pp * (k + 1) + p <= t - pt)
                    dp[i + 1][1] = min(dp[i + 1][1], dp[i][k] + pp + p);
            }
            NG = 1;
            Rep(k, 0, MAXM) if (dp[i + 1][k] != INFI) NG = 0;
            pos = i;
            pp = p;
            pt = t;
        }
        #if 0
            puts("dp: ");
            Rep(i, 0, n + 1)
            {
                Rep(j, 0, MAXM) printf(" %12d", dp[i][j]);
                puts("");
            }
        #endif
        Rep(i, 0, MAXM) mind = min(mind, dp[n][i]);
        if (NG) printf("NG %d\n", pos + 1);
        else printf("OK %d\n", mind + p);
    }

    return 0;
}
