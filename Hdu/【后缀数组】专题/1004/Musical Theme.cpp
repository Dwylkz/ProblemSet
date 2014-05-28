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
#define LLU long long
#define MAXN (22000)
#define MAXT (4400)
#define INFI (MAXN)
#define SHIFT (88)

struct SA
{
    int sa[MAXN], rank[MAXN], height[MAXN];
    int wa[MAXN], wb[MAXN], wv[MAXN], wd[INFI];

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

char buf[MAXN];
int len, str[MAXN];

int lcp(int x, int y)
{
    int id;

    x = zkl.rank[x];
    y = zkl.rank[y];
    if (x > y) swap(x, y);
    x++;
    return rmq.que(x, y);

}

bool chk(int x)
{
    int maxi, mini;

    Rep(i, 1, len) if (zkl.height[i] >= x)
    {
        maxi = max(zkl.sa[i], zkl.sa[i - 1]);
        mini = min(zkl.sa[i], zkl.sa[i - 1]);
        for (i++; i < len && zkl.height[i] >= x; i++)
        {
            maxi = max(maxi, zkl.sa[i]);
            mini = min(mini, zkl.sa[i]);
        }
        if (maxi - mini >= x) return true;
    }

    return false;
}

void solve()
{
    int ans, l = 0, mid, r = len;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (chk(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    printf("%d\n", ans < 4? 0: ans + 1);
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int lb, bt;

    while (scanf("%d", &len), len)
    {
        Rep(i, 0, len)
        {
            scanf("%d", str + i);
            if (i > 0) str[i - 1] = str[i] - str[i - 1] + SHIFT;
        }
        str[len - 1] = 0;

        zkl.ini(str, len, INFI);
        #if 0
            Rep(i, 0, len)
            {
                printf(" %d: ", zkl.sa[i]);
                Rep(j, zkl.sa[i], len)
                    printf("%d ", str[j] - SHIFT);
                puts("");
            }
            puts("");
        #endif
        //rmq.ini(zkl.height, l);

        solve();
    }

    return 0;
}
