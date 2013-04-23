#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (66000)
#define MAXM (6)
typedef long long LL;
typedef int AI[MAXN];

struct Vec
{
    int x, y, z;
    Vec(int tx = 0, int ty = 0, int tz = 0)
    : x(tx), y(ty), z(tz) {}
} _Vec;

struct RT
{
    Vec a, b;
    RT(Vec ta = _Vec, Vec tb = _Vec)
    : a(ta), b(tb) {}
} _RT;

struct SL
{
    int x, d, u, a;
    SL(int tx = 0, int td = 0, int tu = 0, int ta = 0)
    : x(tx), d(td), u(tu), a(ta) {}
    friend bool operator < (SL p, SL q)
    {
        if (p.x != q.x) return p.x < q.x;
        return p.a > q.a;
    }
} _SL;

AI p, Y, Z;
int n, m, ZL, YL;
RT rt[MAXN];

struct SGT
{
    #define ls(x) (x << 1)
    #define rs(x) (ls(x) | 1)
    #define ML ((l + r) >> 1)
    #define TL l, ML, ls(x)
    #define TN l, r, x
    #define TR ML + 1, r, rs(x)
    typedef int TI[MAXN << 2];
    TI c, s;
    void cls()
    {
        memset(c, 0, sizeof c);
        memset(s, 0, sizeof s);
    }
    void ins(int h, int o, int a, int l, int r, int x = 1)
    {
        if (h <= l && r <= o) c[x] += a;
        else
        {
            if (h <= ML) ins(h, o, a, TL);
            if (ML < o) ins(h, o, a, TR);
        }
        if (c[x]) s[x] = Y[r + 1] - Y[l];
        else s[x] = s[ls(x)] + s[rs(x)];
    }
} zkl;

LL WTF()
{
    LL ans = 0;

    Rep(j, 0, ZL - 1)
    {
        int slL = 0;
        static SL sl[MAXN];
        Rep(i, 0, n) if (rt[i].a.z <= Z[j] && Z[j] < rt[i].b.z)
        {
            sl[slL++] = SL(rt[i].a.x, rt[i].a.y, rt[i].b.y, 1);
            sl[slL++] = SL(rt[i].b.x, rt[i].a.y, rt[i].b.y, -1);
        }
        zkl.cls();
        sort(sl, sl + slL);
        LL s = 0;
        Rep(i, 0, slL)
        {
            int l = lower_bound(Y, Y + YL, sl[i].d) - Y,
                r = lower_bound(Y, Y + YL, sl[i].u) - Y;
            zkl.ins(l, r - 1, sl[i].a, 0, YL - 1);
            if (i < slL - 1) s += 1LL * zkl.s[1] * (sl[i + 1].x - sl[i].x);
        }
        ans += s * (Z[j + 1] - Z[j]);
    }

    return ans;
}

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif

    int Test, Case = 1;

    scanf("%d", &Test);
    while (Test--)
    {
        YL = ZL = 0;
        scanf("%d%d", &n, &m);
        Rep(i, 0, m) scanf("%d", p + i);
        Rep(i, 0, n)
        {
            int z;
            scanf("%d%d%d%d%d",
                  &rt[i].a.x, &rt[i].a.y,
                  &rt[i].b.x, &rt[i].b.y,
                  &z);
            rt[i].a.z = 0;
            rt[i].b.z = p[z - 1];
            Y[YL++] = rt[i].a.y;
            Y[YL++] = rt[i].b.y;
            Z[ZL++] = rt[i].a.z;
            Z[ZL++] = rt[i].b.z;
        }
        sort(Y, Y + YL);
        YL = unique(Y, Y + YL) - Y;
        sort(Z, Z + ZL);
        ZL = unique(Z, Z + ZL) - Z;
        printf("Case %d: %I64d\n", Case++, WTF());
    }

    return 0;
}
