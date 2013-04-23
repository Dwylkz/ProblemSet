#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define MS(c, a) memset(c, a, sizeof(c))
#define MAXN (880000)
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
            for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i ++){
                x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p - 1: p ++;
            }
        }
    }

    void calHeight(int *r, int n)
    {           //  ÇóheightÊý×é¡£
        int i, j, k = 0;
        for(i = 1; i <= n; i ++) rank[sa[i]] = i;
        for(i = 0; i < n; height[rank[i ++]] = k)
            for(k ? k -- : 0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k ++);
    }
} zkl;

int n, id[MAXN];
char buf[MAXN];
int str[MAXN];
string ans;

bool chk(int x, int l)
{
    bool vis[MAXT];
    int cou = 0;

    MS(vis, 0);
    Rep(i, 1, l)
        if (zkl.height[i] < x)
        {
            MS(vis, 0);
            cou = 0;
        }
        else if (id[zkl.sa[i]] < MAXN && id[zkl.sa[i - 1]] < MAXN)
        {
            if (!vis[id[zkl.sa[i - 1]]])
            {
                vis[id[zkl.sa[i - 1]]] = 1;
                cou++;
            }
            if (!vis[id[zkl.sa[i]]])
            {
                vis[id[zkl.sa[i]]] = 1;
                cou++;
            }
            if (cou == n)
            {
                ans = "";
                Rep(j, zkl.sa[i], zkl.sa[i] + x)
                    ans += str[j] + 'a' - 1;
                return 1;
            }
        }
    return 0;
}

int BS(int l, int r, int len)
{
    int m, ans = 0;

    while (l <= r)
    {
        m = (l + r) / 2;
        if (chk(m, len))
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
    int lb, l, bt, maxi;

    while (scanf("%d", &n), n)
    {
        l = 0;
        bt = 29;
        Rep(i, 0, n)
        {
            scanf("%s", buf);
            lb = strlen(buf);
            Rep(j, 0, lb)
            {
                id[l] = i;
                str[l++] = buf[j] - 'a' + 1;
            }
            id[l] = bt;
            str[l++] = bt++;
        }
        str[l++] = 0;
        zkl.ini(str, l, bt);
        puts(BS(0, lb, l)? ans.c_str(): "IDENTITY LOST");
    }

    return 0;
}
