#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define LL long long
#define MAXN (300000)

//SGT
#define ls(x) (x << 1)
#define rs(x) (ls(x) + 1)
struct Node
{
    int l, r, rank;
} sgt[MAXN << 2];
void bui(int l, int r, int x = 1)
{
    sgt[x].l = l;
    sgt[x].r = r;
    sgt[x].rank = r - l + 1;
    if (l == r) return ;
    int m = (l + r) >> 1;
    bui(l, m, ls(x));
    bui(m + 1, r, rs(x));
}
int que(int key, int x = 1)
{
    sgt[x].rank--;
    if (sgt[x].l == sgt[x].r) return sgt[x].l;
    if (key <= sgt[ls(x)].rank) return que(key, ls(x));
    else return que(key - sgt[ls(x)].rank, rs(x));
}
//SGT_END

int n, k;

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif

    int T, tsu, ki;
    LL ans;

    scanf("%d", &T);
    Rep(Case, 1, T + 1)
    {
        scanf("%d%d", &n, &k);
        bui(1, n);
        ans = 0;
        while (k--)
        {
            scanf("%d", &ki);
            ans += que(ki);
        }
        printf("Case %d: %I64d\n", Case, ans);
    }

    return 0;
}
