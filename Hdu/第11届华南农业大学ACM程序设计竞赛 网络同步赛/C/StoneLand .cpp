#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define Clr(c, a, b) fill(c, c + a, b)
#define MS(c, a) memset(c, a, sizeof(c))
#define LLU long long
#define MAXN (1100000)
#define MAXT (4400)
#define INFI 0x7fffffff
#define SHIFT (0)

int n, dp[MAXN], co[MAXN];

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif

    int T;

    scanf("%d", &T);
    Rep(C, 0, T)
    {
        scanf("%d", &n);
        Clr(dp, n, INFI);
        dp[0] = 1;
        co[0] = 1;
        Rep(i, 0, n - 1)
        {
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
            if (i + co[i] < n)
                dp[i + co[i]] = min(dp[i + co[i]], dp[i] + 1);
            if (i + i < n)
            {
                dp[i + i] = min(dp[i + i], dp[i] + 3);
                co[i + i] = i;
            }
        }
        printf("Case %d: %d\n", C + 1, dp[n - 1]);
    }

    return 0;
}
