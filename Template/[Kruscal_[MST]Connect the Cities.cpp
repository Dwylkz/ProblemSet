#include <iostream>
#include <algorithm>
using namespace std;
#define MAX1 505
#define MAX2 25002

struct road
{ 
	int u, v, w;
	bool operator < (road o)
	{ return w < o.w; }
} G[MAX2];
int n, pre[MAX1], rank[MAX2];

void init(int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		rank[i] = 0;
		pre[i] = i;
	}
}

int Find(int x)
{
	if (x != pre[x]) pre[x] = Find(pre[x]);
	return pre[x];
}

bool Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x == y) return 0;
	if (rank[x] > rank[y])
		pre[y] = x;
	else
	{
		if (rank[x] == rank[y])
			rank[y]++;
		pre[x] = y;
	}
	return 1;
}

int main()
{
	int T, m, k, t, u, v, i, cost, tree;

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &m, &k);
		for (i = 0; i < m; i++)
			scanf("%d%d%d", &G[i].u, &G[i].v, &G[i].w);
		sort(G, G + m);
		init(n);
		while (k--)
		{
			scanf("%d%d", &t, &u);
			for (i = 1; i < t; i++)
			{
				scanf("%d", &v);
				Union(u, v);
				u = v;
			}
		}
		for (cost = i = 0; i < m; i++)
			if (Union(G[i].u, G[i].v))
				cost += G[i].w;
		for (tree = 0, i = 1; i <= n; i++)
			if (pre[i] == i) tree++;
		if (tree > 1) cost = -1;
		printf("%d\n", cost);
	}

	return 0;
}