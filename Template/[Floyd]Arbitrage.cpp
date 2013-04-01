#include<iostream>
#include<string>
using namespace std;
#define MAXI 35
#define CMAX 1000

int n , m;
double g[MAXI][MAXI];
char cur[MAXI][CMAX];

int find(char *tar)
{
	int i;
	for (i = 0; i < n; i++)
		if (strcmp(tar , cur[i]) == 0)
			return i;
	return i;
}

bool Floyd()
{
	int u , k , v;
	for (k = 0; k < n; k++)
		for (u = 0; u < n; u++)
			for (v = 0; v < n; v++)
				if (g[u][k] * g[k][v] > g[u][v])
					g[u][v] = g[u][k] * g[k][v];
	for (u = 0; u < n; u++)
		if (g[u][u] > 1.0) return 1;
	return 0;
}

int  main()
{
	char buf[CMAX];
	int i, j , Case = 0;
	double w;
	bool ok;

	while (scanf("%d" , &n) , n)
	{
		for (i = 0; i < n; i++)
			for (j = 0;j < n; j++)
				g[i][j] = 0;

		for (i = 0;i < n ; i++)
			scanf("%s" , cur[i]);

		ok = 0;
		scanf("%d" , &m);
		while (m--)
		{
			scanf("%s%lf" , buf , &w);
			i = find(buf);
			scanf("%s" , buf);
			j = find(buf);
			if (g[i][j] < w)
				g[i][j] = w;
			if (i == j && w > 1.0) ok = 1;
		}

		printf("Case %d: " , ++Case);
		if (ok) puts("Yes");
		else puts(Floyd()? "Yes" : "No");
	}
	return 0;
}
