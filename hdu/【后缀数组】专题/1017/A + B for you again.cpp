#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define MS(c, a) memset(c, a, sizeof(c))
#define MAXN (220000)
#define MAXT (4400)
#define INFI (512)

struct SA
{
    int sa[MAXN], rank[MAXN], height[MAXN];
    int wa[MAXN], wb[MAXN], wv[MAXN], wd[MAXN];

    int cmp(int *r, int a, int b, int l)
    {
        return r[a] == r[b] && r[a+l] == r[b+l];
    }

    void ini(int *r, int l, int m)
    {
        da(r, l, m);
        calHeight(r, l - 1);
    }

    void da(int *r, int n, int m)
    {
        int i, j, p, *x = wa, *y = wb, *t;
        for(i = 0; i < m; i ++) wd[i] = 0;
        for(i = 0; i < n; i ++) wd[x[i]=r[i]] ++;
        for(i = 1; i < m; i ++) wd[i] += wd[i-1];
        for(i = n-1; i >= 0; i --) sa[-- wd[x[i]]] = i;
        for(j = 1, p = 1; p < n; j *= 2, m = p)
        {
            for(p = 0, i = n-j; i < n; i ++) y[p ++] = i;
            for(i = 0; i < n; i ++) if(sa[i] >= j) y[p ++] = sa[i] - j;
            for(i = 0; i < n; i ++) wv[i] = x[y[i]];
            for(i = 0; i < m; i ++) wd[i] = 0;
            for(i = 0; i < n; i ++) wd[wv[i]] ++;
            for(i = 1; i < m; i ++) wd[i] += wd[i-1];
            for(i = n-1; i >= 0; i --) sa[-- wd[wv[i]]] = y[i];
            for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i ++)
                x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p - 1: p ++;
        }
    }

    void calHeight(int *r, int n)
    {
        int i, j, k = 0;
        for(i = 1; i <= n; i ++) rank[sa[i]] = i;
        for(i = 0; i < n; height[rank[i ++]] = k)
            for(k ? k -- : 0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k ++);
    }
} zkl;

struct ST
{
    int t[20][MAXN];

    int low(int x)
    {
        int c = 0;
        while ((1 << c) <= x) c++;
        return c;
    }

    void ini(int *S, int len)
    {
        int tp, l = low(len);

        Rep(i, 0, len) t[0][i] = S[i];
        Rep(i, 1, l) Rep(j, 0, len)
        {
            tp = (1 << i >> 1);
            if (j + tp < len)
                t[i][j] = min(t[i - 1][j], t[i - 1][j + tp]);
        }
    }

    int que(int l, int r)
    {
        int j, tp;

        if (l > r) swap(l, r);
        j = low(r - l + 1) - 1;
        tp = (1 << j);
        return min(t[j][l], t[j][r - tp + 1]);
    }
} rmq;

char A[MAXN], B[MAXN];
int la, lb, l, str[MAXN];

int lcp(int x, int y)
{
    int id;

    x = zkl.rank[x];
    y = zkl.rank[y];
    if (x > y) swap(x, y);
    x++;
    return rmq.que(x, y);

}

string s1, s2;

void solve()
{
    int maxi;

    s1.clear();
    maxi = 0;
    Rep(i, 0, la)
    {
        maxi = lcp(i, la + 1);
        if (maxi == la - i) break;
    }
    Rep(i, 0, la) s1 += A[i];
    Rep(i, maxi, lb) s1 += B[i];

    s2.clear();
    maxi = 0;
    Rep(i, 0, lb)
    {
        maxi = lcp(0, la + 1 + i);
        if (maxi == lb - i) break;
    }
    Rep(i, 0, lb) s2 += B[i];
    Rep(i, maxi, la) s2 += A[i];

    if (s1.length() == s2.length())
    puts(s1 < s2? s1.c_str(): s2.c_str());
    else puts(s1.length() < s2.length()? s1.c_str(): s2.c_str());
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int bt;

    while (~scanf("%s%s", A, B))
    {
        l = 0;
        la = strlen(A);
        lb = strlen(B);
        Rep(i, 0, la) str[l++] = A[i] - 'a' + 1;
        str[l++] = 28;
        Rep(i, 0, lb) str[l++] = B[i] - 'a' + 1;
        str[l++] = 0;

        zkl.ini(str, l, 29);
        rmq.ini(zkl.height, l);

        solve();
    }

    return 0;
}
