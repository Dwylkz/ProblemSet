#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (2200)
#define INFI (0x7fffffff)
#define SHFT (500)
typedef __int64 LL;

struct Vec
{
    int x, y, z;
    Vec(int tx = 0, int ty = 0, int tz = 0)
        : x(tx), y(ty), z(tz) {}
} _Vec;

struct Cube
{
    Vec a, b;
    Cube(Vec ta = _Vec, Vec tb = _Vec)
        : a(ta), b(tb) {}
} _Cube;

struct SL
{
    int y, d, u, a;
    SL(int ty = 0, int td = 0, int tu = 0, int ta = 0)
        : y(ty), d(td), u(tu), a(ta) {}
} _SL;


vector<int> X, Z;

struct SGT
{
#define ls(x) (x << 1)
#define rs(x) (ls(x) | 1)

    struct Node
    {
        int l, r, c, s[3];
    } t[MAXN << 2];

    SGT()
    {
        bui();
    }

    void upd(int x)
    {
        bool bl = (t[x].l != t[x].r);
        int d = t[x].c? (t[x].r + 1 - t[x].l): 0;
        memset(t[x].s, 0, sizeof t[x].s);
        if (t[x].c >= 3) t[x].s[2] = d;
        else if (t[x].c == 2)
        {
            if (bl) Rep(i, 0, 3) t[x].s[2] += t[ls(x)].s[i] + t[rs(x)].s[i];
            t[x].s[1] = d - t[x].s[2];
        }
        else if (t[x].c == 1)
        {
            if (bl)
            {
                Rep(i, 1, 3) t[x].s[2] += t[ls(x)].s[i] + t[rs(x)].s[i];
                t[x].s[1] = t[ls(x)].s[0] + t[rs(x)].s[0];
            }
            t[x].s[0] = d - t[x].s[1] - t[x].s[2];
        }
        else if (t[x].c == 0 && bl) Rep(i, 0, 3)
            t[x].s[i] = t[ls(x)].s[i] + t[rs(x)].s[i];
    }

    void bui(int l = 0, int r = MAXN - 1, int x = 1)
    {
        t[x].l = l;
        t[x].r = r;
        t[x].c = 0;
        t[x].s[0] = t[x].s[1] = t[x].s[2] = 0;
        if (l == r) return ;
        int m = (l + r) >> 1;
        if (l <= m) bui(l, m, ls(x));
        if (m < r) bui(m + 1, r, rs(x));
    }

    void ins(int l, int r, int a, int x = 1)
    {
        if (l <= t[x].l && t[x].r <= r) t[x].c += a;
        else
        {
            int m = (t[x].l + t[x].r) >> 1;
            if (l <= m) ins(l, r, a, ls(x));
            if (m < r) ins(l, r, a, rs(x));
        }
        upd(x);
    }

    int que()
    {
        return t[1].s[2];
    }
} zkl;

Cube C[MAXN];
int n;

bool cmp(SL p, SL q)
{
    if (p.y == q.y) p.a > q.a;
    return p.y < q.y;
}

LL CV()
{
    LL v = 0;
    vector<SL> L;

    Rep(i, 0, X.size() - 1)
    {
        L.clear();
        Rep(j, 0, n) if (C[j].a.x <= X[i] && X[i] < C[j].b.x)
        {
            L.push_back(SL(C[j].a.y, C[j].a.z, C[j].b.z, 1));
            L.push_back(SL(C[j].b.y, C[j].a.z, C[j].b.z, -1));
        }
        zkl.bui();
        sort(L.begin(), L.end(), cmp);
        LL s = 0;
        Rep(j, 0, L.size())
        {
            zkl.ins(L[j].d + SHFT, L[j].u - 1 + SHFT, L[j].a);
            if (j < L.size() - 1) s += 1LL * zkl.que() * (L[j + 1].y - L[j].y);
        }
        v += s * (X[i + 1] - X[i]);
    }

    return v;
}

int main()
{
#if  1
    freopen("test.txt", "rt", stdin);
#endif

    int Cas, Cor[6];

    scanf("%d", &Cas);
    Rep(CCa, 1, Cas + 1)
    {
        X.clear();
        scanf("%d", &n);
        Rep(i, 0, n)
        {
            scanf("%d%d%d%d%d%d",
                  &C[i].a.x, &C[i].a.y, &C[i].a.z,
                  &C[i].b.x, &C[i].b.y, &C[i].b.z);
            X.push_back(C[i].a.x);
            X.push_back(C[i].b.x);
        }
        sort(X.begin(), X.end());
        X.erase(unique(X.begin(), X.end()), X.end());
        printf("Case %d: %I64d\n", CCa, CV());
    }

    return 0;
}
