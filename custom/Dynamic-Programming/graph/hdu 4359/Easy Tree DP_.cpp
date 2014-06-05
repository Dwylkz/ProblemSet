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
#define BUG puts("hoho");
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
#define MAXN (366)
#define MOD (1000000007)
typedef long long LL;

struct BIA
{
    LL t[MAXN];
    BIA()
    {
        memset(t, 0, sizeof t);
    }
    int low(int x)
    {
        return -x & x;
    }
    void upd(int x, LL a)
    {
        for (; x < MAXN; x += low(x))
            t[x] = (t[x] + a) % MOD;
    }
    LL operator []  (int x)
    {
        LL sm = 0;
        for (; x; x -= low(x))
            sm = (sm + t[x]) % MOD;
        return sm;
    }
} dp[MAXN];

int N, D;
LL C[MAXN][MAXN];

int low(int n)
{
    int o = 0;
    while ((1 << o) <= n) o++;
    return o;
}

void dp_ini()
{ 
    C[0][0] = 1;
    Rep(i, 1, MAXN)
    {
        C[i][0] = 1;
        Rep(j, 1, i + 1) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    dp[1].upd(1, 1);
    Rep(n, 2, MAXN) Rep(d, low(n), n + 1)
    {
        LL tp = 0;
        int h = d - 1, o = (h < 9)? 1 << h: n; // Be careful o = 1 << 65 damn!!!
        Rep(x, 1, n - 1)
        {
            int l = x, r = n - 1 - x;
            if (l < o && r < o && (l >= h || r >= h))
            {
                LL tt = dp[l][h] * dp[r][h] % MOD;
                tt = (MOD + tt - dp[l][h - 1] * dp[r][h - 1] % MOD) % MOD;
                tp = (tp + C[n - 2][l] * tt % MOD) % MOD;
            }
        }
        tp += 2 * (dp[n - 1][h] - dp[n - 1][h - 1] + MOD) % MOD;
        dp[n].upd(d, tp % MOD * n % MOD);
    }
}

int main()
{
    int T, Cas = 1;

    dp_ini();
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &N, &D);
        LL res = (dp[N][D] - dp[N][D - 1] + MOD) % MOD;
        printf("Case #%d: %lld\n", Cas++, res);
    }
    return 0;
}
