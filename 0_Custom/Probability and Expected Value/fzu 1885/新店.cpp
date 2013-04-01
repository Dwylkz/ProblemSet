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
//STL-Alias
#define UN(c, a) unique(c, a)
#define MS(c, a) memset(c, a, sizeof c)
#define FLC(c, a ,b) fill(c, c + a, b)
#define LOS(c, a, b) lower_bound(c, a, b)
#define UPS(c, a, b) upper_bound(c, a, b)
//Syntax-Alias
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
//B-OP
#define LM(x, y) ((x) << (y))
#define RM(x, y) ((x) >> (y))
#define GB(x, y) (RM(x, y) & 1)
#define SB(x, y) (LM(1, y) | x)
#define SBI(x, a, b) ((LM(1, b) - LM(1, a)) | x)
#define CBI(x, a, b) (~(LM(1, b) - LM(1, a)) & x)
//DEBUG
#define FK puts("Fuck here!")
#define PA(s, c, a, b, p, f){\
	printf(s);\
	Rep(c, a, b) printf(p, (f));\
	puts("");}
//Constant
#define MAXN (1 << 16)
//Type-Alias
typedef long long LL;
typedef long double LD;
typedef int AI[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];

int n, m;
AD p, c, ex;

double DFS(int s)
{
	if (!s) return 0.0;
	if (ex[s]) return ex[s];
	double ps = 0;
	Rep(i, 1, m + 1)
	{
		double tp = 0;
		int ct = 0;
		Rep(l, 0, n) if (GB(s, l))
		{
			int r = l;
			for (; r < n && GB(s, r); r++);
			if (r - l >= i)
			{
				ct += r - l - i + 1;
				Rep(j, l, r - i + 1)
					tp += DFS(CBI(s, j, j + i));
			}
			l = r - 1;
		}
		if (ct)
		{
			ex[s] += (tp / ct + c[i] * i) * p[i];
			ps += p[i];
		}
	}
	if (ps > 0.0) ex[s] /= ps;
#if 0
	printf("ex = %lf ", ex[s]);
	PA("s:", k, 0, n, " %3d", GB(s, k));
#endif
	return ex[s];
}

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif
	int T;
	scanf("%d", &T);
	Rep(Cas, 1, T + 1)
	{
		//Initialize
		scanf("%d%d", &n, &m);
		Rep(i, 1, m + 1) scanf("%lf", p + i);
		Rep(i, 1, m + 1) scanf("%lf", c + i);
		//Solve
		MS(ex, 0);
		printf("Case %d:\n%.3lf\n\n", Cas, DFS(LM(1, n) - 1));
	}
	return 0;
}
