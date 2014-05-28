#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
#define MAXI 6006

vector<int> G[MAXI];
int n, m, pre[MAXI], color[MAXI];
bool vis[MAXI];


void G_init()
{
    int u;
    for (u = 0; u < n; u++)
        G[u].clear();
}

bool BFS_CC(int u)
{
    int i, v;
    queue<int> Q;
    Q.push(u);
    color[u] = 0;
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for (i = 0; i < G[u].size(); i++)
        {
            v = G[u][i];
            if (color[v] == -1)
            {
                color[v] = color[u] ^ 1;
                Q.push(v);
            }
            else if (color[v] == color[u])
                return true;
        }
    }
    return false;
}

bool is_BGM()
{
    int u;
    memset(color, -1, sizeof color);
    for (u = 0; u < n; u++)
        if (color[u] == -1 && BFS_CC(u))
            return false;
    return true;
}

int DFS(int u)
{
    int i, v;

    for (i = 0; i < G[u].size(); i++)
    {
        v = G[u][i];
        if (!vis[v])
        {
            vis[v] = true;
            if (pre[v] == -1 || DFS(pre[v]))
            {
                pre[v] = u;
                return 1;
            }
        }
    }

    return 0;
}

int BGM()
{
    int u, tsu = 0;

    memset(pre, -1, sizeof pre);
    for (u = 0; u < n; u++)
    {
        memset(vis, false, sizeof vis);
        tsu += DFS(u);
    }

    return tsu;
}

int main()
{
    int u, v;

    while (~scanf("%d%d", &n, &m))
    {
        G_init();
        while (m--)
        {
            scanf("%d%d", &u, &v);
            u--; v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if (is_BGM()) printf("%d\n", BGM() / 2);
        else printf("No\n");
    }
    return 0;
}
