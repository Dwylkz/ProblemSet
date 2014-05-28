#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;
#define MAXI 101
#define INFI 0x7fffffff

struct V
{
    int v, w;
} tp;
int n, dis[MAXI];
vector<V> g[MAXI];

void ini()
{
    int i;
    for (i = 0; i < n; i++) g[i].clear();
}

bool BMF(int u)
{
    int k, i, v, w;
    for (i = 0; i < n; i++)
        dis[i] = INFI;
    dis[u] = 0;
    for (k = 0; k < n - 1; k++)
        for (u = 0; u < n; u++)
            for (i = 0; i < g[u].size(); i++)
            {
                v = g[u][i].v;
                w = g[u][i].w;
                if (dis[v] - w > dis[u])
                    dis[v] = w + dis[u];
            }
}

int main()
{
    int m, u, v;

    while (scanf("%d%d", &n, &m), n || m)
    {
        ini();
        while (m--)
        {
            scanf("%d%d%d", &u, &v, &tp.w);
            u--; v--;
            tp.v = v;
            g[u].push_back(tp);
            tp.v = u;
            g[v].push_back(tp);
        }
        BMF(0);
        printf("%d\n", dis[n - 1]);
    }

    return 0;
}
