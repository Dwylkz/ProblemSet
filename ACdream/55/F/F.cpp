//Header
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
//Macro
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
#define MAXN (1001)
//Type-Alias
typedef long long LL;
typedef long double LD;
typedef int AI[MAXN];
typedef bool AB[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];
typedef AI AI2[MAXN];

int dr[3][2] = {{0, -1}, {-1, -1}, {-1, 0}};
typedef struct SGV
{
	int s[4], d[4][2];
	SGV()
	{
		Rep(i, 0, 4)
		{
			s[i] = 1;
			d[i][0] = -MAXN;
			d[i][1] = MAXN;
		}
	}
	void set(int _s)
	{
		Rep(i, 0, 4)
		{
			s[i] = d[i][_s] = _s;
			d[i][!_s] = _s? MAXN: -MAXN;
		}
	}
	void upd(SGV *p, int x)
	{
		Rep(i, x, 4)
		{
			s[i] &= p->s[x];
			d[i][0] = max(d[i][0], p->d[x][1] + 1);
			d[i][1] = min(d[i][1], p->d[x][0] + 1);
			if (i < 3) i = 3 - 1;
		}
	}
	void uni()
	{
		s[3] ^= 1;
		Rep(i, 0, 3)
		{
			s[i] &= s[3];
			if (s[i]) d[3][0] = MAXN;
			else d[3][1] = -MAXN;
			d[i][0] = min(d[i][0], d[3][0]);
			d[i][1] = max(d[i][1], d[3][1]);
		}
	}
} *PSGV;
SGV sg[MAXN][MAXN];
void SG_ini()
{
	sg[0][0].set(0);
	Rep(i, 1, MAXN)
	{
		sg[i][0].set(1);
		sg[0][i].set(1);
	}
	Rep(i, 1, MAXN) Rep(j, 1, MAXN)
	{
		Rep(k, 0, 3) sg[i][j].upd(sg[i + dr[k][0]] + j + dr[k][1], k);
		sg[i][j].uni();
	}
#if 1
	Rep(i, 0, 11) PA(" ", j, 0, 11, " %4d", sg[i][j].s[3]);
#endif
}

int x, y, p;

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
#endif
	SG_ini();
	int T;
	scanf("%d", &T);
	while (T--)
	{
		//Initialize
		//Solve
		scanf("%d%d%d", &x, &y, &p);
		if (sg[x][y].s[3]) printf("Sita %d\n", sg[x][y].d[3][1]);
		else printf("Gita %d\n", sg[x][y].d[3][0]);
	}
	return 0;
}
