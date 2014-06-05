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
#define FL(c, a ,b) fill(c, c + a, b)
#define MS(c, a) memset(c, a, sizeof c)
#define LOW(a, b, c) lower_bound(a, b, c)
#define UPP(a, b, c) upper_bound(a, b, c)
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
#define MAXN (500050)
typedef long long LL;
typedef int AI[MAXN];
typedef double AD[MAXN];
typedef LL ALL[MAXN];

struct Que
{
	int a, b, i;
} Q[MAXN];
bool cmpb(Que p, Que q)
{
	if (p.b != q.b) return p.b > q.b;
	return p.a > q.a;
}

struct DST
{
	vector<int> D;
	void ini(int *s, int n)
	{
		D.clear();
		Rep(i, 0, n) D.push_back(s[i]);
		sort(D.begin(), D.end());
		D.erase(unique(D.begin(), D.end()), D.end());
	}
	int operator [] (int x)
	{
		return LOW(D.begin(), D.end(), x) - D.begin();
	}
} dst;

int n, m;
AI dol, pre, res;

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif
	while (~scanf("%d", &n))
	{
		//Initialize
		Rep(i, 0, n) scanf("%d", dol + i);
		dst.ini(dol, n);
		scanf("%d", &m);
		Rep(i, 0, m)
		{
			scanf("%d%d", &Q[i].a, &Q[i].b);
			Q[i].a--;
			Q[i].b--;
			Q[i].i = i;
		}
		sort(Q, Q + m, cmpb);
		//Solve
		int j = 0;
		MS(pre, -1);
		MS(res, -1);
		Nre(i, n - 1, -1)
		{
			int x = dst[dol[i]];
			if (pre[x] >= 0)
				for (; j < m && pre[x] <= Q[j].b; j++)
					if (Q[j].a <= i && res[Q[j].i] < 0)
						res[Q[j].i] = dol[i];
			pre[x] = i;
		}
		Rep(i, 0, m) printf((res[i] < 0)? "OK\n": "%d\n", res[i]);
		puts("");
	}
	return 0;
}
