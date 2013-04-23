/*
Intuitively, according to the declaration of the problem, we have

Definition
	s[i] as the coordinate ith point need to be covered.
 	dp[i] as the minimum cost to cover the walkway within [0, i],

Thus,
 	dp[i] = min(dp[j - 1] + (s[i] - s[j])^2 + c), j ∈ [0, i]
 	dp'[i] = dp[j - 1] + s[i]^2 + s[j]^2 - 2 * s[i] * s[j] + c
 	(dp[j - 1] + s[j]^2) = (dp'[i] - s[i]^2 - c) + 2 * s[i] * s[j]

We can ignore s[i]^2 and c as they are both constant.

	y = dp[j - 1] + s[j]^2
	k = 2 * s[i]
	x = s[j]
	b = dp'[i]

	y = k * x + b

So, the problem now is for each slope k, to find a point(x, y)
with the minimum intercept.

We can also say
	Construct the convex hull of all point(x, y).
	Find a tangent of the convex hull which has y = k * x + b form.

Besides k = 2 * s[i] is increasing monotonically,
thus the points before the optimal point can be discarded
and we the lower-right part of the convex hull is what we need.

As to maintain the lower-right part of the convex hull,
we use a queue which has two operations.

	Insert
		Check the queue reversely, calculate the cross product
		of the inserting point and last two points 
	
	Pop
		Check the queue sequentially, until the current intercept
		larger than previous one.

The alogrithm above AKA slope optimize dynamic programming.
 */
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
#define MAXN (1000010)
//Type-Alias
typedef long long LL;
typedef long double LD;
typedef int AI[MAXN];
typedef bool AB[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];
typedef LD ALD[MAXN];

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
} zkl;

int n, c;
LL dp[MAXN];

int main()
{
#if 1
	freopen("test.txt", "r", stdin);
	freopen("test.out", "w", stdout);
#endif
	while (scanf("%d%d", &n, &c), n || c)
	{
		//Initialize
		zkl.ini();
		Rep(i, 0, n)
		{
			int k;
			scanf("%d", &k);
			LL kk = 1LL * k * k;
			zkl.ins(Vec(k, bool(i) * dp[i - 1] + kk));
			dp[i] = kk + zkl.pop(k << 1) + c;
		}
		//Solve
		printf("%lld\n", dp[n - 1]);
	}
	return 0;
}
