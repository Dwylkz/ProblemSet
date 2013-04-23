#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN (4400000)
#define SIGM (512)
typedef int AI[MAXN];

struct SA
{
    AI ws, wa, wb, wv, sa, wd, rank, height;
    void ini(int *r, int l, int m)
    {
        da(r, l, m); calHeight(r, l - 1);
    }
    int cmp(int *r, int a, int b, int l)
    {
        return r[a] == r[b] && r[a + l] == r[b + l];
    }
    void rs(int *r, int *k, int *x, int *y, int n, int m)
    {
        Rep(i, 0, m) r[i] = 0; Rep(i, 0, n) r[k[i]]++;
        Rep(i, 1, m) r[i] += r[i - 1];
        Nre(i, n - 1, -1) x[--r[k[i]]] = y[i];
    }
    void da(int *r, int n, int m)
    {
        int j, p, *x = wa, *y = wb;
        Rep(i, 0, n) x[i] = r[i], y[i] = i;
        rs(wd, x, sa, y, n, m);
        for (j = 1, p = 1; p < n; j *= 2, m = p)
        {
            p = 0; Rep(i, n - j, n) y[p++] = i;
            Rep(i, 0, n) if (sa[i] >= j) y[p++] = sa[i] - j;
            Rep(i, 0, n) wv[i] = x[y[i]];
            rs(wd, wv, sa, y, n, m);
            swap(x, y), p = 1, x[sa[0]] = 0;
            Rep(i, 1, n) x[sa[i]] = cmp(y, sa[i - 1], sa[i], j)? p - 1: p++;
        }
    }
    void calHeight(int *r, int n)
    {
        int i, j, k = 0;
        for (i = 1; i <= n; i++) rank[sa[i]] = i;
        for (i = 0; i < n; height[rank[i++]] = k)
            for (k? k--: 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
    }
} zkl;

char buf[MAXN];
int m, len, lb, str[MAXN];

int chk(int x)
{
    int id = -1;
    Rep(i, 1, len) if (zkl.height[i] >= x)
    {
        int cou = 1, tid = zkl.sa[i - 1];
        for (; i < len && zkl.height[i] >= x; cou++, i++)
            tid = max(tid, zkl.sa[i]);
        if (cou >= m) id = max(id, tid);
    }
    return id;
}
void solve()
{
    if (m == 1)
    {
        printf("%d 0\n", lb);
        return ;
    }
    int l = 1, r = lb, ans = -1, id;
    while (l <= r)
    {
        int x = (l + r) >> 1, tid = chk(x);
        if (tid != -1)
        {
            ans = x;
            id = tid;
            l = x + 1;
        }
        else r = x-  1;
    }
    printf(ans < 0? "none\n": "%d %d\n", ans, id);
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    while (scanf("%d", &m), m)
    {
        scanf("%s", buf);
        lb = strlen(buf);
        len = 0;
        Rep(i, 0, lb) str[len++] = buf[i];
        str[len++] = 0;
        zkl.ini(str, len, SIGM);
        solve();
        #if 0
            Rep(i, 0, len)
            {
                printf(" %4d %4d : ", zkl.sa[i], zkl.height[i]);
                Rep(j, zkl.sa[i], len)
                    printf("%c", str[j]);
                puts("");
            }
        #endif
    }

    return 0;
}
