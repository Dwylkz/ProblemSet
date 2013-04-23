#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define Clr(c, a, b) fill(c, c + a, b)
#define MS(c, a) memset(c, a, sizeof(c))
#define LLU long long
#define MAXN (110000)
#define MAXT (4400)
#define INFI 0x7fffffff
#define SHIFT (0)

struct BIA
{
    int t[MAXN], l;

    void ini(int n)
    {
        l = n;
        Clr(t, n + 1, 0);
    }

    int low(int x)
    {
        return (-x) & x;
    }

    void upd(int x, int add)
    {
        while (x <= l)
        {
            t[x] += add;
            x += low(x);
        }
    }

    int sum(int x)
    {
        int tsu = 0;
        while (x)
        {
            tsu += t[x];
            x -= low(x);
        }
        return tsu;
    }
} bia;

struct SGT
{
    struct Node
    {
        int l, r, ls, rs, mini;
    } t[MAXN << 1];
    int ind;

    void ini(int n)
    {
        bui(0, n, ind = 0);
    }

    void bui(int l, int r, int x = 0)
    {
        int mid = (l + r) / 2;

        t[x].l = l;
        t[x].r = r;
        t[x].mini = INFI;
        t[x].ls = t[x].rs = -1;
        if (l == r) return ;
        if (l <= mid) bui(l, mid, t[x].ls = ++ind);
        if (mid < r) bui(mid + 1, r, t[x].rs = ++ind);
    }

    void upd(int x)
    {
        int ls = t[x].ls, rs = t[x].rs;
        t[x].mini = min(t[ls].mini, t[rs].mini);
    }

    void ins(int k, int tmin, int x = 0)
    {
        int mid = (t[x].l + t[x].r) / 2;

        if (t[x].l == t[x].r)
            t[x].mini = min(t[x].mini, tmin);
        else
        {
            if (k <= mid) ins(k, tmin, t[x].ls);
            else if (mid < k) ins(k, tmin, t[x].rs);
            upd(x);
        }
    }

    int que(int l, int r, int x = 0)
    {
        int mid = (t[x].l + t[x].r) / 2, tmin = INFI;

        if (l <= t[x].l && t[x].r <= r) return t[x].mini;
        else
        {
            if (l <= mid) tmin = min(tmin, que(l, r, t[x].ls));
            if (mid < r) tmin = min(tmin, que(l, r, t[x].rs));
        }

        return tmin;
    }
} sgt;

int n, M[MAXN], id[MAXN];
map<int, int> D;
map<int, int>::iterator beg;

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif
    int T, r, pre, maxi;

    scanf("%d", &T);
    Rep(C, 0, T)
    {
        scanf("%d", &n);
        D.clear();
        Rep(i, 0, n)
        {
            scanf("%d", M + i);
            D[M[i]] = 1;
        }
        r = 0;
        for (beg = D.begin(); beg != D.end(); beg++)
            beg->second = r++;
        sgt.ini(n);
        maxi = 1;
        Rep(i, 0, n)
        {
            r = D[M[i]];
            pre = i;
            if (r > 0) pre = sgt.que(0, r - 1);
            #if 0
                Rep(i, 0, n) printf(" %d", sgt.que(i, i));
                puts("");
            #endif
            if (pre == INFI) pre = i;
            maxi = max(maxi, i - pre + 1);
            sgt.ins(r, i);
        }
        printf("Case %d: %d\n", C + 1, maxi);
    }

    return 0;
}
