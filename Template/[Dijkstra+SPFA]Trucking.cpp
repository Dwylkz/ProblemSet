#include<iostream>
#include<queue>
using namespace std;
#define INFI 0x7fffffff
#define MAXI 1001

struct node
{
	int h , w;
} g[MAXI][MAXI];

int v , h , n , dp[MAXI];
bool vis[MAXI];

int Mem_DFS(int s , int minh)
{
	int  i , temph;
	
	if (dp[s] != 0) return dp[s];
	if (s == v) return minh;
	vis[s] = 1;
	
	for (i = 0; i < n; i++)
		if (!vis[i] && !(g[s][i].h == -1 && g[s][i].w == INFI))
		{
			if (g[s][i].h < minh) temph = Mem_DFS(i , g[s][i].h);
			else temph = Mem_DFS(i , minh);
			if (dp[s] < temph) dp[s] = temph;
		}

	vis[s] = 0;

	return dp[s];
}

void Dijkstra(int u , int minh)
{
	int i , j , tmax , temph;

	dp[u] = minh;
	
	for (i = 0; i < n; i++)
	{
		tmax = -11;
		for (j = 0; j < n; j++)
			if (!vis[j] && dp[j] > tmax)
			{
				tmax = dp[j];
				u = j;
			}
		vis[u] = 1;
		for (j = 0; j < n; j++)
			if (!vis[j] && g[u][j].h != -1)
			{
				if (g[u][j].h < dp[u]) temph = g[u][j].h;
				else temph = dp[u];
				if (temph > dp[j]) dp[j] = temph;
			}
	}
}

void SPFA(int u)
{
	int i;

	queue<int> Q;
	Q.push(u);
	vis[u] = 1;
	dp[u] = 0;

	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();
		vis[u] = 0;

		for (i = 0; i < n; i++)
			if (i != u && g[u][i].h >= h && dp[i] - dp[u] > g[u][i].w)
			{
				dp[i] = dp[u] + g[u][i].w;
				if (!vis[i])
				{
					Q.push(i);
					vis[i] = 1;
				}
			}
	}

}

int main()
{
	int u , w , m , Case = 0;
	bool ok;
	
	scanf("%d%d" , &n , &m);
	while (n || m)
	{
		ok = 1;
		for (u = 0; u < n; u++)
			for (v = 0; v < n; v++)
			{ 
				g[u][v].w = INFI;
				g[u][v].h = -1;
			}
			
		while (m--)
		{
			scanf("%d%d%d%d" , &u , &v , &h , &w);
			u--; v--;
			if (h == -1) h = INFI;
			
			if (g[u][v].h == h)
			{
				if (g[u][v].w > w)
					g[u][v].w = g[v][u].w = w;
			}
			else if (g[u][v].h < h)
			{
				g[u][v].h = g[v][u].h = h;
				g[u][v].w = g[v][u].w = w;
			}
		}
			
		for (u = 0; u < n; u++) 
		{
			dp[u] = 0;
			vis[u] = 0;
		}
			
		scanf("%d%d%d" , &u , &v , &h);			
		u--; v--;
			
		//dp[v] = Mem_DFS(u , h);

		Dijkstra(u , h);

		if (dp[v] != 0)
		{
			h = dp[v];
			for (w = 0; w < n; w++) 
			{
				dp[w] = INFI;
				vis[w] = 0;
			}

			SPFA(u);

			if (dp[v] != INFI) ok = 1;
		}
		else ok = 0;

		printf("Case %d:\n" , ++Case);

		if (ok)
		{
			printf("maximum height = %d\n" , h);
			printf("length of shortest route = %d\n" , dp[v]);
		}
		else printf("cannot reach destination\n");

		scanf("%d%d" , &n , &m);

		if (n || m) putchar('\n');
	}

	return 0;
}