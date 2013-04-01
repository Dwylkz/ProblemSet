#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define MAXN (200000)
#define MAXI (0x7fffffff)

struct Edge
{
    int v, w, next;
};
vector<Edge> E;
int L[MAXN];

void G_ini()
{
    Clr(L, MAXN, -1);
    E.clear();
}

void AE(int u, int v, int w)
{
    Edge t = {v, w, L[u]};
    L[u] = E.size();
    E.push_back(t);
}

int n, toc[MAXN], sum, mini;

void DFS(int u, int tsu)
{
    int i;

    if (toc[u] - tsu < mini)
        mini = toc[u] - tsu;

    for (i = L[u]; i != -1; i = E[i].next)
    {
        sum += E[i].w;
        DFS(E[i].v, tsu + E[i].w);
        sum += E[i].w;
    }
}

int main()
{
    #if 0
        freopen("test.txt", "rt", stdin);
    #endif

    int u, v, w;

    while (~scanf("%d", &n))
    {
        G_ini();
        Rep(i, 0, n + 1)
            scanf("%d", toc + i);
        Rep(i, 0, n)
        {
            scanf("%d%d%d", &u, &v, &w);
            AE(u, v, w);
        }
        sum = 0;
        mini = MAXI;
        DFS(0, 0);
        #if 0
            printf(" tsu = %d mini = %d\n", sum, mini);
        #endif
        printf("%d\n", sum + mini);
    }

    return 0;
}
