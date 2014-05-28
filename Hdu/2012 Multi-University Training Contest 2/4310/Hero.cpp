#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (22)

struct EM
{
    int h, d;
    friend bool operator < (EM p, EM q)
    {
        return 1.0 * p.d / p.h > 1.0 * q.d / q.h;
    }
} E[MAXN];

int n;

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    while (~scanf("%d", &n))
    {
        int sd = 0, ans = 0;
        Rep(i, 0, n)
        {
            scanf("%d%d", &E[i].h, &E[i].d);
            sd += E[i].d;
        }
        sort(E, E + n);
        Rep(i, 0, n)
        {
            ans += sd * E[i].h;
            sd -= E[i].d;
        }
        printf("%d\n", ans);
    }

    return 0;
}
