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
#define INFL (0x7fffffffffffffffLL)
#define MOD ()
#define MAXN (500050)
//Type-Alias
typedef long long LL;
typedef long double LD;
typedef int AI[MAXN];
typedef bool AB[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];

//CMQ
struct Vec
{
	LL x, y;
	Vec(LL _x = 0, LL _y = 0): x(_x), y(_y) {};
	friend Vec operator - (Vec p, Vec q)
	{
		return Vec(p.x - q.x, p.y - q.y);
	}
	friend LL operator % (Vec p, Vec q)
	{
		return p.x * q.y - p.y * q.x;
	}
} _Vec;
struct CMQ
{
	Vec Q[MAXN];
	int hd, tl;
	void ini()
	{
		hd = tl = 0;
	}
	LL fun(LL k, LL x, LL y)
	{
		return y - k * x;
	}
	void ins(Vec v)
	{
		while (hd + 1 < tl)
		{
			if ((Q[tl - 2] - v) % (Q[tl - 1] - v) > 0)
				break;
			tl--;
		}
		Q[tl++] = v;
	}
	LL pop(LL k)
	{
		LL res = INFL; 
		while (hd < tl)
		{
			LL cb = fun(k, Q[hd].x, Q[hd].y);
			if (cb > res) break;
			hd++;
			res = cb;
		}
		hd--;
		return res;
	}
	void tra()
	{
		printf("CMQ:");
		Rep(i, hd, tl) printf("(%5lld, %5lld)", Q[i].x, Q[i].y);
		puts("");
	}
} cmq;

int n, k;
AI c;
ALL s = {0}, dp = {0};

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
		scanf("%d%d", &n, &k);
		MS(dp, 0);
		Rep(i, 1, n + 1)
		{
			dp[i] = 1LL * MAXN * MAXN;
			scanf("%d", c + i);
			s[i] = s[i - 1] + c[i];
		}
		cmq.ini();
		Rep(i, k, n + 1)
		{
			LL j = i - k + 1;
			cmq.ins(Vec(c[j], dp[j - 1] - s[j - 1] + (j - 1) * c[j]));
			dp[i] = s[i] + cmq.pop(i);
		}
		//Solve
		printf("%lld\n", dp[n]);
	}
	return 0;
}
