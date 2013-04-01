#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
#define MAXN (55000)

struct SGT
{
    #define ls(x) (x << 1)
    #define rs(x) (ls(x) | 1)
    typedef int TI[MAXN << 2];
    TI l, m, r, ln, ma, c, lc, mc, rc;
    void bui(int h, int o, int x = 1)
    {
        l[x] = h, m[x] = (h + o) >> 1, r[x] = o;
        ln[x] = o - h + 1;
        c[x] = 1;
        set(1, x);
        if (h == o) return ;
        if (h <= m[x]) bui(h, m[x], ls(x));
        if (m[x] < o) bui(m[x] + 1, o, rs(x));
    }
    void set(int tc, int x)
    {
        c[x] = tc;
        ma[x] = lc[x] = mc[x] = rc[x] = tc? ln[x]: 0;
    }
    void pus(int x)
    {
        if (c[x] < 0 || l[x] == r[x]) return ;
        set(c[x], ls(x));
        set(c[x], rs(x));
        c[x] = -1;
    }
    void upd(int x)
    {
        c[x] = (c[ls(x)] == c[rs(x)])? c[ls(x)]: -1;
        lc[x] = lc[ls(x)] + lc[rs(x)] * (c[ls(x)] > 0);
        rc[x] = rc[rs(x)] + rc[ls(x)] * (c[rs(x)] > 0);
        ma[x] = mc[x] = rc[ls(x)] + lc[rs(x)];
        ma[x] = max(ma[x], max(ma[ls(x)], ma[rs(x)]));
    }
    void ins(int h, int o, int tc, int x = 1)
    {
        if (h <= l[x] && r[x] <= o) set(tc, x);
        else
        {
            pus(x);
            if (h <= m[x]) ins(h, o, tc, ls(x));
            if (m[x] < o) ins(h, o, tc, rs(x));
            upd(x);
        }
    }
    int que(int d, int x = 1)
    {
        int ind = 0;
        pus(x);
        if (ma[ls(x)] >= d) ind = que(d, ls(x));
        else if (mc[x] >= d) ind = l[rs(x)] - rc[ls(x)];
        else if (ma[rs(x)] >= d) ind = que(d, rs(x));
        upd(x);
        return ind;
    }
} zkl;

int n, m;

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int op, xi, di;

    scanf("%d%d", &n, &m);
    zkl.bui(1, n);
    while (m--)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d", &di);
            xi = zkl.que(di);
            if (xi) zkl.ins(xi, xi + di - 1, 0);
            printf("%d\n", xi);
        }
        else
        {
            scanf("%d%d", &xi, &di);
            zkl.ins(xi, xi + di - 1, 1);
        }
    }

    return 0;
}
