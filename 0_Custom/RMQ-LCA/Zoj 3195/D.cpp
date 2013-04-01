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
#define MAXN (50050 << 1)

struct Edge
{
	int v, w, next;
};
vector<Edge> E;
int L[MAXN];
void G_ini()
{
	E.clear();
	MS(L, -1);
}
void AE(int u, int v, int w)
{
	Edge te = {v, w, L[u]};
	L[u] = E.size();
	E.push_back(te);
}

int n, q, dep[MAXN], ind, ta[MAXN], id[MAXN], dis[MAXN];

void TTI(int u, int fa)
{
	if (fa != -1) dep[u] = dep[fa] + 1;
	id[u] = ind;
	ta[ind++] = u;
	for (int i = L[u]; i != -1; i = E[i].next)
		if (E[i].v != fa)
		{
			dis[E[i].v] = dis[u] + E[i].w;
			TTI(E[i].v, u);
			ta[ind++] = u;
		}
}

int st[20][MAXN];
int low(int x)
{
	int o = 0;
	while ((1 << o) <= x) o++;
	return o;
}
void st_ini()
{
	Rep(i, 0, ind) st[0][i] = ta[i];
	int l = low(ind);
	Rep(i, 1, l) Rep(j, 0, ind)
		if (j + (1 << i) < ind)
		{
			int x = st[i - 1][j],
				y = st[i - 1][j + (1 << (i - 1))];
			st[i][j] = (dep[x] < dep[y])? x: y;
		}
}
int rmq(int x, int y)
{
	x = id[x];
	y = id[y];
	if (x > y) swap(x, y);
	int l = low(y - x + 1) - 1;
	x = st[l][x];
	y = st[l][y - (1 << l) + 1];
	return (dep[x] < dep[y])? x: y;
}

bool cmp(int p, int q)
{
	if (dep[p] != dep[q]) return dep[p] < dep[q];
	return p < q;
}

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif
	bool spa = 0;
	while (~scanf("%d", &n))
	{
		if (spa) puts(""); 
		spa = 1;
		G_ini();
		Rep(i, 0, n - 1)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			AE(u, v, w);
			AE(v, u, w);
		}
		MS(dep, 0);
		MS(dis, 0);
		TTI(ind = 0, -1);
		st_ini();
		scanf("%d", &q);
		vector<int> x;
		while (q--)
		{
			int tx;
			x.clear();
			Rep(i, 0, 3)
			{
				scanf("%d", &tx);
				x.push_back(tx);
			}
			tx = x.size();
			Rep(i, 0, tx) Rep(j, 0, tx)
				x.push_back(rmq(x[i], x[j]));
			sort(x.begin(), x.end(), cmp);
			x.erase(unique(x.begin(), x.end()), x.end());
			int res = 0;
			Rep(i, 1, x.size())
				Nre(j, i - 1, -1)
				{
					if (rmq(x[i], x[j]) == x[j])
					{
						res += dis[x[i]] - dis[x[j]];
						break;
					}
				}
			printf("%d\n", res);
		}
	}
	return 0;
}
