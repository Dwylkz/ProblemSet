#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (110000)

typedef struct Node
{
     int ky, ct, sz;
     int at;
     Node *p, *s[2];
} *PNode, Node;

struct SLY
{
    Node t[MAXN];
    PNode top, rt;
    void ini()
    {
        top = t;
        rt = 0;
    }
    PNode cre(int key, PNode fa = 0)
    {
        top->ky = key;
        top->ct = top->sz = 1;
        top->p = fa;
        top->s[0] = top->s[1] = 0;
		top->at = 0;
        return top++;
    }
    PNode set(PNode x, int inc)
    {
		x->ky += inc;
		x->at += inc;
        return x;
    }
    PNode pus(PNode x)
    {
        Rep(i, 0, 2) if (x->s[i]) set(x->s[i], x->at);
        x->at = 0;
        return x;
    }
    PNode upd(PNode x)
    {
        x->sz = x->ct;
        Rep(i, 0, 2) if (x->s[i])
            x->sz += x->s[i]->sz;
        return x;
    }
    PNode rot(PNode x, bool b = 0)
    {
        PNode y = x->s[!b];
		pus(y); pus(x);
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
    PNode ias(int key, bool ios = 0)
    {
		if (!rt)
		{
			if (ios) rt = cre(key);
			return rt;
		}
		PNode y = 0, x = rt;
		while (x && pus(x)->ky != key)
		{
			y = x;
			x = x->s[x->ky < key];		
		}
		if (ios)
		{
			if (!x) y->s[y->ky < key] = x = cre(key, y);
			else x->ct++;
		}
		return x? sly(x): x;
    }
    PNode slt(PNode x)
    {
        rt = x->s[1];
        x->s[1] = 0;
        if (rt) rt->p = 0;
        return upd(x);
    }
	int lrs(PNode x, bool b)
	{
		return x->ct + (x->s[b]? x->s[b]->sz: 0);
	}
    PNode sel(PNode x, int ind, bool b = 0)
    {
        while (lrs(pus(x), b) != ind)
        {
			PNode y = x;
			if (lrs(x, b) - x->ct < ind && ind <= lrs(x, b)) break;
            x = x->s[(lrs(x, b) < ind) ^ b];
            ind -= lrs(y, b) * (lrs(y, b) < ind);
        }
        return upd(x);
    }
    PNode add(PNode x, int inc)
    {
        return set(x, inc);
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
        #if 0
            printf(" %4d", x->ky);
        #endif
        tra(x->s[1]);
        upd(x);
    }
} zkl;

int n, lom;

int main()
{
	#if 1
		freopen("test.txt", "rt", stdin);
	#endif

    int ans = 0;

	scanf("%d%d", &n, &lom);
	zkl.ini();
	while (n--)
	{
	    char op[4];
	    int k;
	    scanf("%1s%d", op, &k);
	    #if 0
            printf("op = %c k = %d\n", op[0], k);
        #endif
	    if (op[0] == 'I' && k >= lom) zkl.ias(k, 1);
	    if (op[0] == 'A' && zkl.rt) zkl.add(zkl.rt, k);
	    if (op[0] == 'S' && zkl.rt)
        {
			zkl.add(zkl.rt, -k);
			ans += zkl.slt(zkl.ias(lom - 1, 1))->sz - 1;
        }
        if (op[0] == 'F')
            if (!zkl.rt || k > zkl.rt->sz) puts("-1");
            else printf("%d\n", zkl.sly(zkl.sel(zkl.rt, k, 1))->ky);
	    #if 0
            zkl.tra(zkl.rt);
            puts("");
        #endif
	}
	printf("%d\n", ans);

	return 0;
}
