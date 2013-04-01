#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (2000)
#define INFI (10000)
#define X2(x) (x * x)

struct Doll
{
    int w, l, h;
    friend bool operator > (Doll p, Doll q)
    {
        return p.w > q.w && p.l > q.l && p.h > q.h;
    }
} D[MAXN];

struct Edge
{
    int v, nxt;
};
vector<Edge> E;
int L[MAXN];

void G_ini()
{
    E.clear();
    memset(L, -1, sizeof L);
}

void AE(int u, int v)
{
    Edge te = {v, L[u]};
    L[u] = E.size();
    E.push_back(te);
}

int n, mat[MAXN];
bool vis[MAXN];

bool MM_DFS(int u)
{
    for (int i = L[u]; i != -1; i = E[i].nxt)
    {
        int v = E[i].v;
        if (!vis[v])
        {
            vis[v] = 1;
            if (mat[v] < 0 || MM_DFS(mat[v]))
            {
                mat[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int MM()
{
    int mm = 0;
    memset(mat, -1, sizeof mat);
    Rep(u, 0, n)
    {
        memset(vis, 0, sizeof vis);
        mm += MM_DFS(u);
    }
    return mm;
}

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif

    while (scanf("%d", &n), n)
    {
        G_ini();
        Rep(i, 0, n)
        {
            scanf("%d%d%d", &D[i].w, &D[i].l, &D[i].h);
            Rep(j, 0, i)
            {
                if (D[i] > D[j]) AE(i, j);
                if (D[j] > D[i]) AE(j, i);
            }
        }
        printf("%d\n", n - MM());
    }

    return 0;
}
