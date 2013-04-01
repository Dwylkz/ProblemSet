#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define MAXN (20020)
#define INF32 (0x7fffffff)

struct Edge
{
    int v, w, next;
} te;
vector<Edge> E;

int n, m, L[MAXN], dis[MAXN], gap[MAXN], Vm;

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

void G_init()
{
    E.clear();
    Clr(L, n + 3, -1);
}

inline int fmin(int a, int b)
{
    return a < b? a: b;
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
    Clr(dis, n + 2, 0);
    Clr(gap, n + 2, 0);
    gap[0] = Vm = n + 2;
    while (dis[0] < Vm)
        maxf += DFS(n, INF32);
    return maxf;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("test.txt", "rt", stdin);
    #endif
    int a, b, c;
    while (~scanf("%d%d", &n, &m))
    {
        G_init();
        Rep(i, 0, n)
        {
            scanf("%d%d", &a, &b);
            AE(n, i, a);
            AE(i, n + 1, b);
        }
        Rep(i, 0, m)
        {
            scanf("%d%d%d", &a, &b, &c);
            AE(a - 1, b - 1, c);
            AE(b - 1, a - 1, c);
        }
        #if 0
            Rep(i, 0, n + 2)
            {
                printf("%d: ", i);
                for (int j = L[i]; j > -1; j = E[j].next)
                    printf("(%d,%d)", E[j].v, E[j].w);
                puts("");
            }
        #endif
        printf("%d\n", ISAP());
    }
    return 0;
}
