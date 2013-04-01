#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define MAXN (2000)
#define MAXC (40)

struct Edge
{
    int v, next;
};
vector <Edge> E;
int L[MAXN];

void G_ini()
{
    Clr(L, MAXN, -1);
    E.clear();
}

void AE(int u, int v)
{
    Edge te = {v, L[u]};
    L[u] = E.size();
    E.push_back(te);
}

int n, id[MAXN], deg[MAXN], odd;
bool vis[MAXN], fin;
char W[MAXN][MAXC];
vector<int> S;

bool DFS(int x, int d)
{
    int i;

    S.push_back(x);
    #if 0
        printf(" n = %d %s\n", d, W[x]);
    #endif
    if (d == n - 1)
    {
        Rep(i, 0, S.size())
        {
            printf("%s", W[S[i]]);
            if (i < S.size() - 1)
                putchar('.');
        }
        putchar('\n');
        fin = 1;
    }
    vis[x] = 1;
    for (i = L[x]; i != -1; i = E[i].next)
        if (!vis[E[i].v])
            DFS(E[i].v, d + 1);
    vis[x] = 0;
    S.pop_back();

    return 0;
}

bool cmp(int a, int b)
{
    return strcmp(W[a], W[b]) == -1;
}

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif
    int T;

    scanf("%d", &T);
    while (T--)
    {
        G_ini();
        Clr(deg, MAXN, 0);
        scanf("%d", &n);
        Rep(i, 0, n)
        {
            id[i] = i;
            scanf("%s", W[i]);
        }
        sort(id, id + n, cmp);
        Rep(i, 0, n) Rep(j, i + 1, n)
        if (i != j && W[id[i]][strlen(W[id[i]]) - 1] == W[id[j]][0])
        {
            AE(id[i], id[j]);
            deg[id[i]]++;
            deg[id[j]]++;
        }
        #if 0
            Rep(i, 0, n)
                printf(" %s = %d\n", W[id[i]], deg[id[i]]);
            putchar('\n');
        #endif
        fin = 1;
        /*Rep(i, 0, n)
        {
            if (deg[i] % 2)
                odd++;
            if (!deg[i])
                fin = 0;
        }
        if (fin && odd > 2) fin = 0;*/
        if (fin)
        {
            fin = 0;
            S.clear();
            Clr(vis, MAXN, 0);
            Rep(i, 0, n)
            {
                DFS(id[i], 0);
                if (fin) break;
            }
            if (!fin) puts("***");
        }
        else puts("***");
    }

    return 0;
}
