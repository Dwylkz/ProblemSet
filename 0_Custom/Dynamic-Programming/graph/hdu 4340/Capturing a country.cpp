#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
#define MAXN (200)
#define INFI (0x7fffffff)

struct Edge
{
	int v, next;
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

int n, ta[MAXN], tb[MAXN], f[MAXN][2], g[MAXN][2];
bool vis[MAXN];

void TDP(int u)
{	
	vis[u] = 1;
	bool lef = 1;
	int ami = INFI, bmi = INFI;
	for (int i = L[u]; i != -1; i = E[i].next)
	{
		int v = E[i].v;
		if (vis[v]) continue;
		lef = 0;
		TDP(v);
		int tma = min(f[v][0], g[v][1]),
			tmb = min(g[v][0], f[v][1]);
		ami = min(ami, f[v][1] - tma);
		bmi = min(bmi, g[v][1] - tmb);
		f[u][0] += tma;
		g[u][0] += tmb;
	}
	if (lef)
	{
		f[u][1] = ta[u];
		g[u][1] = tb[u];
		f[u][0] = ta[u] >> 1;
		g[u][0] = tb[u] >> 1;
	}
	else
	{
		f[u][1] = f[u][0] + min(ta[u], ta[u] / 2 + ami);
		g[u][1] = g[u][0] + min(tb[u], tb[u] / 2 + bmi);
		f[u][0] += ta[u] >> 1;
		g[u][0] += tb[u] >> 1;
	}
}


int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif

	while (~scanf("%d", &n))
	{
		G_ini();
		Rep(i, 0, n) scanf("%d", ta + i);
		Rep(i, 0, n) scanf("%d", tb + i);
		Rep(i, 0, n - 1)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			u--; v--;
			AE(u, v);
			AE(v, u);
		}
		memset(vis, 0, sizeof vis);
		memset(f, 0, sizeof f);
		memset(g, 0, sizeof g);
		TDP(0);
#if 0
		Rep(u, 0, n) printf("%4d: %4d %4d\n",
				u, dp[u][0][1], dp[u][1][1]);
#endif
		printf("%d\n", min(f[0][1], g[0][1]));
	}

	return 0;
}
