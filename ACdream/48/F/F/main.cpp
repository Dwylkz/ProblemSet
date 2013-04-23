#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define MAXN 55000
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define INFI 1e16
typedef long long LL;
typedef pair<LL, LL> PA;

struct  Edge
{
    int v, w, next;
};
vector<Edge> E;
int L[MAXN];
void G_ini()
{
    E.clear();
    memset(L, -1, sizeof L);
}
void AE(int u, int v, int w)
{
    Edge te = {v, w, L[u]};
    L[u] = E.size();
    E.push_back(te);
}

int n, m;
LL mn, sdp, dp[MAXN], sum[MAXN];

bool vis[MAXN];
PA DFS_U(int u)
{
    LL tp = 0, ts = 0;
    vis[u] = 1;
    for (int i = L[u]; i != -1; i = E[i].next)
    {
        int v = E[i].v, w = E[i].w;
        if (!vis[v])
        {
            PA td = DFS_U(v);
            tp += td.first;
            ts += td.first * w + td.second;
        }
    }
    dp[u] += tp;
    sum[u] = ts;
    return make_pair(dp[u], sum[u]);
}

void DFS_D(int u, int e)
{
    vis[u] = 1;
    if (e != -1)
    {
        int fa = E[e ^ 1].v, w = E[e].w;
        sum[u] += sum[fa] - sum[u] - dp[u] * w;
        sum[u] += E[e ^ 1].w * (sdp - dp[u]);
    }
    mn = min(mn, sum[u]);
    for (int i = L[u]; i != -1; i = E[i].next)
    {
        int v = E[i].v;
        if (!vis[v]) DFS_D(v, i);
    }
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif
    int Cas;

    scanf("%d", &Cas);
    while (Cas--)
    {
        G_ini();
        scanf("%d", &n);
        Rep(i, 0, n - 1)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            AE(u, v, w);
            AE(v, u, w);
        }
        scanf("%d", &m);
        memset(sum, 0, sizeof sum);
        memset(dp, 0, sizeof dp);
        sdp = 0;
        while (m--)
        {
            int u, w;
            scanf("%d%d", &u, &w);
            sdp += w;
            dp[u] = w;
        }
        memset(vis, 0, sizeof vis);
        DFS_U(1);
        memset(vis, 0, sizeof vis);
        mn = INFI;
        DFS_D(1, -1);
        printf("%lld\n", mn * 2);
        int i;
        for (i = 1; i <= n; i++) if (sum[i] == mn)
        {
            printf("%d", i);
            break;
        }
        for (i++; i <= n; i++) if (sum[i] == mn)
            printf(" %d", i);
        puts("");
    }

    return 0;
}
