#include<queue>
#include<iostream>
using namespace std;
#define MAXI 15
#define INFI 0x7fffffff
#define min(x, y) x < y? x : y

int n, m, c[MAXI][MAXI], f[MAXI][MAXI], pre[MAXI], tf[MAXI], maxf;

bool BFS(int s, int t)
{
	int u, v;
	queue<int> Q;
	
	memset(pre, -1, sizeof pre);
	Q.push(s); pre[s] = -11; tf[s] = INFI;
	while (!Q.empty())
	{
		u = Q.front(); Q.pop();
		for (v = 0; v < n; v++)
			if (c[u][v] > f[u][v] && pre[v] == -1)
			{
				tf[v] = min(tf[u], c[u][v] - f[u][v]);
				pre[v] = u; Q.push(v);
			}
	}
	if (pre[t] == -1) return 0;
	maxf += tf[t];
	for (v = t; pre[v] > -1; v = u)
	{
		u = pre[v];
		f[u][v] += tf[t];
		f[v][u] -= tf[t];
	}
	return 1;
}

int main()
{
	int m, u, v, w, T, Case = 0;
	
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		memset(c, 0, sizeof c);
		memset(f, 0, sizeof f);
		while (m--)
		{
			scanf("%d%d%d", &u, &v, &w);
			c[u - 1][v - 1] += w;
		}
		for (maxf = 0; (BFS(0, n - 1)););
		printf("Case %d: %d\n", ++Case, maxf);
	}
	return 0;
}