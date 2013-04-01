#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define MAXN (101)
#define INF (0x7fffffff)

int n, m, G[MAXN][MAXN];

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int T, u, v, w;

    scanf("%d", &T);
    Rep(C, 0, T)
    {
        scanf("%d%d", &n, &m);
        Rep(i, 0, n) Rep(j, 0, n)
            G[i][j] = INF;
        while (m--)
        {
            scanf("%d%d%d", &u, &v, &w);
            u--; v--;
            if (w < G[u][v]) G[u][v] = G[v][u] = w;
        }
        Rep(k, 0, n) Rep(i, 0, n) Rep(j, 0, n)
            if (G[i][j] - G[k][j] > G[i][k])
                G[i][j] = G[i][k] + G[k][j];
        printf("Case %d: ", C + 1);
        if (G[0][n - 1] == INF) printf("Impossible\n");
        else printf("%d\n", G[0][n - 1]);
    }

    return 0;
}
