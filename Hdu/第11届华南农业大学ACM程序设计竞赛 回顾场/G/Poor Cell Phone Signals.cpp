#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory.h>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (110)

struct DLX
{
    #define FF(i, A, s) for (int i = A[s]; i != s; i = A[i])
    #define DXM (MAXN * MAXN)
    #define DXN (MAXN)

    int R[DXM], L[DXM], U[DXM], D[DXM], col[DXM], s[DXN], pre, fir, sz, lim;
    bool hash[DXN];

    void ini(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            U[i] = i;
            D[i] = i;
            col[i] = i;
            L[i] =  i - 1;
            R[i] = i + 1;
        }
        sz = n + 1;
        pre = -1;
        fir = 0;
        memset(s, 0, sizeof s);
    }

    void ins(int i, int j) //注意逐行插入
    {
        if (i != pre)
        {
            R[sz - 1] = fir;
            L[fir] = sz - 1;
            pre = i;
            fir = sz;
        }
        L[sz] = sz - 1;
        R[sz] = sz + 1;
        D[U[j]] = sz;
        D[sz] = j;
        U[sz] = U[j];
        U[j] = sz;
        col[sz] = j;
        s[j]++;
        sz++;
    }

    void fin()
    {
        R[sz - 1] = fir;
        L[fir] = sz - 1;
    }

    void xrm(int c)
    {
        L[R[c]] = L[c];
        R[L[c]] = R[c];
        FF(i, U, c) FF(j, L, i)
        {
            U[D[j]] = j;
            D[U[j]] = j;
            --s[col[j]];
        }
    }

    void xrs(int c)
    {
        FF(i, U, c) FF(j, L, i)
        {
            ++s[col[j]];
            U[D[j]] = j;
            D[U[j]] = j;
        }
    }

    bool xdfs(int k)
    {
        int idx = R[0];

        if (R[0] == 0) return 1;
        for (int i = R[0]; i != 0; i = R[i])
            if (s[idx] > s[i])
                idx = i;
        xrm(col[idx]);
        FF(i, D, idx)
        {
            FF(j, R, i) xrm(col[j]);
            xdfs(k + 1);
            FF(j, L, i) xrs(col[j]);
        }
        xrs(col[idx]);

        return 0;
    }

    void rm(int c)
    {
        FF(i, D, c)
        {
            L[R[i]] = L[i];
            R[L[i]] = R[i];
        }
    }

    void rs(int c)
    {
        FF(i, D, c)
        {
            L[R[i]] = i;
            R[L[i]] = i;
        }
    }

    int h()
    {
        int ret = 0;

        memset(hash, 0, sizeof hash);
        for (int c = R[0]; c != 0; c = R[c]) //c != 0 可修改
            if (!hash[c])
            {
                hash[c] = 1;
                ret++;
                FF(i, D, c) FF(j, R, i) hash[col[j]] = 1;
            }

        return ret;
    }

    bool dfs(int k)
    {
        int idx = R[0];

        if (k + h() >= lim) return 0;
        if (R[0] == 0)
        {
            if (k < lim) lim = lim = k;
            return 1;
        }
        for (int i = R[0]; i != 0; i = R[i])
            if (s[idx] > s[i])
                idx = i;
        FF(i, D, idx)
        {
            rm(i);
            FF(j, R, i) rm(j);
            if (dfs(k + 1)) return 1;
            FF(j, L, i) rs(j);
            rs(i);
        }

        return 0;
    }

    int astar()
    {
        lim = h();
        while (!dfs(0)) lim++;

        return lim;
    }
} dlx;

struct Coor
{
    double x, y, r;
} co[MAXN];

double cdi(Coor a, Coor b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int n;
double x[MAXN], y[MAXN], r[MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    while (~scanf("%d", &n))
    {
        dlx.ini(n);
        Rep(i, 0, n) scanf("%lf%lf%lf", &co[i].x, &co[i].y, &co[i].r);
        Rep(i, 0, n) Rep(j, 0, n)
            if (cdi(co[i], co[j]) <= co[i].r * co[i].r)
                dlx.ins(i + 1, j + 1);
        dlx.fin();
        printf("%d\n", dlx.astar(0));
    }

    return 0;
}
