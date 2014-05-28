#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN (2200)
#define INFI (10000000)

struct Edge
{
    int v, w, h, next;
};
vector<Edge> E;
int L[MAXN];
void G_ini()
{
    E.clear();
    memset(L, -1, sizeof L);
}
void AE(int u, int v, int w, int h)
{
    Edge te = {v, w, h, L[u]};
    L[u] = E.size();
    E.push_back(te);
}

int c, r, s, e, hl;

int d[MAXN], h[MAXN];

void SPFA_H(int u)
{
    queue<int> Q;
    bool iq[MAXN];
    Rep(i, 0, c)
    {
        h[i] = 0;
        iq[i] = 0;
    }
    Q.push(u);
    h[u] = hl;
    iq[u] = 1;
    while (!Q.empty())
    {
        u = Q.front(); Q.pop();
        iq[u] = 0;
        for (int i = L[u]; i != -1; i = E[i].next)
        {
            int v = E[i].v, th = min(E[i].h, h[u]);
            if (th > h[v])
            {
                h[v] = th;
                if (!iq[v])
                {
                    iq[v] = 1;
                    Q.push(v);
                }
            }
        }
    }
}

void SPFA_D(int u)
{
    queue<int> Q;
    bool iq[MAXN];
    Rep(i, 1, c + 1)
    {
        h[i] = 0;
        d[i] = INFI;
        iq[i] = 0;
    }
    Q.push(u);
    h[u] = hl;
    d[u] = 0;
    iq[u] = 1;
    while (!Q.empty())
    {
        u = Q.front(); Q.pop();
        iq[u] = 0;
        for (int i = L[u]; i != -1; i = E[i].next)
        {
            int v = E[i].v, w = E[i].w, th = E[i].h;
            if (th == -1) th = h[u];
            else th = min(h[u], th);
            if (th > h[v] || (th == h[v] && d[v] - w > d[u]))
            {
                h[v] = th;
                d[v] = d[u] + w;
                if (!iq[v])
                {
                    iq[v] = 1;
                    Q.push(v);
                }
            }
        }
    }
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int T, Cas = 1;

    scanf("%d%d", &c, &r);
    while (c || r)
    {
        G_ini();
        while (r--)
        {
            int u, v, w, h;
            scanf("%d%d%d%d", &u, &v, &h, &w);
            u; v;
            AE(u, v, w, h);
            AE(v, u, w, h);
        }
        scanf("%d%d%d", &s, &e, &hl);
        s; e;
        //SPFA_H(s);
        SPFA_D(s);
        printf("Case %d:\n", Cas++);
        if (d[e] - INFI)
        {
            printf("maximum height = %d\n", h[e]);
            printf("length of shortest route = %d\n", d[e]);
        }
        else puts("cannot reach destination");
        scanf("%d%d", &c, &r);
        if (c || r) puts("");
    }

    return 0;
}
