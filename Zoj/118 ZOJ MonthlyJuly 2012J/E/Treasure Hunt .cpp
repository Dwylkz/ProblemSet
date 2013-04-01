#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c > b; c--)
#define MAXN (110)
#define MAXM (220)
#define INFI (0x7ffffffff)

int n, k, m, w[MAXN], G[MAXN][MAXN];
bool vis[MAXN];

void TDP(int u, int c, int tm, int *dp)
{
    if (tm > m) return ;
    int td[MAXM];
    bool leaf = 1;
    vis[u] = 1;
    Rep(v, 1, n + 1) if (G[u][v] && !vis[v])
    {
        leaf = 0;
        memset(td, 0, sizeof td);
        TDP(v, G[u][v], tm + G[u][v], td);
        Nre(i, m, c - 1) dp[i] = max(dp[i], td[i - c] + w[u]);
    }
    if (leaf) Nre(i, m, c - 1) dp[i] = w[u];
    #if 0
        printf(" %d %d %d:", leaf, w[u], u);
        Rep(i, 0, m + 1) printf(" %d", dp[i]);
        puts("");
    #endif
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    while (~scanf("%d", &n))
    {
        memset(G, 0, sizeof G);
        Rep(i, 1, n + 1) scanf("%d", w + i);
        Rep(i, 0, n - 1)
        {
            int u, v, t;
            scanf("%d%d%d", &u, &v, &t);
            G[u][v] = G[v][u] = t << 1;
        }
        scanf("%d%d", &k, &m);
        int dp[MAXM];
        memset(dp, 0, sizeof dp);
        memset(vis, 0, sizeof vis);
        TDP(k, 0, 0, dp);
        printf("%d\n", dp[m]);
    }

    return 0;
}
