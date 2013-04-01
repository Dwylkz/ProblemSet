#include <iostream>
#include <queue>
using namespace std;
#define MAXI 2002
#define INFI 0x7fffffff

int n, m, cost, len;
int dis[MAXI], g[MAXI][MAXI], pre[MAXI], vil[MAXI], inQ[MAXI], cho[MAXI];
bool hash[MAXI];


void SPFA(int s)
{
	int u, v;
	queue<int> Q;

	for (u = 1; u <= n; u++)
	{
		dis[u] = INFI;
		pre[u] = 0;
		inQ[u] = 0;
	}

	dis[s] = 0;
	inQ[s] = 1;
	Q.push(s);

	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();

		for (v = 1; v <= n; v++)
			if (dis[v] - g[u][v] > dis[u])
			{
				dis[v] = g[u][v] + dis[u];
				pre[v] = u;
				if (!inQ[v])
				{
					Q.push(v);
					inQ[v] = 1;
				}
			}
	}
}

void chose()
{
	int i, j, k, u, v;

	memset(hash, 0, sizeof hash);
	j = cost = k = 0;

	for (i = 0; i < m; i++)
	{
		v = vil[i];
		j++;

		while (v != 0)
		{
			u = pre[v];
			if (!hash[v])
			{
				hash[v] = 1;
				cho[k++] = v;
				if (u != 0)
					cost += g[u][v];
			}
			v = u;
		}
	}

	printf("%d\n", cost);
	
	len = k;
}

int main()
{
	int i, j, a, b, c;

	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (i = 0; i <= n; i++)
			for (j = 0; j <= n; j++)
				g[i][j] = INFI;

		for (i = 0; i < m; i++)
			scanf("%d", &vil[i]);
		for (i = 0; i < n - 1; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			g[a][b] = g[b][a] = c;
		}

		SPFA(vil[0]);
		chose();

#if 0
		printf("Vil : ");
		for (i = 0; i < m; i++)
			printf("%d ", vil[i]);
		putchar('\n');
		printf("Pre : ");
		for (i = 1; i <= n; i++)
			printf("%d ", pre[i]);
		putchar('\n');
		printf("Hash : ");
		for (i = 1; i <= n; i++)
			printf("%d ", hash[i]);
		putchar('\n');
		printf("Cho : ");
		for (i = 0; i < len; i++)
			printf("%d ", cho[i]);
		putchar('\n');
#endif
	}
	return 0;
}