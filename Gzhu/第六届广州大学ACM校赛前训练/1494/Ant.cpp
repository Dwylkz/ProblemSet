#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a ,b) fill(c, c + a, b)
#define MAXN (500)
#define INFI (0x7fffffff)

struct Edge
{
    int v;
    double w;
    Edge(int tv = 0, double tw = 0)
    {
        v = tv;
        w = tw;
    }
};
vector<Edge> E[MAXN];

void G_ini()
{
    Rep(i, 0, MAXN) E[i].clear();
}

int N, A, H[MAXN][MAXN];
double V, tim;
bool vis[MAXN][MAXN], poor;

void sim(int s, int t)
{
    int tow;
    double tti = 0;

    Rep(i, 0, MAXN) Clr(vis[i], MAXN, 0);
    #if 0
        puts("fuck");
    #endif
    while (1)
    {
        #if 0
            printf(" %d->%d\n", s, t);
        #endif
        if (vis[s][t])
        {
            poor = 1;
            return ;
        }
        if (E[s].size() < 2)
        {
            if (tti > tim) tim = tti;
            return ;
        }
        vis[s][t] = 1;
        tow = H[s][t];
        tti += E[s][tow].w;
        tow = (H[t][s] + 1 + E[t].size()) % E[t].size();
        s = t;
        t = E[t][tow].v;
    }
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int T, m, v, s, t;
    double w;

    scanf("%d", &T);
    while (T--)
    {
        G_ini();
        scanf("%d%lf", &N, &V);
        Rep(u, 0, N)
        {
            scanf("%d", &m);
            while (m--)
            {
                scanf("%d%lf", &v, &w);
                v--;
                H[u][v] = E[u].size();
                E[u].push_back(Edge(v, w));
            }
        }
        tim = 0;
        poor = 0;
        scanf("%d", &A);
        while (A--)
        {
            scanf("%d%d", &s, &t);
            sim(s - 1, t - 1);
        }
        if (poor) puts("Poor Ants");
        else printf("%.4lf\n", tim / V);
    }
    return 0;
}
