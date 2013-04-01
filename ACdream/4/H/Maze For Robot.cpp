#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (200)
#define MAXC (100)
#define INFI (0x7fffffff)

int n, l, sig[MAXN], met, dis[MAXN][MAXN], G[MAXN][3];

void G_ini()
{
    Rep(i, 0, MAXN) Rep(j, 0, MAXN)
        dis[i][j] = INFI;
}

void Floyd()
{
    Rep(k, 0, n) Rep(i, 0, n) Rep(j, 0, n)
        if (dis[i][j] - dis[i][k] > dis[k][j])
            dis[i][j] = dis[i][k] + dis[k][j];
    #if 0
        Rep(i, 0, n)
        {
            Rep(j, 0, n)
                printf(" %12d", dis[i][j]);
            puts("");
        }
    #endif
}

void DFS(int u, int rl)
{
    if (!rl)
    {
        if (sig[u]) met++;
        return ;
    }
    bool no = 1;
    Rep(v, 0, n) if (sig[v] && rl >= dis[u][v]) no = 0;
    if (no) return ;
    Rep(i, 0, 3) DFS(G[u][i], rl - 1);
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int Case;

    scanf("%d", &Case);
    Rep(CCas, 1, Case + 1)
    {
        G_ini();
        scanf("%d", &n);
        Rep(i, 0, n)
        {
            int u, v;
            scanf("%d", &u);
            u--;
            Rep(j, 0, 3)
            {
                scanf("%d", &v);
                v--;
                dis[u][v] = 1;
                G[u][j] = v;
            }
            scanf("%d", sig + u);
        }
        scanf("%d", &l);
        Floyd();
        met = 0;
        DFS(0, l);
        printf("%d\n", met);
    }

    return 0;
}
