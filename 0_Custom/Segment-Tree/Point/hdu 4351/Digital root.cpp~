#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
#define MS(a, b) memset(a, b, sizeof a)
#define GB(x, y) (((x) >> (y)) & 1)
#define SB(x, y) ((x) | (1 << (y)))
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN (110000)

struct SGT
{
    #define ls(x) (x << 1)
    #define rs(x) (ls(x) | 1)
    typedef int T1[MAXN << 2];
    typedef int T2[MAXN << 2][10];
    T1 l, r, m, sm;
    T2 lc, rc;
    int E[10][10];
    SGT()
    {
        Rep(i, 0, 10) Rep(j, 0, 10)
            E[i][j] = EC(i + j);
    }
    int EC(int x)
    {
        while (x > 9)
        {
            int sm = 0;
            while (x)
            {
                sm += x % 10;
                x /= 10;
            }
            x = sm;
        }
        return x;
    }
    void bui(int *s, int h, int o, int x = 1)
    {
        l[x] = h;
        r[x] = o;
        m[x] = (h + o) >> 1;
        sm[x] = 0;
        MS(lc[x], -1);
        MS(rc[x], -1);
        if (h == o)
        {
            s[h] = EC(s[h]);
            sm[x] = SB(sm[x], s[h]);
            lc[x][s[h]] = h;
            rc[x][s[h]] = h;
            return ;
        }
        bui(s, h, m[x], ls(x));
        bui(s, m[x] + 1, o, rs(x));
        int ts = 0;
        Rep(i, l[x], r[x] + 1)
        {
            ts = E[ts][s[i]];
            if (lc[x][ts] < 0) lc[x][ts] = i;
        }
        ts = 0;
        Nre(i, r[x], l[x] - 1)
        {
            ts = E[ts][s[i]];
            if (rc[x][ts] < 0) rc[x][ts] = i;
        }
        Rep(i, 0, 10) if (rc[ls(x)][i] != -1)
            Rep(j, 0, 10) if (lc[rs(x)][j] != -1)
                sm[x] = SB(sm[x], E[i][j]);
        sm[x] |= sm[ls(x)] | sm[rs(x)];
    }
    int f5m(int h, int o, int x = 1)
    {
        int ts = 0;
        if (h <= l[x] && r[x] <= o) ts = sm[x];
        else
        {
            if (h <= m[x]) ts |= f5m(h, o, ls(x));
            if (m[x] < o) ts |= f5m(h, o, rs(x));
            Rep(i, 0, 10) if (rc[ls(x)][i] != -1 && h <= rc[ls(x)][i])
                Rep(j, 0, 10) if (lc[rs(x)][j] != -1 && lc[rs(x)][j] <= o)
                    ts = SB(ts, E[i][j]);
        }
        return ts;
    }
} sgt;

int n, q, s[MAXN];

int main()
{
    int T, Cas = 1;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        Rep(i, 0, n) scanf("%d", s + i);
        sgt.bui(s, 0, n - 1);
        scanf("%d", &q);
        printf("Case #%d:\n", Cas++);
        while (q--)
        {
            int l, r, i, ts, ct = 0;
            scanf("%d%d", &l, &r);
            ts = sgt.f5m(l - 1, r - 1);
            for (i = 9; i >= 0; i--)
                if (GB(ts, i))
                {
                    printf("%d", i);
                    ct++;
                    break;
                }
            for (i--; ct < 5 && i >= 0; i--)
                if (GB(ts, i))
                {
                    printf(" %d", i);
                    ct++;
                }
            for (; ct < 5; ct++) printf(" %d", -1);
            puts("");
        }
        if (T) puts("");
    }

    return 0;
}
