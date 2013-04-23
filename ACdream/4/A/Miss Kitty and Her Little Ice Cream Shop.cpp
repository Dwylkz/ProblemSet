#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (11000000)

int m, a, b, c, d, e, f, g, h, i, j, k;

int H2(int a, int b, int c, int x)
{
    return a * x * x + b * x + c;
}

bool chk(int x)
{
    int pf = 0, cl;

    Rep(tx, 1, x + 1)
    {
        cl = j * tx + k;
        if (cl % 3 < 1) pf += H2(a, b, c, tx);
        else if (cl % 3 < 2) pf += H2(d, e, f, tx);
        else pf += H2(g, h, i, tx);
    }

    return pf >= m;
}

int BS()
{
    int l = 1, r = m, m, ans = -1;

    while (l <= r)
    {
        m = (l + r) >> 1;
        if (chk(m))
        {
            r = m - 1;
            ans = m;
        }
        else l = m + 1;
    }

    return ans;
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int Case;

    scanf("%d", &Case);
    while (Case--)
    {
        scanf("%d%d%d%d%d%d%d%d%d%d%d%d",
              &m, &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k);
        printf("%d\n", BS());
    }
    return 0;
}
