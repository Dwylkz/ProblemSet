#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (110000)
#define INFI (0x7fffffff)

struct DVT
{
    #define MAXD (30)
    struct Node
    {
        int r, IL, IR;
    } t[MAXD][MAXN];

    void bui(int *s, int l, int r, int d = 0)
    {
        Node *ct = t[d], *nt = t[d + 1];
        int i, IL = 0, IR = 0, m = (l + r) >> 1;
        if (!d) for (i = l; i <= r; i++) ct[s[i]].r = i;
        for (i = l; i <= r; i++)
        {
            if (ct[i].r <= m) nt[l + IL++].r = ct[i].r;
            else nt[m + 1 + IR++].r = ct[i].r;
            ct[i].IL = IL;
            ct[i].IR = IR;
        }
        if (l == r) return ;
        if (l <= m) bui(s, l, m, d + 1);
        if (m < r) bui(s, m + 1, r, d + 1);
    }

    int que(int s, int e, int k, int l, int r, int d = 0)
    {
        Node *ct = t[d];
        int b = (l != s);
        int LS = ct[s - 1].IL * (b);
        int LE = ct[e].IL;
        int RS = ct[s - 1].IR * (b);
        int RE = ct[e].IR;
        int DL = LE - LS;
        int m = (l + r) >> 1;
        #if 0
            printf("[%3d, %3d] in [%3d, %3d] %3d LS = %3d LE = %3d RS = %3d RE = %3d DL = %3d\n",
                   s, e, l, r, k, LS, LE, RS, RE, DL);
        #endif
        if (l == r) return ct[l].r;
        if (k <= DL) return que(l + LS, l + LE - 1, k, l, m, d + 1);
        return que(m + 1 + RS, m + 1 + RE - 1, k - DL, m + 1, r, d + 1);
    }

} zkl;

int n, m, p[MAXN];

bool cmp(int a, int b)
{
    return p[a] < p[b];
}

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif

    int Cas = 1, h, tb;
    static int rank[MAXN];

    while (~scanf("%d", &n))
    {
        Rep(i, 0, n)
        {
            scanf("%d", p + i);
            rank[i] = i;
        }
        sort(rank, rank + n, cmp);
        zkl.bui(rank, 0, n - 1);
        scanf("%d", &m);
        printf("Case %d:\n", Cas++);
        while (m--)
        {
            int l, r, k;
            scanf("%d%d", &l, &r);
            l--;
            r--;
            k = (r - l + 1) >> 1;
            #if 0
                printf(" k = %d\n", k);
            #endif
            k = zkl.que(l, r, k + 1, 0, n - 1);
            printf("%d\n", p[rank[k]]);
        }
        #if 0
            Rep(d, 0, MAXD)
            {
                Rep(i, 0, n) printf(" %3d", zkl.t[d][i].r);
                putchar(' ');
                Rep(i, 0, n) printf(" %3d", zkl.t[d][i].IL);
                puts("");
            }
        #endif
    }

    return 0;
}
