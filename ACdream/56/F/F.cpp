#if 1 //Header
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
#include <cmath>
using namespace std;
#endif
#if 1 //Macro
//STL-Alias
#define UN(c, a) unique(c, a)
#define MS(c, a) memset(c, a, sizeof c)
#define FLC(c, a ,b) fill(c, c + a, b)
#define LOS(c, a, b) lower_bound(c, a, b)
#define UPS(c, a, b) upper_bound(c, a, b)
//Syntax-Alias
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
//DEBUG
#define FK puts("Fu*k here!")
#define PA(s, c, a, b, p, f){\
	printf(s);\
	Rep(c, a, b) printf(p, (f));\
	puts("");}
//Constant
#define INFI (0x7fffffff)
#define MOD ()
#define MAXN (1100)
//Type-Alias
typedef long long LL;
typedef long double LD;
typedef int AI[MAXN];
typedef bool AB[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];
#endif

struct Flo
{
	int fd, id;
	Flo(int _fd = 0, int _id = 0): fd(_fd), id(_id) {};
	friend bool operator < (Flo p, Flo q)
	{
		return p.fd < q.fd;
	}
	friend bool operator == (Flo p, Flo q)
	{
		return p.fd == q.fd;
	}
};
vector<Flo> W[MAXN];

struct Bri
{
	int b1, f1, b2, f2, t;
	void inp()
	{
		scanf("%d%d%d%d%d", &b1, &f1, &b2, &f2, &t);
	}
} B[MAXN];

int n, m, f, q, ind, G[MAXN][MAXN];

void Fyd()
{
	Rep(k, 0, ind) Rep(u, 0, ind)
		Rep(v, 0, ind) if (G[u][v] - G[k][v] > G[u][k])
			G[u][v] = G[u][k] + G[k][v];
}

Flo LBS(vector<Flo> s, int x)
{
	Flo res(-1);
	int l = 0, r = s.size() - 1;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		if (s[m].fd <= x)
		{
			res = s[m];
			l = m + 1;
		}
		else r = m - 1;
	}
	return res;
}
Flo RBS(vector<Flo> s, int x)
{
	Flo res(-1);
	int l = 0, r = s.size() - 1;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		if (x <= s[m].fd)
		{
			res = s[m];
			r = m - 1;
		}
		else l = m + 1;
	}
	return res;
}

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		//Initialize
		scanf("%d%d%d", &n, &f, &m);
		Rep(i, 1, n + 1)
		{
			W[i].clear();
			W[i].push_back(Flo(1));
			W[i].push_back(Flo(f));
		}
		Rep(i, 0, m)
		{
			B[i].inp();
			W[B[i].b1].push_back(Flo(B[i].f1));
			W[B[i].b2].push_back(Flo(B[i].f2));
		}
		Rep(i, 0, MAXN) Rep(j, 0, MAXN) G[i][j] = INFI;
		Rep(i, 0, MAXN) G[i][i] = 0;
		ind = 0;
		Rep(i, 1, n + 1)
		{
			sort(W[i].begin(), W[i].end());
			W[i].erase(unique(W[i].begin(), W[i].end()), W[i].end());
			Rep(j, 0, W[i].size())
			{
				W[i][j].id = ind++;
				if (j)
					G[W[i][j].id][W[i][j - 1].id] =
					G[W[i][j - 1].id][W[i][j].id] =
					W[i][j].fd - W[i][j - 1].fd;
			}
			if (i > 1)
				G[W[i][0].id][W[i - 1][0].id] =
				G[W[i - 1][0].id][W[i][0].id] = 1;
		}
		G[W[n][0].id][W[1][0].id] =
		G[W[1][0].id][W[n][0].id] = 1;
#if 0
		Rep(i, 1, n + 1)
		{
			printf("Tower %d:", i);
			Rep(j, 0, W[i].size())
				printf(" %4d", W[i][j].fd);
			puts("");
		}
#endif
		Rep(i, 0, m)
		{
			Flo u, v;
			u = LBS(W[B[i].b1], B[i].f1);
			v = LBS(W[B[i].b2], B[i].f2);
			G[u.id][v.id] = G[v.id][u.id] = B[i].t;
		}
		//Solve
		Fyd();
		scanf("%d", &q);
		while (q--)
		{
			int b1, f1, b2, f2;
			scanf("%d%d%d%d", &b1, &f1, &b2, &f2);
			if (b1 == b2 && f1 == f2)
			{
				puts("0");
				continue;
			}
			Flo ul = LBS(W[b1], f1), uu = RBS(W[b1], f1),
				vl = LBS(W[b2], f2), vu = RBS(W[b2], f2);
			LL  duu = uu.fd - f1, dum = G[ul.id][uu.id], dul = f1 - ul.fd,
				dvu = vu.fd - f2, dvm = G[vl.id][vu.id], dvl = f2 - vl.fd,
				d1 = min(duu, dum + dul) + G[uu.id][vu.id] + min(dvu, dvm + dvl),
				d2 = min(duu, dum + dul) + G[uu.id][vl.id] + min(dvl, dvm + dvu),
				d3 = min(dul, dum + duu) + G[ul.id][vu.id] + min(dvu, dvm + dvl),
				d4 = min(dul, dum + duu) + G[ul.id][vl.id] + min(dvl, dvm + dvu);
			printf("%lld\n", min(d1, min(d2, min(d3, d4))));
#if 0
			printf("duu = %d dul = %d\ndvu = %d dvl = %d\n",
					duu, dul,
					dvu, dvl);
			printf("(%d, %d) ul = %d, uu = %d\n(%d, %d) vl = %d, vu = %d\n",
					b1, f1, ul.fd, uu.fd,
					b2, f2, vl.fd, vu.fd);
#endif
		}
	}
	return 0;
}
