#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <memory.h>
#include <algorithm>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (5500)
#define MAXM (55000)

struct BIA
{
    int lt, t[MAXN];

    void ini(int n)
    {
        memset(t, 0, sizeof t);
        lt = n;
    }

    int low(int x)
    {
        return x & (-x);
    }

    void upd(int x, int add)
    {
        while (x <= lt)
        {
            t[x] += add;
            x += low(x);
        }
    }

    int que(int x)
    {
        int tsu = 0;

        while (x)
        {
            tsu += t[x];
            x -= low(x);
        }

        return tsu;
    }
};

struct BIA2
{
    int lt;
    BIA t[MAXN];

    void ini(int n, int m)
    {
        lt = n;
        for (int i = 0; i <= n; i++)
            t[i].ini(m);
    }

    int low(int x)
    {
        return x & (-x);
    }

    void upd(int x, int y, int add)
    {
        while (x <= lt)
        {
            t[x].upd(y, add);
            x += low(x);
        }
    }

    int que(int x, int y)
    {
        int tsu = 0;

        while (x)
        {
            tsu += t[x].que(y);
            x -= low(x);
        }

        return tsu;
    }
} zkl;

struct Maxtri
{
    int lx, ly, ux, uy;
} C[MAXM], Q[MAXN];

map<int, int> Dx, Dy;
map<int ,int>::iterator beg;
int n, k, x[MAXN], y[MAXN], xle, yle;

int LBS(int *s, int x, int l, int r)
{
    int ans;

    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (s[m] >= x)
        {
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }

    return ans;
}

int RBS(int *s, int x, int l, int r)
{
    int ans;

    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (s[m] <= x)
        {
            ans = m;
            l = m + 1;
        }
        else r = m - 1;
    }

    return ans;
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int lx, ly, ux, uy, Case;

    while (scanf("%d", &n), n)
    {
        Case = 1;
        Rep(i, 0, n) scanf("%d%d%d%d", &C[i].lx, &C[i].ly, &C[i].ux, &C[i].uy);
        scanf("%d", &k);
        Dx.clear();
        Dy.clear();
        Rep(i, 0, k)
        {
            scanf("%d%d%d%d", &Q[i].lx, &Q[i].ly, &Q[i].ux, &Q[i].uy);
            Dx[Q[i].lx] = 1;
            Dx[Q[i].ux] = 1;
            Dy[Q[i].ly] = 1;
            Dy[Q[i].uy] = 1;
        }
        for (xle = 0, beg = Dx.begin(); beg != Dx.end(); beg++)
            x[xle++] = beg->first;
        for (yle = 0, beg = Dy.begin(); beg != Dy.end(); beg++)
            y[yle++] = beg->first;
        lx = x[0];
        ly = y[0];
        ux = x[xle - 1];
        uy = y[yle - 1];
        #if 1
            printf(" x :");
            Rep(i, 0, xle) printf(" %d", x[i]);
            printf("\n y :");
            Rep(i, 0, yle) printf(" %d", y[i]);
            printf("\n d :");
            Rep(i, 0, (yle > xle? yle: xle)) printf(" %d", i + 1);
            puts("");
        #endif

        zkl.ini(xle + 1, yle + 1);
        Rep(i, 0, n)
        {
            int a = C[i].lx, b = C[i].ly, c = C[i].ux, d = C[i].uy;

            if (a > ux || c < lx || b > uy || d < ly) continue;
            if (a < lx) a = lx;
            if (c > ux) c = ux;
            if (b < ly) b = ly;
            if (d > uy) d = uy;
            #if 1
                printf(" (%3d, %3d)(%3d, %3d)", a, b, c, d);
            #endif
            a = RBS(x, a, 0, xle - 1) + 2;
            c = LBS(x, c, 0, xle - 1) + 2;
            b = RBS(y, b, 0, yle - 1) + 2;
            d = LBS(y, d, 0, yle - 1) + 2;
            #if 1
                printf("-> (%3d, %3d)(%3d, %3d)\n", a, b, c, d);
            #endif
            Rep(i, a, c + 1)
            {
                zkl.upd(a, b - 1, -1);
                zkl.upd(c, d, 1);
                zkl.upd(c, d + 1, -1);
            }
        }
        Rep(i, 0, k)
        {
            int a = Q[i].lx, b = Q[i].ly, c = Q[i].ux, d = Q[i].uy, tsu = 0;

            #if 1
                printf("  (%3d, %3d)(%3d, %3d)", a, b, c, d);
            #endif
            a = RBS(x, a, 0, xle - 1) + 2;
            c = LBS(x, c, 0, xle - 1) + 2;
            b = RBS(y, b, 0, yle - 1) + 2;
            d = LBS(y, d, 0, yle - 1) + 2;
            tsu = zkl.que(a - 1, b - 1) - zkl.que(a - 1, d) - zkl.que(c, b - 1) + zkl.que(c, d);
            #if 1
                printf("-> (%3d, %3d)(%3d, %3d)\n", a, b, c, d);
                printf("  tsu = %d\n", tsu);
            #endif
            printf("Case #%d : ", Case++);
            puts(tsu? "Yes": "No");
        }
    }

    return 0;
}
