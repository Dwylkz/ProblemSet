#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <stack>
#include <memory.h>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MS(a, b) memset(a, b, sizeof a)
#define LL long long
#define MAXN (220000)

struct BT
{
    int l, r;
    BT(int tl = -1,  int tr = -1):l(tl), r(tr){}
    friend bool operator < (BT a, BT b)
    {
        if (a.l != b.l) return a.l < b.l;
        return a.r < b.r;
    }
} bt[2][MAXN];
map<BT, int> ty;

int n, m, ha[2][MAXN];

void DFS(int t, int x)
{
    stack<int> st;
    char rc[MAXN];

    st.push(x);
    MS(rc, 0);
    while (!st.empty())
    {
        x = st.top();
        if (!rc[x])
        {
            if (bt[t][x].l > -1) st.push(bt[t][x].l);
            rc[x]++;
        }
        else if (rc[x] < 2)
        {
            if (bt[t][x].r > -1) st.push(bt[t][x].r);
            rc[x]++;
        }
        else
        {
            BT tb;
            int ls = bt[t][x].l, rs = bt[t][x].r;
            if (ls > -1) tb.l = ty[BT(bt[t][ls].l, bt[t][ls].r)];
            if (rs > -1) tb.r = ty[BT(bt[t][rs].l, bt[t][rs].r)];
            if (!ty[tb]) ty[tb] = ty.size() + 1;
            ha[t][ty[tb]]++;
            st.pop();
            #if 0
                printf("x = %d, size = %d, (%d, %d)\n", x, ty.size(), tb.l, tb.r);
                for (map<BT, int>::iterator beg = ty.begin(); beg != ty.end(); beg++)
                printf(" (%d, %d)", beg->first.l, beg->first.r);
            puts("");
            #endif
        }
    }
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int T;
    LL ans;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        Rep(i, 1, n + 1) scanf("%d%d", &bt[0][i].l, &bt[0][i].r);
        Rep(i, 1, m + 1) scanf("%d%d", &bt[1][i].l, &bt[1][i].r);
        MS(ha, 0);
        ty.clear();
        DFS(0, 1);
        DFS(1, 1);
        ans = 0;
        Rep(i, 1, n + m + 1) ans += ha[0][i] * ha[1][i];
        printf("%lld\n", ans);
    }

    return 0;
}
