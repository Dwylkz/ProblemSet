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

struct Edge
{
    int w, v, nxt;
};
vector<Edge> E;
int L[MAXN];

void G_ini()
{
    E.clear();
    memset(L, -1, sizeof L);
}

void AE(int u, int v, int w)
{
    Edge te = {w, v, L[u]};
    L[u] = E.size();
    E.push_back(te);
}

int n, s, t, M;
double dis[MAXN];

void SPFA(int u)
{
    static queue<int> Q;
    static bool IQ[MAXN];
    Rep(i, 1, n + 1) dis[i] = -INFI, IQ[i] = 0;
    dis[u] = M, Q.push(u), IQ[u] = 1;
    while (!Q.empty())
    {
        u = Q.front(), Q.pop(), IQ[u] = 0;
        for (int i = L[u]; i != -1; i = E[i].nxt)
        {
            int v = E[i].v;
            double w = -dis[u] * E[i].w / 100.0;
            if (dis[v] < dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if (IQ[v]) continue;
                Q.push(v), IQ[v] = 1;
            }
        }
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
