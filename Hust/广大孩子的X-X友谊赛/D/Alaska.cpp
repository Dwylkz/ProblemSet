#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define MAXN (1423)

int n;
bool h[MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int pre, now;
    bool yes;

    while (scanf("%d", &n), n)
    {
        yes = 1;
        Clr(h, MAXN, 0);
        Rep(i, 0, n)
        {
            scanf("%d", &now);
            h[now] = 1;
        }
        pre = 0;
        Rep(i, 1, MAXN)
            if (h[i] && i - pre <= 200)
                if (i < MAXN - 1) pre = i;
            else
            {
                yes = 0;
                break;
            }
        if (yes && (MAXN - 1 - pre) * 2 > 200)
            yes = 0;
        puts(yes? "POSSIBLE": "IMPOSSIBLE");
    }

    return 0;
}
