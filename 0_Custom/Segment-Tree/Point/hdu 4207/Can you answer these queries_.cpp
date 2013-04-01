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
#define Rep(c, a, b) for (int c = (a); c < (b); c++)
#define Nre(c, a, b) for (int c = (a); c > (b); c--)
#define MAXN (110000)
typedef long long LL;

struct SGT
{
#define ls(x) (x << 1)
#define rs(x) (ls(x) | 1)
	typedef int TI[MAXN << 2];
	TI l, m, r;
	LL sm[MAXN << 2];
	bool on[MAXN << 2];
	void bui(LL *s, int h, int o, int x = 1)
	{
		l[x] = h;
		r[x] = o;
		m[x] = (h + o) >> 1;
		if (h == o)
		{
			set(s[h], x);
			return ;
		}
		bui(s, h, m[x], ls(x));
		bui(s, m[x] + 1, o, rs(x));
		upd(x);
	}
	void set(LL a, int x)
	{
		sm[x] = a;
		if (sm[x] < 2) on[x] = 1;
		else on[x] = 0;
	}
	void upd(int x)
	{
		sm[x] = sm[ls(x)] + sm[rs(x)];
		on[x] = on[ls(x)] & on[rs(x)];
	}
	void inb(int h, int o, int x = 1)
	{
		if (l[x] == r[x]) set(LL(sqrt(double(sm[x]))), x);
		else
		{
			inb(h, o, ls(x));
			inb(h, o, rs(x));
			upd(x);
		}
	}
	void ins(int h, int o, int x = 1)
	{
		if (h <= l[x] && r[x] <= o)
		{
			if (!on[x]) inb(h, o, x);
		}
		else
		{
			if (h <= m[x]) ins(h, o, ls(x));
			if (m[x] < o) ins(h, o, rs(x));
			upd(x);
		}
	}
	LL que(int h, int o, int x = 1)
	{
		LL tsm = 0;
		if (h <= l[x] && r[x] <= o) tsm = sm[x];
		else
		{
			if (h <= m[x]) tsm += que(h, o, ls(x));
			if (m[x] < o) tsm += que(h, o, rs(x));
		}
		return tsm;
	}	
} sgt;

LL s[MAXN];
int n, m;

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif
	int Cas = 1;

	while (~scanf("%d", &n))
	{
		Rep(i, 0, n) scanf("%lld", s + i);
		sgt.bui(s, 0, n - 1);
		scanf("%d", &m);
		printf("Case #%d:\n", Cas++);
		while (m--)
		{
			int T, x, y;
			scanf("%d%d%d", &T, &x, &y);
			x--; y--;
			if (x > y) swap(x, y);
			if (T) printf("%lld\n", sgt.que(x, y));
			else sgt.ins(x, y);
#if 0
			printf("%d: [%4d, %4d]:", T, x, y);
			Rep(i, 0, n) printf(" %4lld", sgt.que(i, i));
			puts("");
#endif
		}
		puts("");
	}

	return 0;
}
