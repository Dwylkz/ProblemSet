#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <queue>
#include <stack>
using namespace std;
#define MS(c, a) memset(c, a, sizeof c)
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
#define MAXN (1024)

struct Edge
{
	int v, next;
};
vector<Edge> E; 
int L[MAXN];
void G_ini()
{
	E.clear();
	MS(L, -1);
}
void AE(int u, int v)
{
	Edge te = {v, L[u]};
	L[u] = E.size();
	E.push_back(te);
}

int n, l, s;
double dp[MAXN][MAXN];

void DFS(int u, int fa)
{
	MS(dp[u], 0);
	dp[u][0] = 1;
	for (int i = L[u]; i != -1; i = E[i].next)
	{
		int v = E[i].v;
		if (v != fa)
		{
			Rep(j, 1, s + 1) dp[u][j] += dp[u][j - 1];
			DFS(v, u);
			Nre(j, s, -1) if (!j)
				dp[u][j] = dp[u][j] * dp[v][j];
			else if (j + j <= s)
				dp[u][j] = dp[u][j] * dp[v][j] - dp[u][j - 1] * dp[v][j - 1];
			else
			{
				int k = s - j;
				dp[u][j] = dp[u][j] * dp[v][k] - dp[u][j - 1] * dp[v][k];
				dp[u][j] += dp[u][k] * dp[v][j] - dp[u][k] * dp[v][j - 1];
			}
		}
	}
	if (fa != -1)
	{
		Nre(i, s, - 1) Rep(j, max(0, i - l), i)
			dp[u][i] += dp[u][j];
		Rep(i, 0, s + 1) dp[u][i] /= 1 + l;
	}
	Rep(i, 1, s + 1) dp[u][i] += dp[u][i - 1];
}

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif
	int T, u, v;
	scanf("%d", &T);
	Rep(Cas, 1, T + 1)
	{
		scanf("%d%d%d", &n, &l, &s);
		G_ini();
		Rep(i, 0, n - 1)
		{
			scanf("%d%d", &u, &v);
			AE(u, v);
			AE(v, u);
		}
		DFS(1, -1);
		printf("Case %d: %.6lf\n", Cas, dp[1][s]);
	}
	return 0;
}
