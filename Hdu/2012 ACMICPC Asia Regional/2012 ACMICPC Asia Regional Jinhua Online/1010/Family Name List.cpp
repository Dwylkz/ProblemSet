/*
 Three operations
 	L     : the same as input, correspond to Preorder traversal.
 	b x   : correspond to ask how many sons does x's father have.
 	c x y : LCA(x, y), there is a trick, if LCA(x, y) is x or y,
		    you should output LCA(x, y)'s father,
		    because in our real life, one can't be one's ancestor.

 About sorting the brothers
 	We can use map to store their names.
	Then their names will be in alphabetical order.
	At last, Scan the map and construct the family tree.
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;
//STL
#define MS(c, a) memset(c, a, sizeof c)
//Syntax
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
//Constant
const int MAXN = 30005 << 1;
//Array
typedef int AI[MAXN];

//FSG
struct Edge{
    int v, next;
};
vector<Edge> E;
AI L;
void G_ini(){
	E.clear(); MS(L, -1);
}
void AE(int u, int v){
	Edge te = {v, L[u]};
	L[u] = E.size();
	E.push_back(te);
}
#define Ere(c, a, L) for (int c = L[a]; c != -1; c = E[c].next)

//RMQ
int  ind;
AI dep, ta, id, st[20];
void TTI(int u, int fa = -1)
{
	if (fa != -1) dep[u] = dep[fa] + 1;
	id[u] = ind;
	ta[ind++] = u;
	for (int i = L[u]; i != -1; i = E[i].next)
		if (E[i].v != fa)
		{
			TTI(E[i].v, u);
			ta[ind++] = u;
		}
}
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

int n, q;
AI fat, now, son;
char buf[MAXN];
string nam[MAXN];
map<string, int> H;
map<string, int>::reverse_iterator Hi; 

void LT(int u, int d = 0)
{
	Rep(i, 0, d) putchar('.');
	printf("%s\n", nam[u].c_str());
	Ere(i, u, L) LT(E[i].v, d + 1);
}

int main()
{
	while (scanf("%d", &n), n)
	{
		MS(fat, -1);
		MS(now, -1);
		MS(son, 0);
		H.clear();
		scanf("%s", buf);
		string ne = buf;
		H[ne] = 1;
		nam[now[0] = 0] = ne;
		Rep(i, 2, n + 1)
		{
			scanf("%s", buf);
			int k = 0;
			while (buf[k] == '.') k++;
			son[fat[i - 1] = now[k - 1]]++; 
			H[ne = buf + k] = i;
			nam[now[k] = i - 1] = ne;
		}
		G_ini();
		for (Hi = H.rbegin(); Hi != H.rend(); Hi++)
		{
			int v = Hi->second - 1, u = fat[v];
			if (Hi->second > 1) AE(u, v);
		}
		MS(dep, 0);
		TTI(ind = 0);
		st_ini();
		scanf("%d", &q);
		while (q--)
		{
			char op[3];
			scanf("%s", op);
			if (op[0] == 'L') LT(0);
			if (op[0] == 'b')
			{
				scanf("%s", buf);
				ne = buf;
				int u = H[ne] - 1;
				if (!u) puts("1");
				else printf("%d\n", son[fat[u]]);
			}
			if (op[0] == 'c')
			{
				scanf("%s", buf);
				ne = buf;
				int u = H[ne] - 1;
				scanf("%s", buf);
				ne = buf;
				int v = H[ne] - 1, p = rmq(u, v);
				if (p == u || p == v) p = fat[p];
				printf("%s\n", nam[p].c_str());
			}
		}
	}
	return 0;
}
