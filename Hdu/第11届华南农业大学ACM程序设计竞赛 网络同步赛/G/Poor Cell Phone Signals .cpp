#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <memory.h>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define Clr(c, a, b) fill(c, c + a, b)
#define MS(c, a) memset(c, a, sizeof(c))
#define LLU long long
#define MAXN (110)
#define MAXT (4400)
#define INFI 0x7fffffff
#define SHIFT (0)

struct Coor
{
    double x, y, r;
} co[MAXN];

double dis(Coor a, Coor b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

struct DLX
{
    #define FF(i, A, s) for (int i = A[s]; i != s; i = A[i])
    #define DXL (MAXN * MAXN)
    #define DXN (MAXN)

    int L[DXL], R[DXL], U[DXL], D[DXL], col[DXL], s[DXN], pre, now, sz, lim;
    bool H[DXN];

    void ini(int n)
    {
        for (int i = 0; i < n; i++)
        {
            U[i] = D[i] = col[i] = i;
            L[i] = i - 1;
            R[i] = i + 1;
        }
        sz = n;
        pre = -1;
        now = 0;
        memset(H, 0, sizeof H);
    }

    void ins(int i, int j)
    {
        if (i != pre)
        {
            R[sz] = now;
            L[now] = sz - 1;
            pre = i;
            now = sz;
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
        R[sz - 1] = now;
        L[now] = sz - 1;
    }

    void xrm(int c)
    {
        L[R[c]] = L[c];
        R[L[c]] = R[c];
        FF(i, D, c) FF(j, R, i)
        {
            U[D[j]] = U[j];
            D[U[j]] = D[j];
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
        L[R[c]] = c;
        R[L[c]] = c;
    }

    bool xdfs(int k)
    {
        int id = R[0];

        if (!R[0]) return 1;
        for (int i = R[0]; i != 0; i = R[i])
            if (s[id] > s[i]) id = i;
        xrm(col[id]);
        FF(i, D, id)
        {
            FF(j, R, i) xrm(col[j]);
            xdfs(k + 1);
            FF(j, L, i) xrs(col[j]);
        }
        xrs(col[id]);

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

        memset(H, 0, sizeof H);
        for (int c = R[0]; c != 0; c = R[c])
            if (!H[c])
            {
                H[c] = 1;
                ret++;
                FF(i, D, c) FF(j, R, i) H[col[j]] = 1;
            }

        return ret;
    }

    bool dfs(int k)
    {
        int id = R[0];

        if (k + h() >= lim) return 0;
        if (R[0] == 0)
        {
            if (k < lim) lim = k;
            return 1;
        }
        for (int i = R[0]; i != 0; i = R[i])
            if (s[id] > s[i]) id = i;
        FF(i, D, id)
        {
            rm(i);
            FF(j, R, i) rm(i);
            if (dfs(k + 1)) return 1;
            FF(j, L, i) rs(i);
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

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif
    int n, maxi, ans;

    while (~scanf("%d", &n))
    {
        puts("fuck");
        dlx.ini(n);
        Rep(i, 0, n) scanf("%lf%lf%lf", &co[i].x, &co[i].y, &co[i].r);
        Rep(i, 0, n) Rep(j, 0, n)
            if (dis(co[i], co[j]) <= co[j].r * co[j].r)
                dlx.ins(i, j);
        dlx.fin();
        printf("%d\n", dlx.astar());
    }

    return 0;
}
