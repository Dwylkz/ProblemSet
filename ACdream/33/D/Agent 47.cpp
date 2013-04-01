#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
#define LL long long
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c < b; c++)
#define MAXN (0x10000)
#define MAXM (16)
#define Get(x, y) (x & (1 << y))
#define Set(x, y) (x | (1 << y))
#define INFI (0x7fffffff)
#define MOD ()

int n, ha[MAXN], da[MAXM][MAXM], hp[MAXM], md[MAXN][MAXM];
bool inQ[MAXM];

int SCDP()
{
    int lh = (1 << n) - 1;
    fill(ha, ha + MAXN, INFI);
    Rep(s, 0, lh) Rep(i, 0, n) md[s][i] = 1;
    Rep(s, 1, lh) Rep(i, 0, n) if (Get(s, i))
        Rep(j, 0, n) md[s][j] = max(md[s][j], da[i][j]);
    ha[0] = 0;
    Rep(s, 0, lh) Rep(i, 0, n) if (!Get(s, i))
    {
        int ts = Set(s, i);
        ha[ts] = min(ha[ts], ha[s] + hp[i] / md[s][i] + bool(hp[i] % md[s][i]));
    }
    return ha[lh];
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int T;
    char buf[2];

    scanf("%d", &T);
    Rep(C, 1, T + 1)
    {
        scanf("%d", &n);
        Rep(i, 0, n) scanf("%d", hp + i);
        Rep(i, 0, n) Rep(j, 0, n)
        {
            scanf("%1s", buf);
            da[i][j] = buf[0] - '0';
        }
        printf("Case %d: %d\n", C, SCDP());
    }

    return 0;
}
