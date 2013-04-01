#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define MAXN (100001)

int n, q, T[MAXN], S[MAXN], I[MAXN], J[MAXN];

struct SGT
{
    struct Node
    {
        int l, r, ls, rs, c, s;

        void upc()
        {
            s = c * (r - l + 1);
        }
    } t[MAXN << 1];
    int ind;

    void ini()
    {
        bui(0, MAXN, ind = 0);
    }

    void bui(int l, int r, int x)
    {
        int mid = (l + r) / 2;

        t[x].l = l;
        t[x].r = r;
        t[x].c = t[x].s = 0;
        if (t[x].l == t[x].r) return ;
        if (t[x].l <= mid) bui(l, mid, t[x].ls = ++ind);
        if (mid < t[x].r) bui(mid + 1, r, t[x].rs = ++ind);
    }

    void pus(int x)
    {
        int ls = t[x].ls, rs = t[x].rs;

        if (t[x].c != -1)
        {
            t[ls].c = t[rs].c = t[x].c;
            t[ls].upc();
            t[rs].upc();
        }
        t[x].c = -1;
    }

    void upd(int x)
    {
        int ls = t[x].ls, rs = t[x].rs;

        t[x].s = t[ls].s + t[rs].s;
        if (t[ls].c == t[rs].c)
            t[x].c = t[ls].c;
    }

    void ins(int l, int r, int tc, int x = 0)
    {
        int mid = (t[x].l + t[x].r) / 2;

        if (l <= t[x].l && t[x].r <= r)
        {
            t[x].c = tc;
            t[x].upc();
        }
        else
        {
            pus(x);
            if (l <= mid) ins(l, r, tc, t[x].ls);
            if (mid < r) ins(l, r, tc, t[x].rs);
            upd(x);
        }
    }

    int que(int l, int r, int x = 0)
    {
        int mid = (t[x].l + t[x].r) / 2, ans = 0;

        if (l <= t[x].l && t[x].r <= r)
            return t[x].s;
        else
        {
            pus(x);
            if (l <= mid) ans += que(l, r, t[x].ls);
            if (mid < r) ans += que(l, r, t[x].rs);
            upd(x);
        }

        return ans;
    }
} zkl;

struct Que
{
    int x, y, w;
} Q[MAXN];

int n, q, T[MAXN], id[MAXN], ans[MAXN];
vector<int> H[MAXN];

bool cmp(int a, int b)
{
    return Q[a].w < Q[b].w;
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int pre, ind, w;

    zkl.ini();
    while (~scanf("%d%d", &n, &q))
    {
        Rep(i, 0, MAXN) H[i].clear();
        Rep(i, 0, n)
        {
            scanf("%d", T + i);
            H[T[i]].push_back(i);
        }
        Rep(i, 0, q)
        {
            id[i] = i;
            scanf("%d%d%d", &Q[i].x, &Q[i].y, &Q[i].w);
            Q[i].x--;
            Q[i].y--;
        }
        sort(id, id + q, cmp);
        pre = 0;
        Rep(i, 0, q)
        {
            ind = id[i];
            if (Q[ind].w != pre)
            {
                w = Q[ind].w;
                zkl.ins(0, MAXN, 0);
                Rep(j, 0, H[w].size())
                    zkl.ins(H[w][j], H[w][j], 1);
                pre = w;
            }
            ans[ind] = zkl.que(Q[ind].x, Q[ind].y);
        }
        Rep(i, 0, q) printf("%d\n", ans[i]);
    }

    return 0;
}
