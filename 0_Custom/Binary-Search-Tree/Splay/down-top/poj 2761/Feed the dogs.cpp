#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (110000)

typedef struct Node
{
    int ky, ct, sz;
    Node *s[2], *p;
} *PNode, Node;
struct SLY
{
    Node t[MAXN];
    int id;
    PNode rt;
    PNode ini()
    {
        id = 0;
        return rt = 0;
    }
    PNode cre(int key, PNode p = 0)
    {
        PNode x = t + id++;
        x->ky = key;
        x->p = p;
        x->s[0] = x->s[1] = 0;
        x->sz = x->ct = 1;
        return x;
    }
    PNode rot(PNode x, bool b)
    {
        PNode y = x->s[!b];
        x->s[!b] = y->s[b];
        if (y->s[b]) y->s[b]->p = x;
        y->p = x->p;
        if (!x->p) rt = y;
        else x->p->s[x->p->s[0] != x] = y;
        y->s[b] = x;
        x->p = y;
        return upd(x);
    }
    PNode sly(PNode x, PNode y = 0)
    {
        while (x->p != y)
        {
            bool bp = x->p->s[0] != x;
            if (x->p->p == y)
            {
                rot(x->p, !bp);
                break;
            }
            bool bg = x->p->p->s[0] != x->p;
            if (bg ^ bp) rot(x->p, bg);
            else rot(x->p->p, !bg);
            rot(x->p, !bg);
        }
        return upd(x);
    }
    PNode upd(PNode x)
    {
        x->sz = 1 + (x->s[0]? x->s[0]->sz: 0) + (x->s[1]? x->s[1]->sz: 0);
        return x;
    }
    PNode ias(int key, bool ios = 0)
    {
        if (!rt)
        {
            if (ios) rt = cre(key);
            return rt;
        }
        bool lr;
        PNode y = 0, x = rt;
        while (x && key != x->ky)
        {
            y = x;
            x = x->s[lr = key > x->ky];
        }
        if (ios) if (!x)
            y->s[lr] = x = cre(key, y);
        else if (x->s[1])
        {
            x = ext(x->s[1], 0);
            x = x->s[0] = cre(key, x);
        }
        else x = x->s[1] = cre(key, x);
        //else x->ct++;
        if (x) sly(x);
        return x;
    }
    PNode del(PNode x)
    {
        if (!x) return x;
        if (--x->ct) return x;
        sly(x);
        if (rt->s[0])
        {
            sly(ext(rt->s[0], 1));
            rt->s[1] = rt->s[1]->s[1];
            if (rt->s[1]) rt->s[1]->p = rt;
        }
        else
        {
            if (rt->s[1]) rt->s[1]->p = 0;
            rt = rt->s[1];
        }
        return rt;
    }
    PNode ext(PNode x, bool b)
    {
        while (x && x->s[b]) x = x->s[b];
        return x;
    }
    PNode bui(int l, int r, int *key, PNode p)
    {
        int m = (l + r) >> 1;
        PNode x = cre(key[m], p);
        if (l < m) x->s[0] = bui(l, m - 1, key, x);
        if (m < r) x->s[1] = bui(m + 1, r, key, x);
        upd(x);
        return x;
    }
    PNode pul(int siz, PNode y = 0)
    {
        if (siz > rt->sz) return 0;
        PNode x = rt;
        int tsz = 1 + (x->s[0]? x->s[0]->sz: 0);
        while (tsz != siz)
        {
            bool b = siz > tsz;
            siz -= b * tsz;
            x = x->s[b];
            tsz = 1 + (x->s[0]? x->s[0]->sz: 0);
        }
        sly(x, y);
        return x;
    }
    void tra(PNode x)
    {
        if (x->s[0]) tra(x->s[0]);
        printf(" %4d -> (%4d, %4d) sz = %d\n",
               x->ky,
               x->s[0]? x->s[0]->ky: 0,
               x->s[1]? x->s[1]->ky: 0,
               x->sz);
        if (x->s[1]) tra(x->s[1]);
    }
} zkl;

struct Vec
{
    int x,  y;
    friend bool operator < (Vec p, Vec q)
    {
        if (p.x != q.x) return p.x < q.x;
        else return p.y < q.y;
    }
} ;
struct Que: Vec
{
    int k, num;
} q[MAXN];
int n, m, d[MAXN], ans[MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    scanf("%d%d", &n, &m);
    Rep(i, 0, n) scanf("%d", d + i);
    zkl.ini();
    Rep(i, 0, m)
    {
        scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].k);
        q[i].num = i;
    }
    sort(q, q + m);
    int i = 0, j = 0, k = 0;
    Rep(k, 0, m)
    {
        while (j < q[k].y) zkl.ias(d[j++], 1);
        while (i < q[k].x - 1) zkl.del(zkl.ias(d[i++]));
        #if 0
            printf(" Q: [%d, %d] : %d\n", q[k].x, q[k].y, q[k].k);
            zkl.tra(zkl.rt);
        #endif
        PNode x = zkl.pul(q[k].k);
        ans[q[k].num] = x? x->ky: 0;
    }
    Rep(i, 0, m) printf("%d\n", ans[i]);

    return 0;
}
