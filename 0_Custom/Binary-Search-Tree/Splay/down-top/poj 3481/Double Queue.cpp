#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (2000002)

typedef struct Node
{
    int ky, ct, ne;
    Node *s[2], *p;
} *PNode, Node;
struct SLY
{
    Node *rt, t[MAXN];
    int id;
    void ini()
    {
        id = 0;
        rt = 0;
    }
    PNode cre(int key, int nam, PNode p = 0)
    {
        PNode x = t + id++;
        x->ky = key;
        x->p = p;
        x->s[0] = x->s[1] = 0;
        x->ne = nam;
        x->ct = 1;
        return x;
    }
    void rot(PNode x, bool b)
    {
        PNode y = x->s[!b];
        x->s[!b] = y->s[b];
        if (y->s[b]) y->s[b]->p = x;
        y->p = x->p;
        if (!x->p) rt = y;
        else x->p->s[x->p->s[0] != x] = y;
        y->s[b] = x;
        x->p = y;
    }
    void sly(PNode x, PNode y = 0)
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
    }
    void ins(int nam, int key)
    {
        if (!rt)
        {
            rt = cre(key, nam);
            return ;
        }
        bool lr;
        PNode y = 0, x = rt;
        while (x && key != x->ky)
        {
            y = x;
            x = x->s[lr = key > x->ky];
        }
        if (x) x->ct++;
        else y->s[lr] = x = cre(key, nam, y);
        sly(x);
    }
    void del(PNode x)
    {
        if (!x) return ;
        if (--x->ct) return ;
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
    }
    PNode ext(PNode x, bool b)
    {
        while (x && x->s[b]) x = x->s[b];
        return x;
    }
    void tra(PNode x)
    {
        if (!x) return ;
        if (x->s[0]) tra(x->s[0]);
        printf(" %d -> (%d, %d)\n",
               x->ky,
               x->s[0]? x->s[0]->ky: -1,
               x->s[1]? x->s[1]->ky: -1);
        if (x->s[1]) tra(x->s[1]);
    }
} zkl;

int n;

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif

    int op;
    zkl.ini();
    while (scanf("%d", &op), op)
        if (op == 1)
        {
            int k, p;
            scanf("%d%d", &k, &p);
            zkl.ins(k, p);
            #if 0
                printf("Ins %4d %4d\n", k, p);
                zkl.tra(zkl.rt);
            #endif
        }
        else
        {
            PNode x = zkl.ext(zkl.rt, op == 2);
            printf("%d\n", x? x->ne: 0);
            zkl.del(x);
            #if 0
                printf("Del %4d\n", x? x->ky: 0);
                zkl.tra(zkl.rt);
            #endif
        }

    return 0;
}
