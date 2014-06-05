#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
//Macro Define Begin
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(a, b) memset(a, b, sizeof a)
#define MAXN 3003
#define DMAXN 2 * MAXN
#define MAXF 3003
//End.

class vec
{
public :
    double x, y;
    vec (double tx = 0.0, double ty = 0.0)
    {
        x = tx;
        y = ty;
    }
    friend vec operator - (vec o1, vec o2)
    {
        return vec(o1.x - o2.x, o1.y - o2.y);
    }
    double mod()
    {
        return sqrt(x * x + y * y);
    }
} gus[MAXN], umb[MAXN];
int m, n;
double t, vel[MAXN];

//Hungary BFS Begin
vector<int> G[MAXN];
int lma[MAXN], rma[MAXN], pre[MAXN];
bool vis[MAXN];

void G_init()
{
    Rep(u, 0, m)
        G[u].clear();
    Rep(u, 0, m)
        Rep(v, 0, n)
            if (vel[u] * t >= (gus[u] - umb[v]).mod())
                G[u].push_back(v);
}

bool BFS(int u)
{
    int v, tp;
    queue<int> Q;
    Clr(vis, false);
    Clr(pre, -1);
    Q.push(u);
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();
        Rep(i, 0, G[u].size())
        {
            v = G[u][i];
            if (!vis[v])
            {
                vis[v] = true;
                if (rma[v] == -1)
                {
                    while (u != -1)
                    {
                        rma[v] = u;
                        tp = lma[u];
                        lma[u] = v;
                        v = tp;
                        u = pre[u];
                    }
                    return true;
                }
                else
                {
                    pre[rma[v]] = u;
                    Q.push(rma[v]);
                }
            }
        }
    }
    return false;
}

int BGM()
{
    int mmat = 0;
    Clr(lma, -1);
    Clr(rma, -1);
    Rep(u, 0, m)
        mmat += BFS(u);
    return mmat;
}
//Hungary End.

int main()
{
    int T;

    scanf("%d", &T);
    Rep(C, 0, T)
    {
        scanf("%lf%d", &t, &m);
        Rep(i, 0, m)
            scanf("%lf%lf%lf", &gus[i].x, &gus[i].y, vel + i);
        scanf("%d", &n);
        Rep(i, 0, n)
            scanf("%lf%lf", &umb[i].x, &umb[i].y);
        G_init();
        printf("Scenario #%d:\n%d\n\n", C + 1, BGM());
    }
    return 0;
}

/*
//Hungary DFS   Begin
TLE!!!!!!!!!!!!!!! {TAT}.....
vector<int> G[MAXN];
int mat[MAXN];
bool vis[MAXN];
void G_init()
{
    Rep(u, 0, m)
        G[u].clear();
    Rep(u, 0, m)
        Rep(v, 0, n)
            if (vel[u] * t >= (gus[u] - umb[v]).mod())
                G[u].push_back(v);
}

bool DFS(int u)
{
    int v;
    Rep(i, 0, G[u].size())
    {
        v = G[u][i];
        if (!vis[v])
        {
            vis[v] = true;
            if (mat[v] == -1 || DFS(mat[v]))
            {
                mat[v] = u;
                return true;
            }
        }
    }
    return false;
}

int BGM()
{
    int mmat = 0;
    Clr(mat, -1);
    Rep(u, 0, m)
    {
        Clr(vis, false);
        mmat += DFS(u);
    }
    return mmat;
}
//Hungary DFS End.
*/

/*
//ISAP Begin
MLE!!!! {=  =|||}
struct Edge
{
    int v, w, next;
} te;
vector<Edge> E;
int Vm, L[DMAXN], dis[DMAXN], gap[DMAXN];

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
    Clr(L, -1);
    Vm = m + n + 2;
    Rep(u, 0, m)
    {
        AE(m + n, u, 1);
        Rep(v, 0, n)
            if (vel[u] * t >= (gus[u] - umb[v]).mod())
                AE(u, m + v, 1);
    }
    Rep(u, 0, n) AE(m + u, Vm - 1, 1);
}

inline int fmin(int x, int y)
{
    return x < y? x: y;
}

int DFS(int u, int minf)
{
    int i, v, w, tf, dt, mind;
    if (u == Vm - 1) return minf;
    tf = minf;
    mind = Vm;
    for (i = L[u]; i > -1; i = E[i].next)
    {
        v = E[i].v;
        w = E[i].w;
        if (w > 0)
        {
            dt = fmin(w, tf);
            if (dis[u] == dis[v] + 1)
            {
                dt = DFS(v, dt);
                E[i].w -= dt;
                E[i ^ 1].w += dt;
                tf -= dt;
                if (dis[Vm - 2] >= Vm)
                    return minf - tf;
                if (tf == 0) break;
            }
            mind = fmin(mind, dis[v]);
        }
    }
    if (tf == minf)
    {
        if (--gap[dis[u]] == 0)
            dis[Vm - 2] = Vm;
        dis[u] = mind +1;
        gap[dis[u]]++;
    }
    return minf - tf;
}

int ISAP()
{
    int maxf = 0;
    Clr(dis, 0);
    Clr(gap, 0);
    gap[0] = Vm;
    while (dis[Vm - 2] < Vm)
    {
        maxf += DFS(Vm - 2, MAXF);
        printf("dis[%d] = %d\n", Vm - 2, dis[Vm - 2]);
    }
    return maxf;
}
//ISAP End.
*/
