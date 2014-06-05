#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (220000)

typedef struct Node
{
     int ky, sz;
     int at, rv, mk;
     Node *p, *s[2];
} *PNode;
struct SLY
{
    Node t[MAXN];
    PNode top, rt, ll, rr;
    void ini()
    {
        top = t;
        rt = ll = cre(-1);
        rt->s[1] = rr = cre(-2, rt);
    }
    PNode cre(int key, PNode fa = 0)
    {
        top->ky = key;
        top->sz = 1;
        top->p = fa;
        top->s[0] = top->s[1] = 0;
        top->at = top->rv = top->mk = 0;
        return top++;
    }
    PNode set(PNode x, int rvs, int inc)
    {
        x->ky += inc;
        x->mk += inc;
        x->at += inc;
        x->rv ^= rvs;
        if (rvs) swap(x->s[0], x->s[1]);
        return x;
    }
    PNode pus(PNode x)
    {
        Rep(i, 0, 2) if (x->s[i]) set(x->s[i], x->rv, x->at);
        x->rv = x->at = 0;
        return x;
    }
    PNode upd(PNode x)
    {
        x->mk = x->ky;
        x->sz = 1;
        Rep(i, 0, 2) if (x->s[i])
        {
            x->mk = min(x->mk, x->s[i]->mk);
            x->sz += x->s[i]->sz;
        }
        return x;
    }
    PNode rot(PNode x, bool b = 0)
    {
        PNode y = pus(pus(x)->s[!b]);
        x->s[!b] = y->s[b];
        if (y->s[b]) y->s[b]->p = x;
        y->p = x->p;
        if (!x->p) rt = y;
        else x->p->s[x->p->s[0] != x] = y;
        x->p = y; y->s[b] = x;
        return upd(x);
    }
    PNode sly(PNode x, PNode fa = 0)
    {
        while (x->p != fa)
        {
            bool bp = x->p->s[0] != x;
            if (x->p->p == fa)
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
    PNode mxk(PNode x, bool b = 0)
    {
        while (pus(x)->s[b]) x = x->s[b];
        return x;
    }
    PNode del(PNode x)
    {
        sly(x);
        if (x->s[1])
        {
            PNode y = sly(mxk(x->s[1], 0));
            y->s[0] = x->s[0];
            if (x->s[0]) x->s[0]->p = y;
            x->p = 0;
        }
        else
        {
            rt = x->s[0];
            if (rt) rt->p = 0;
            x->s[0] = 0;
        }
        return upd(rt);
    }
    PNode bui(int l, int r, int *s, PNode fa = 0)
    {
        int m = (l + r) >> 1;
        PNode x = cre(s[m], fa);
        if (l < m) x->s[0] = bui(l, m - 1, s, x);
        if (m < r) x->s[1] = bui(m + 1, r, s, x);
        return upd(x);
    }
    PNode sel(PNode x, int ind)
    {
        int tid = 1 + (x->s[0]? x->s[0]->sz: 0);
        while (tid != ind)
        {
            x = pus(x)->s[tid < ind];
            ind -= tid * (tid < ind);
            tid = 1 + (x->s[0]? x->s[0]->sz: 0);
        }
        return x;
    }
    PNode ina(PNode x, int key = 0)
    {
        if (pus(x)->s[1])
        {
            PNode y = mxk(x->s[1]);
            x = y->s[0] = cre(key, y);
        }
        else x = x->s[1] = cre(key, x);
        return sly(x);
    }
    PNode add(PNode x, int inc)
    {
        return set(x, 0, inc);
    }
    PNode rvs(PNode x)
    {
        return set(x, 1, 0);
    }
    PNode rvl(PNode x, int k)
    {
        if (k %= x->sz)
        {
            x = sly(sel(pus(x), x->sz - k + 1), x->p);
            PNode y = mxk(x);
            y->s[0] = x->s[1];
            if (x->s[1]) x->s[1]->p = y;
            x->s[0]->p = x->p;
            if (x->p) x->p->s[x->p->s[0] != x] = x->s[0];
            x->p = y = mxk(y);
            y->s[0] = x;
            x->s[0] = x->s[1] = 0;
        }
        return sly(upd(x));
    }
    void tra(PNode x)
    {
        if (!x) return ;
        pus(x);
        tra(x->s[0]);
        #if 0
            printf("%4d -> (%4d, %4d) sz = %4d\n",
                   x->ky, x->s[0]? x->s[0]->ky: -3, x->s[1]? x->s[1]->ky: -3,
                   x->sz);
        #endif
        #if 1
            printf(" %4d", x->ky);
        #endif
        tra(x->s[1]);
        upd(x);
    }
} zkl;

int n, m, s[MAXN];

int main()
{
	#if 1
		freopen("test.txt", "rt", stdin);
	#endif

	scanf("%d", &n);
	Rep(i, 0, n) scanf("%d", s + i);
	zkl.ini();
	zkl.rr->s[0] = zkl.bui(0, n - 1, s, zkl.rr);
	zkl.sly(zkl.rr->s[0]);
	scanf("%d", &m);
	while (m--)
	{
	    char op[MAXN];
	    int x, y, z;
	    scanf("%s%d", op, &x);
	    string os = op;
	    PNode i, j;
	    if (os == "DELETE") zkl.del(zkl.sel(zkl.rt, x + 1));
	    else
	    {
	        scanf("%d", &y);
            if (os == "INSERT") zkl.ina(zkl.sel(zkl.rt, x + 1), y);
            else
            {
                i = zkl.sly(zkl.sel(zkl.rt, x));
                j = zkl.sly(zkl.sel(zkl.rt, y + 2), i);
                if (os == "REVERSE") zkl.rvs(j->s[0]);
                else  if (os == "MIN") printf("%d\n", j->s[0]->mk);
                else
                {
                    scanf("%d", &z);
                    if (os == "ADD") zkl.add(j->s[0], z);
                    else zkl.rvl(j->s[0], z);
                }
            }
	    }
        #if 0
            printf("%-10s in (%-3d, %-3d)", os.c_str(), i->ky, j->ky);
            zkl.tra(zkl.rt);
            puts("");
        #endif
	}

	return 0;
}
