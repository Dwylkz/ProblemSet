#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXC (50)
#define MAXT (2000)
#define MAXI (0x7fffffff)

struct DPS
{
    int w, p;
} dp[MAXC][MAXT];

int z, c, t, l;

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int p, e, mini;

    scanf("%d", &z);
    while (z--)
    {
        scanf("%d%d%d", &c, &t, &l);
        Rep(i, 0, t)
            dp[0][i].w = dp[0][i].p = 0;
        Rep(i, 1, c + 1)
            Rep(j, 0, t)
            {
                scanf("%d%d", &p, &e);
                dp[i][j].w = MAXI;
                dp[i][j].p = p;
                Rep(k, 0, t)
                    if (dp[i][j].w > abs(dp[i - 1][k].p - p) + e + dp[i - 1][k].w)
                        dp[i][j].w = abs(dp[i - 1][k].p - p) + e + dp[i - 1][k].w;
            }
        mini = MAXI;
        Rep(i, 0, t)
            if (mini > dp[c][i].w + l - dp[c][i].p)
                mini = dp[c][i].w + l - dp[c][i].p ;
        printf("%d\n", mini);
    }

    return 0;
}
