#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
#define Clr(a, b) memset(a, b, sizeof a)
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXP 505
#define DMAXP 2 * MAXP
#define INF32 0x7fffffff

struct Edge
{
    int v, w, next;
} te;
vector<Edge> E;
int n, m, maxl, Vm, L[DMAXP], dis[DMAXP], gap[DMAXP];

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

inline int fmax(int x, int y)
{
    return x > y? x: y;
}

inline int fmin(int x, int y)
{
    return x < y? x: y;
}

inline int DFS(int u, int minf)
{
    int i, v, w, tf, dt, mind;
    if (u == Vm - 1) return minf;
    tf = minf;
    mind = Vm;
    for (i = L[u]; i > -1; i = E[i].next)
    {
        v = E[i].v;
        w = E[i].w;
        dt = fmin(w, tf);
        if (w > 0)
        {
            if (dis[u] == dis[v] + 1)
            {
                dt = DFS(v, dt);
                E[i].w -= dt;
                E[i ^ 1].w += dt;
                tf -= dt;
                if (dis[0] >= Vm) return minf - tf;
                if (tf == 0) break;
            }
            mind = fmin(mind, dis[v]);
        }
    }
    if (tf == minf)
    {
        gap[dis[u]]--;
        if (!gap[dis[u]])
            dis[0] = Vm;
        dis[u] = mind + 1;
        gap[dis[u]]++;
    }
    return minf - tf;
}

int ISAP()
{
    int maxf = 0;
    Clr(dis, 0);
    Clr(gap, 0);
    gap[0] = Vm = n + maxl + 2;
    while (dis[0] < Vm)
        maxf += DFS(0, INF32);
    return maxf;
}

int main()
{
    int T, p, s, e, tsu, maxf;

    scanf("%d", &T);
    Rep(C, 0, T)
    {
        scanf("%d%d", &n, &m);
        tsu = maxl = 0;
        E.clear();
        Clr(L, -1);
        Rep(u, 1, n + 1)
        {
            scanf("%d%d%d", &p, &s, &e);
            tsu += p;
            AE(0, u, p);
            Rep(v, s, e + 1)
                AE(u, n + v, 1);
            maxl = fmax(maxl, e);
        }
        Rep(u, n + 1, n + maxl + 1)
            AE(u, n + maxl + 1, m);
        maxf = ISAP();
        printf("Case %d: ", C + 1);
        printf(maxf == tsu? "Yes\n\n": "No\n\n");
    }

    return 0;
}
