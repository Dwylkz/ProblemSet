#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(a, b) memset(a, b, sizeof a);
#define MAXM 202
#define MAXN 202
#define MAXF 10000001

struct Edge
{
    int v, w, next;
} te;
vector<Edge> E;
int n, m, L[MAXM], dis[MAXM];

void G_init()
{
    E.clear();
    Clr(L, -1);
}

void AE(int u, int v, int w)
{
    te.v = v;
    te.w = w;
    E.push_back(te);
    E[E.size() - 1].next = L[u];
    L[u] = E.size() - 1;
    te.v = u;
    te.w = 0;
    E.push_back(te);
    E[E.size() - 1].next = L[v];
    L[v] = E.size() - 1;
}

inline int fmin(int x, int y)
{
    return x < y? x: y;
}

inline bool BFS(int u)
{
    int i, v, w;
    queue<int> Q;
    Clr(dis, -1);
    dis[u] = 0;
    Q.push(u);
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for (i = L[u]; i > -1; i = E[i].next)
        {
            v = E[i].v;
            w = E[i].w;
            if (dis[v] == -1 && w)
            {
                dis[v] = dis[u] + 1;
                Q.push(v);
            }
        }
    }
    return dis[m - 1] > -1;
}

int DFS(int u, int minf)
{
    int i, v, w, tf, dt;
    if (u == m - 1)
        return minf;
    tf = minf;
    for (i = L[u]; i > -1; i = E[i].next)
    {
        v = E[i].v;
        w = E[i].w;
        dt = fmin(w, tf);
        if (dis[u] + 1 == dis[v] && w > 0)
        {
            dt = DFS(v, dt);
            E[i].w -= dt;
            E[i ^ 1].w += dt;
            tf -= dt;
            if (tf == 0) break;
        }
    }
    return minf - tf;
}

int Dinic(int s, int e)
{
    int maxf = 0;
    while (BFS(s))
        maxf += DFS(s, MAXF);
    return maxf;
}

int main()
{
    int u, v, w;
    while (~scanf("%d%d", &n, &m))
    {
        G_init();
        while (n--)
        {
            scanf("%d%d%d", &u, &v, &w);
            u--; v--;
            AE(u, v, w);
        }
        printf("%d\n", Dinic(0, m - 1));
    }

    return 0;
}
