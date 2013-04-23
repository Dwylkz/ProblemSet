#include <iostream>
#include <stdio.h>
using namespace std;
#define TYPE int
#define MAXI 200002

inline TYPE fmax(TYPE x, TYPE y)
{
    return x > y? x: y;
}

class SGT
{
public :
    struct node
    {
        int s[2], l, r;
        TYPE maxi;
    } tre[3 * MAXI];
    TYPE id;
    void ini(TYPE l, TYPE r)
    {
        id = 0;
        bui(id, l, r);
    }
    void bui(int x, TYPE l, TYPE r)
    {
        TYPE mid = (l + r) / 2;
        tre[x].l = l;
        tre[x].r = r;
        tre[x].maxi = -1;
        tre[x].s[0] = tre[x].s[1] = -1;
        if (l == r) return ;
        if (l <= mid)
        {
            tre[x].s[0] = ++id;
            bui(tre[x].s[0], l, mid);
        }
        if (mid < r)
        {
            tre[x].s[1] = ++id;
            bui(tre[x].s[1], mid + 1, r);
        }
    }
    void ins(int x, TYPE pos, TYPE key)
    {
        TYPE mid, l, r;
        bool lr;
        if (tre[x].l == tre[x].r)
            tre[x].maxi = key;
        else
        {
            mid = (tre[x].l + tre[x].r) / 2;
            lr = pos > mid;
            ins(tre[x].s[lr], pos, key);
            l = tre[x].s[0];
            r = tre[x].s[1];
            tre[x].maxi = fmax(tre[l].maxi, tre[r].maxi);
        }
    }
    TYPE que(int x, TYPE l, TYPE r)
    {
        TYPE mid, max1, max2;
        if (l <= tre[x].l && tre[x].r <= r)
            return tre[x].maxi;
        max1 = max2 = -1;
        mid = (tre[x].l + tre[x].r) / 2;
        if (l <= mid) max1 = que(tre[x].s[0], l, r);
        if (mid < r) max2 = que(tre[x].s[1], l, r);
        return fmax(max1, max2);
    }
} zkl;

int main()
{
    int n, m, a, b;
    char op;

    while (scanf("%d%d", &n, &m) != EOF)
    {
        zkl.ini(1, n);
        for (a = 1; a <= n ; a++)
        {
            scanf("%d", &b);
            zkl.ins(0, a, b);
        }
        while (m--)
        {
            scanf("%s %d %d", &op, &a, &b);
            if (op == 'U') zkl.ins(0, a, b);
            else printf("%d\n", zkl.que(0, a, b));
        }
    }

    return 0;
}
