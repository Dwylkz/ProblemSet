#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
//MACRO
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN 1001
#define MAXM 100001
#define MAXK 1001
#define INFI 0x3fffffff
//END.
struct Edge
{
    int v, w, next;
} te;
vector<Edge> E;
int n, m, s, t, k, L[MAXN];

void G_init()
{
    E.clear();
    Rep(i, 0, n) L[i] = -1;
}

void AE(int u, int v, int w)
{
    te.v = v; te.w = w;
    te.next = L[u];
    E.push_back(te);
    L[u] = E.size() - 1;
    te.v = u;
    te.next = L[v];
    E.push_back(te);
    L[v] = E.size() - 1;
}

//Heap_Dijkstra
struct V
{
    int u, dis;
    friend bool operator < (V a, V b)
    {
            return a.dis > b.dis;
    }
} tv;
bool vis[MAXN];

int Dijkstra(int s, int *dis)
{
    int u, v, dis_u, w, i;
    priority_queue<V> PQ;
    Rep(u, 0, n)
    {
        dis[u] = INFI;
        vis[u] = false;
    }
    tv.u = s;
    tv.dis = dis[s] = 0;
    PQ.push(tv);
    while (!PQ.empty())
    {
        tv = PQ.top(); PQ.pop();
        u = tv.u; dis_u = tv.dis;
        if (vis[u]) continue;
        vis[u] = true;
        for (i = L[u]; i > -1; i = E[i].next)
        {
            v = E[i].v; w = E[i].w;
            if (i % 2 && !vis[v] && dis[v] - w > dis_u)
            {
                tv.u = v;
                tv.dis = dis_u + w;
                dis[v] = tv.dis;
                PQ.push(tv);
            }
        }
    }
}
//END.

//A_STAR
struct State
{
    int u, h, g, f;
    friend bool operator < (State a, State b)
    {
        return a.f > b.f;
    }
} ts;
int h[MAXN], inQ[MAXN];

int AStar_FKSP()
{
    int i, u, v, dis_u, w;
    priority_queue<State> PQ;
    Dijkstra(t, h);
    if (h[s] == -1) return -1;
    Rep(i, 0, n) inQ[i] = 0;
    ts.u = s;
    ts.g = 0;
    ts.h = h[s];
    ts.f = ts.g + ts.h;
    PQ.push(ts);
    while (!PQ.empty())
    {
        ts = PQ.top(); PQ.pop();
        u = ts.u; dis_u = ts.g;
        inQ[u]++;
        if (inQ[t] == k) return ts.f;
        if (inQ[u] > k) continue;
        for (i = L[u]; i > -1; i = E[i].next)
            if (i % 2 == 0)
            {
                ts.u = E[i].v;
                ts.g = dis_u + E[i].w;
                ts.h = h[ts.u];
                ts.f = ts.g + ts.h;
                PQ.push(ts);
            }
    }
    return -1;
}
//END.

int main()
{
    int u, v, w;
    scanf("%d%d", &n, &m);
    G_init();
    while (m--)
    {
        scanf("%d%d%d", &u, &v, &w);
        AE(u - 1, v - 1, w);
    }
    scanf("%d%d%d", &s, &t, &k);
    s--; t--;
    if (s == t) k++;
    printf("%d\n", AStar_FKSP());

    return 0;
}
