#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (55000)
#define INFI (0x7fffffff)
#define EPS (1e-8)

struct DF
{
    int a, b;
    friend bool operator < (DF p, DF q)
    {
        return p.a
    }
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    while (~scanf("%d", &n))
    {
        G_ini();
        Rep(u, 1, n + 1)
        {
            int k;
            scanf("%d", &k);
            while (k--)
            {
                int v, w;
                scanf("%d%d", &v, &w);
                AE(u, v, w);
                //AE(v, u, w);
            }
        }
        scanf("%d%d%d", &s, &t, &M);
        SPFA(s);
        if (dis[t] > EPS) printf("%.2lf\n", M - dis[t]);
        else puts("IMPOSSIBLE!");
    }

    return 0;
}
