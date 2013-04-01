#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
//MACRO
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN 5005
#define INFI 0x7fffffff
//END.

struct FS_Edge
{
    int v, w, next;
    //FS_Edge *next;
} tfe;//E[MAXN * MAXN], *L[MAXN];
vector<FS_Edge> E;
int L[MAXN], len, n, m;

void AE(int u, int v, int w)
{
    tfe.v = v; tfe.w = w;
    tfe.next = L[u];
    E.push_back(tfe);
    L[u] = E.size() - 1;
    tfe.v = u; tfe.next = L[v];
    E.push_back(tfe);
    L[v] = E.size() - 1;
    /*E[len].v = v; E[len].w = w;
    E[len].next = L[u];
    L[u] = E + len++;
    E[len].v = u; E[len].w = w;
    E[len].next = L[v];
    L[v] = E + len++;*/
}

//Heap_Dijkstra
struct Heap
{
    struct Heap_Ele
    {
        int key, val;
    } T[MAXN + 1];
    int size, P[MAXN + 1];
    void ini() { T[size = 0].val = -INFI; };
    int siz() { return size; }
    void shi(int key, int val, int pos)
    {
        int i, pre;
        Heap_Ele tp = {key, val};
        for (i = pos; tp.val < T[pre = i / 2].val; i = pre)
        {
            T[i] = T[pre];
            P[T[i].key] = i;
        }
        T[i] = tp;
        P[T[i].key] = i;
    }
    void ins(int key, int val) { shi(key, val, ++size); }
    void mdf(int key, int val) { shi(key, val, P[key]); }
    void pop()
    {
        int i, son;
        Heap_Ele tp = T[size--];
        for (i = 1; (son = i * 2) <= size; i = son)
        {
            if (son + 1 <= size && T[son + 1].val < T[son].val)
                son++;
            if (T[son].val < tp.val)
            {
                T[i] = T[son];
                P[T[i].key] = i;
            }
            else break;
        }
        T[i] =  tp;
        P[T[i].key] = i;
    }
} zkl;

void Dijkstra(int u, int *dis)
{
    FS_Edge *p;
    int i;
    zkl.ini();
    Rep(v, 0, n) zkl.ins(v, dis[v] = INFI);
    zkl.mdf(u, dis[u] = 0);
    for (u = zkl.T[1].key; zkl.siz(); u = zkl.T[1].key)
    {
        zkl.pop();
        /*for (p = L[u]; p; p = p->next)
            if (dis[p->v] - p->w > dis[u])
                zkl.mdf(p->v, dis[p->v] = dis[u] + p->w);*/
        for (i = L[u]; i > -1; i = E[i].next)
            if (dis[E[i].v] - E[i].w > dis[u])
                zkl.mdf(E[i].v, dis[E[i].v] = dis[u] + E[i].w);
    }
}
//End.

int main()
{
    int u, v, w, tsp, zdi[MAXN], ndi[MAXN], sp2 = INFI;

    scanf("%d%d", &n, &m);
    len = 0;
    E.clear();
    Rep(i, 0, n) L[i] = -1;
    Rep(i, 0, m)
    {
        scanf("%d%d%d", &u, &v, &w);
        AE(u - 1, v - 1, w);
    }
    Dijkstra(0, zdi);
    Dijkstra(n - 1, ndi);
    Rep(i, 0, E.size())
    {
        u = E[i ^ 1].v; v = E[i].v; w = E[i].w;
        tsp = zdi[u] + ndi[v] + w;
        if (zdi[n - 1] < tsp && tsp < sp2)
            sp2 = tsp;
        tsp = zdi[v] + ndi[u] + w;
        if (zdi[n - 1] < tsp && tsp < sp2)
            sp2 = tsp;
        i++;
    }
    printf("%d\n", sp2);

    return 0;
}
