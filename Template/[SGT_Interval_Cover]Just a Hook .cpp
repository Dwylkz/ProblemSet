#include <iostream>
#include <cstdio>
using namespace std;
#define MAXI 1000001

class SGT
{
public :
    typedef int type;
    struct node
    {
        int s[2];
        type l, r, col;
    }tre[2 * MAXI + 1];
    int id;
    void ini(type l, type r)
    {
        bui(id = 0, l, r);
    }
    void bui(int x, type l, type r)
    {
        type mid = (l + r) / 2;
        tre[x].l = l;
        tre[x].r = r;
        tre[x].col = 1;
        tre[x].s[0] = ++id;
        tre[x].s[1] = ++id;
        if (l == r) return ;
        if (l <= mid) bui(tre[x].s[0], l, mid);
        if (mid < r) bui(tre[x].s[1], mid + 1, r);
    }
    void ins(int x, type l, type r, type col)
    {
        type mid;
        int ls, rs;
        if (l <= tre[x].l && tre[x].r <= r)
            tre[x].col = col;
        else
        {
            mid = (tre[x].l + tre[x].r) / 2;
            ls = tre[x].s[0];
            rs = tre[x].s[1];
            if (tre[x].col)
            {
                tre[ls].col = tre[rs].col = tre[x].col;
                tre[x].col = 0;
            }
            if (l <= mid) ins(tre[x].s[0], l, r, col);
            if (mid < r) ins(tre[x].s[1], l, r, col);
        }
    }
    type que(int x, type l, type r)
    {
        type mid, ts1, ts2;
        if (l <= tre[x].l && tre[x].r <= r && tre[x].col)
            return (tre[x].r - tre[x].l + 1) * tre[x].col;
        mid = (tre[x].l + tre[x].r) / 2;
        if (l <= mid) ts1 = que(tre[x].s[0], l, r);
        if (mid < r) ts2 = que(tre[x].s[1], l, r);
        return ts1 + ts2;
    }
} zkl;

int main()
{
    int C, T, n, q, x, y, z;

    scanf("%d", &T);
    for (C = 1; C <= T; C++)
    {
        scanf("%d%d", &n, &q);
        zkl.ini(1, n);
        while (q--)
        {
            scanf("%d%d%d", &x, &y, &z);
            zkl.ins(0, x, y, z);
        }
        printf("Case %d: The total value of the hook is %d.\n",
               C, zkl.que(0, 1, n));
    }

    return 0;
}
