#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define LLU long long
#define MAXN (55)

int n, m;
LLU dp[MAXN][MAXN];
double p, q, P[MAXN], Q[MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    dp[0][0] = 1;
    Rep(i, 1, 51)
    {
        dp[i][0] = 1;
        Rep(j, 1, i)
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        dp[i][i] = 1;
    }
    #if 0
        Rep(i, 0, 51)
        {
            Rep(j, 0, i + 1)
                printf(" %I64d", dp[i][j]);
            putchar('\n');
        }
    #endif

    while (scanf("%d%d%lf", &n, &m, &p), n || m || p)
    {
        q = 1 - p;
        P[0] = Q[0] = 1;
        Rep(i, 1, n + 1)
        {
            P[i] = P[i - 1] * p;
            Q[i] = Q[i - 1] * q;
        }
        p = 0;
        Rep(i, m, n + 1)
            p += dp[n][i] * P[i] * Q[n - i];
        p *= p;
        q = 1 - p;
        #if 1
            printf("p = %lf q = %lf\n", p, q);
        #endif
        printf("%.6lf\n", 1 + q * q / p);
    }

    return 0;
}
