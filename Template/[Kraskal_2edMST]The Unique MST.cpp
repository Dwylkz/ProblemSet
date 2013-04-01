#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Macro
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(a, b) memset(a, b, sizeof a)
#define MAXN 101
#define INF32 0x7fffffff
//End.

struct Edge
{
    int u, v, w;
    bool ste;
    friend bool operator < (Edge a, Edge b)
    {
        return a.w < b.w;
    }
    Edge(int tu = 0, int tv = 0, int tw = 0)
    {
        u = tu; v = tv; w = tw; ste = false;
    }
};
vector<Edge> E;
int n, m;

//Kruskal_2ed-MST
class UFS
{
public :
    vector<int> pre, rank;
    int l;
    void ini(int n)
    {
        pre.clear();
        rank.clear();
        Rep(i, 0, n)
        {
            pre.push_back(i);
            rank.push_back(0);
        }
    }
    int fin(int x)
    {
        if (x != pre[x]) pre[x] = fin(pre[x]);
        return pre[x];
    }
    bool uni(int x, int y)
    {
        x = fin(x);
        y = fin(y);
        if (x == y) return false;
        if (rank[x] < rank[y])
            pre[x] = y;
        else
        {
            if (rank[x] == rank[y]) rank[x]++;
            pre[y] = x;
        }
        return true;
    }
} zkl;
struct Mst_Edge
{
    int v, w, next;
} te;
vector<Mst_Edge> ME;
int L[MAXN], maxi[MAXN][MAXN];
bool vis[MAXN];

void AE(int u, int v, int w)
{
    te.v = v; te.w = w;
    te.next = L[u];
    ME.push_back(te);
    L[u] = ME.size() - 1;
    te.v = u;
    te.next = L[v];
    ME.push_back(te);
    L[v] = ME.size() - 1;
}

int Kruskal()
{
    int mst = 0;
    ME.clear();
    Rep(i, 0, n) L[i] = -1;
    sort(E.begin(), E.end());
    zkl.ini(n);
    Rep(i, 0, E.size())
        if (zkl.uni(E[i].u, E[i].v))
        {
            mst += E[i].w;
            E[i].ste = true;
            AE(E[i].u, E[i].v, E[i].w);
        }
    return mst;
}

void DFS(int u, int v, int tmax)
{
    int i, ttm;
    vis[v] = true;
    for (i = L[v]; i > -1; i = ME[i].next)
        if (!vis[ME[i].v])
        {
            ttm = max(tmax, ME[i].w);
            maxi[u][ME[i].v] = ttm;
            DFS(u, ME[i].v, ttm);
        }
}

bool Unique(int &mst)
{
    int ms2 = INF32;
    mst = Kruskal();
    Rep(i, 0, n) Rep(j, 0, n)
        maxi[i][j] = 0;
    Rep(u, 0, n)
    {
        Rep(i, 0, n) vis[i] = false;
        DFS(u, u, 0);
    }
    Rep(i, 0, E.size())
        if (!E[i].ste && mst - maxi[E[i].u][E[i].v] + E[i].w < ms2)
            ms2 = mst - maxi[E[i].u][E[i].v] + E[i].w;
    return ms2 != mst;
}
//End.

int main()
{
    int T, u, v, w, mst;

    scanf("%d", &T);
    while (T--)
    {
        E.clear();
        scanf("%d%d", &n, &m);
        Rep(i, 0, m)
        {
            scanf("%d%d%d", &u, &v, &w);
            u--; v--;
            E.push_back(Edge(u, v, w));
        }
        if (Unique(mst))
            printf("%d\n", mst);
        else printf("Not Unique!\n");
    }

    return 0;
}
