#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXN (100010)
#define INFI (0x7fffffff)

struct Edge
{
    int u, v, w, next;
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
	Edge te = {-1, v, w, L[u]};
	L[u] = E.size();
	E.push_back(te);
}

int n, id, dp[MAXN], mx;
map<int, int> D;
bool vis[MAXN];

struct NCR
{
	int u, e, i;
};

void TDP(int u, int fa)
{
	dp[u] = 0;
	for (int i = L[u]; i != -1; i = E[i].next)
		if (E[i].v != fa)
		{
			TDP(E[i].v, u);
			if (dp[E[i].v] + E[i].w > 0) dp[u] += dp[E[i].v] + E[i].w;
		}
	mx = max(mx, dp[u]);
}

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif
    while (scanf("%d", &n), n)
    {
		G_ini();
        D.clear();
        id = 1;
        while (n--)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            if (!D[u]) D[u] = id++;
            if (!D[v]) D[v] = id++;
            u = D[u];
            v = D[v];
			AE(u, v, w);
			AE(v, u, w);
        }
		mx = 0; TDP(1, -1);
        printf("%d\n", mx);
    }

    return 0;
}
