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
typedef long long LL;

struct Vec
{
    double x, y, z;
    Vec(double tx = 0, double ty = 0, double tz = 0)
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
    double y, d, u;
    int a;
    SL(double ty = 0, double td = 0, double tu = 0, int ta = 0)
        : y(ty), d(td), u(tu), a(ta) {}
} _SL;


vector<double> Y;

struct SGT
{
#define ls(x) (x << 1)
#define rs(x) (ls(x) | 1)

    struct Node
    {
        int l, r, c;
        double s[2];
    } t[MAXN << 3];

    SGT()
    {
        bui();
    }

    void upd(int x)
    {
        bool bl = (t[x].l != t[x].r);
        t[x].s[0] = t[x].s[1] = 0;
        if (t[x].c >= 2) t[x].s[1] = Y[t[x].r + 1] - Y[t[x].l];
        else if (t[x].c == 1)
        {
            if (bl) Rep(i, 0, 2) t[x].s[1] += t[ls(x)].s[i] + t[rs(x)].s[i];
            t[x].s[0] = Y[t[x].r + 1] - Y[t[x].l] - t[x].s[1];
        }
        else if (t[x].c == 0 && bl)
            Rep(i, 0, 2) t[x].s[i] = t[ls(x)].s[i] + t[rs(x)].s[i];
    }

    void bui(int l = 0, int r = MAXN - 1, int x = 1)
    {
        t[x].l = l;
        t[x].r = r;
        t[x].c = 0;
        t[x].s[0] = t[x].s[1] = 0;
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

    double que()
    {
        return t[1].s[1];
    }
} zkl;

Cube C[MAXN];
int n;

bool cmp(SL p, SL q)
{
    if (p.y == q.y) p.a > q.a;
    return p.y < q.y;
}

double CV()
{
    double s = 0;
    vector<SL> L;

    Rep(i, 0, n)
    {
        L.push_back(SL(C[i].a.x, C[i].a.y, C[i].b.y, 1));
        L.push_back(SL(C[i].b.x, C[i].a.y, C[i].b.y, -1));
    }
    sort(L.begin(), L.end(), cmp);
    Rep(i, 0, L.size())
    {
        int l = lower_bound(Y.begin(), Y.end(), L[i].d) - Y.begin();
        int r = lower_bound(Y.begin(), Y.end(), L[i].u) - Y.begin();
        zkl.ins(l, r - 1, L[i].a);
        if (i < L.size() - 1) s += zkl.que() * (L[i + 1].y - L[i].y);
    }

    return s;
}

int main()
{
#if  1
    freopen("test.txt", "rt", stdin);
#endif

    int T, Cas = 1;

    scanf("%d", &T);
    while (T--)
    {
        Y.clear();
        scanf("%d", &n);
        Rep(i, 0, n)
        {
            scanf("%lf%lf%lf%lf",
                  &C[i].a.x, &C[i].a.y,
                  &C[i].b.x, &C[i].b.y);
            Y.push_back(C[i].a.y);
            Y.push_back(C[i].b.y);
        }
        sort(Y.begin(), Y.end());
        Y.erase(unique(Y.begin(), Y.end()), Y.end());
        printf("%.2lf\n", CV());
    }

    return 0;
}
