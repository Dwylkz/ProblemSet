#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define LLU int
#define MAXN (65536)
#define MAXND (131072)

struct sgt
{
    struct nod
    {
        LLU l, r;
        int ls, rs, col, xr;
        void fxr()
        {
            if (col > -1) col ^= 1;
            else xr ^= 1;
        }
    } t[MAXND << 1];

    int ind;

    void ini(LLU l, LLU r)
    {
        bui(l, r, ind = 0);
    }

    void pus(int x)
    {
        int ls = t[x].ls, rs = t[x].rs;

        if (ls == -1) return ;
        if (t[x].col > -1)
        {
            t[ls].col = t[rs].col = t[x].col;
            t[x].col = -1;
        }
        else if (t[x].xr)
        {
            t[ls].fxr();
            t[rs].fxr();
        }
        t[x].xr = 0;
    }

    void upd(int x)
    {
        int ls = t[x].ls, rs = t[x].rs;

        if (ls == -1) return ;
        if (t[ls].col == t[rs].col)
            t[x].col = t[ls].col;
    }

    void bui(LLU l, LLU r, int x = 0)
    {
        int mid = (l + r) >> 1;

        t[x].l = l;
        t[x].r = r;
        t[x].ls = t[x].rs = -1;
        t[x].col = t[x].xr = 0;
        if (l == r) return ;
        if (l <= mid) bui(l, mid, t[x].ls = ++ind);
        if (mid < r) bui(mid + 1, r, t[x].rs = ++ind);
    }
    void ins(LLU l, LLU r, int op, int x = 0)
    {
        int mid = (t[x].l + t[x].r) >> 1;

        if (l > r) return ;
        if (l <= t[x].l && t[x].r <= r)
        {
            if (op < 2) t[x].col = op;
            else t[x].fxr();
            #if 0
                printf(" [%d, %d] = %d\n", t[x].l, t[x].r, t[x].col);
            #endif
        }
        else
        {
            pus(x);
            if (l <= mid) ins(l, r, op, t[x].ls);
            if (mid < r) ins(l, r, op, t[x].rs);
            upd(x);
        }
    }

    bool ha[MAXND];
    bool emp;

    void tra(int x)
    {
        if (t[x].col == 1)
        {
            #if 0
                printf(" [%d, %d]\n", t[x].l, t[x].r);
            #endif
            emp = 0;
            Rep(i, t[x].l, t[x].r + 1)
                ha[i] = 1;
        }
        else if (t[x].col == -1)
        {
            pus(x);
            if (t[x].l < t[x].r)
            {
                tra(t[x].ls);
                tra(t[x].rs);
            }
            upd(x);
        }
    }

    void sta()
    {
        #if 0
            puts("statstic");
        #endif
        bool ep, fri;

        emp = 1;
        Clr(ha, MAXND, 0);
        tra(0);
        if (emp) puts("empty set");
        else
        {
            ep = fri = 0;
            Rep(i, 0, MAXND)
                if (ha[i])
                {
                    if (!ep)
                    {
                        ep = 1;
                        if (!fri) fri = 1;
                        else putchar(' ');
                        if (i & 1)
                            printf("(%d,", (i - 1) >> 1);
                        else
                            printf("[%d,", i >> 1);
                    }
                }
                else
                {
                    if (ep)
                    {
                        ep = 0;
                        if (i & 1)
                            printf("%d]", (i - 1) >> 1);
                        else
                            printf("%d)", i >> 1);
                    }
                }
            putchar('\n');
        }
    }
} zkl;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("test.txt", "rt", stdin);
#endif

    char op[3], lb[3], ch[3], rb[3];
    LLU ln, rn;

    zkl.ini(0, MAXND);
    while (~scanf("%1s", op))
    {
        #if 0
            zkl.sta();
        #endif
        scanf("%1s%d%1s%d%1s", lb, &ln, ch, &rn, rb);
        ln <<= 1;
        rn <<= 1;
        if (lb[0] == '(') ln++;
        if (rb[0] == ')') rn--;
        #if 0
            printf("%c {%d, %d}\n", op[0], ln, rn);
        #endif
        switch (op[0])
        {
        case 'U':
            zkl.ins(ln, rn, 1);
            break;
        case 'D':
            zkl.ins(ln, rn, 0);
            break;
        case 'S':
            zkl.ins(ln, rn, 2);
            break;
        case 'I':
            zkl.ins(0, ln - 1,0);
            zkl.ins(rn + 1, MAXND, 0);
            break;
        default :
            zkl.ins(ln, rn, 2);
            zkl.ins(0, ln - 1,0);
            zkl.ins(rn + 1, MAXND, 0);
        }
    }
    zkl.sta();

    return 0;
}
