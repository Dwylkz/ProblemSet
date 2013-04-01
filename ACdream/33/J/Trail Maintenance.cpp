#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define LL long long
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Nre(c, a, b) for (int c = a; c < b; c++)
#define MAXN (100000001)
#define INFI (0x7fffffff)
#define MAXM (10001)
#define MAXV (220)
#define MAXE (6600)
#define MODL (0x100000000LL)

struct Edge
{
    int u, v, w;
    friend bool operator < (Edge o1, Edge o2)
    {
        return o1.w < o2.w;
    }
} E[MAXE], md[MAXV][MAXV];

struct UFS
{
    int p[MAXV], r[MAXV], n;
    void ini(int tn)
    {
        n = tn;
        Rep(i, 0, n)
        {
            p[i] = i;
            r[i] = 0;
        }
    }
    bool uno()
    {
        int cou = 0;
        Rep(i, 0, n) if (i == p[i]) cou++;
        return cou == 1;
    }
    int fin(int x)
    {
        if (x != p[x]) p[x] = fin(p[x]);
        return p[x];
    }
    bool uni(int x, int y)
    {
        x = fin(x);
        y = fin(y);
        if (x == y) return 0;
        if (r[x] < r[y]) p[x] = y;
        else
        {
            if (r[x] == r[y]) r[x]++;
            p[y] = x;
        }
        return 1;
    }
} zkl;

int n, m, dp[MAXV][MAXV], mst = 0, G[MAXV][MAXV];
bool vis[MAXV];

void DP(int p, int u, int maxw, int mu, int mv)
{
    vis[u] = 1;
    Rep(v, 0, n) if (G[u][v] != INFI && !vis[v])
    {
        int tmax = 0, tu = mu, tv = mv;
        if (G[u][v] > maxw)
        {
            tmax = G[u][v];
            tu = u;
            tv = v;
        }
        dp[p][v] = G[u][v];
        md[p][v].u = tu;
        md[p][v].v = tv;
        DP(p, v, tmax, tu, tv);
    }
    vis[u] = 0;
}

int main()
{
    #if 1
        freopen("test.txt", "rt", stdin);
    #endif

    int T;

    scanf("%d", &T);
    Rep(C, 1, T + 1)
    {
        Rep(i, 0, n) Rep(j, 0, n) dp[i][j] = G[i][j] = INFI;
        scanf("%d%d", &n, &m);
        zkl.ini(n);
        printf("Case %d:\n", C);
        while (m--)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            u--;
            v--;
            if (dp[u][v] == INFI)
            {
                dp[u][v] = dp[v][u] = G[u][v] = G[v][u] = w;
                mst += w;
                zkl.uni(u, v);
            }
            else if (mst - dp[u][v] + w < mst)
            {
                mst += w - dp[u][v];
                G[u][v] = G[v][u] = w;
                G[md[u][v].u][md[u][v].v] = G[md[u][v].v][md[u][v].u] = INFI;
                DP(u, u, -INFI, -1, -1);
                DP(v, v, -INFI, -1, -1);
                zkl.uni(u, v);
            }
            if (zkl.uno()) printf("%d\n", mst);
            else puts("-1");
        }
    }

    return 0;
}
