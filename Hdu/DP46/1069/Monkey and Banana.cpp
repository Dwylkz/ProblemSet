#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN (200)
#define INFI (0x7fffffff)
#define LL long long

struct B
{
    int l, w, h;

    B(int tl = 0, int tw = 0, int th = 0)
    {
        l = tl;
        w = tw;
        h = th;
    }

    friend bool operator > (B a, B b)
    {
        return a.l > b.l && a.w > b.w;
    }

    bool operator == (B t)
    {
        return l == t.l && w == t.w && h == t.h;
    }
};

bool cmp(B a, B b)
{
    if (a.l != b.l) return a.l > b.l;
    return a.w > b.w;
}

int n, dp[MAXN];
vector<B> BS;

void BS_pus(B tb)
{
    Rep(i, 0, BS.size())
        if (BS[i] == tb) return ;
    BS.push_back(tb);
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int p[3], maxh, Case = 1;

    while (scanf("%d", &n), n)
    {
        BS.clear();
        Rep(i, 0, n)
        {
            Rep(j, 0, 3) scanf("%d", p + j);
            sort(p, p + 3);
            do
            {
                BS_pus(B(p[0], p[1], p[2]));
            } while (next_permutation(p, p + 3));
        }
        sort(BS.begin(), BS.end(), cmp);
        maxh = 0;
        Rep(i, 0, BS.size())
        {
            dp[i] = BS[i].h;
            Rep(j, 0, i) if (BS[j] > BS[i])
                dp[i] = max(dp[i],  dp[j] + BS[i].h);
            maxh = max(maxh, dp[i]);
        }
        printf("Case %d: maximum height = %d\n", Case++, maxh);
        #if 0
            puts("Block:");
            Rep(i, 0, BS.size())
                printf(" (%4d, %4d, %4d)\n", BS[i].l, BS[i].w, BS[i].h);
            puts("");
        #endif
    }

    return 0;
}
