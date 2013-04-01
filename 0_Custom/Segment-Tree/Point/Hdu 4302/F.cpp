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
#define MAXN (100010)
typedef long long LL;

struct BIA
{
	int t[MAXN];
	void ini()
	{
		MS(t, 0);
	}
	int low(int x)
	{
		return -x & x;
	}
	void upd(int x, int ad)
	{
		for (; x < MAXN; x += low(x)) t[x] += ad;
	}
	int operator [] (int x)
	{
		int tsu = 0;
		for (; x; x -= low(x)) tsu += t[x];
		return tsu;
	}
} bia;

int LBS(int l, int r)
{
	int ans = -1;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		if (bia[m] - bia[l - 1])
		{
			ans = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	return ans;
}

int RBS(int l, int r)
{
	int ans = -1;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		if (bia[r] - bia[m - 1])
		{
			ans = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	return ans;
}

int l, n;

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif
	int T, cd, cp, op, x, cl, cr;
	LL dis;
	scanf("%d", &T);
	Rep(Cas , 1, T + 1)
	{
		scanf("%d%d", &l, &n);
		l++;
		bia.ini();
		cd = cp = 1;
		dis = 0;
		while (n--)
		{
			scanf("%d", &op);
			if (op)
			{
				cl = RBS(1, cp);
				cr = LBS(cp, l);
				if (cl != -1 || cr != -1)
				{
					if (cl == -1)
					{
						dis += cr - cp;
						bia.upd(cr, -1);
						cp = cr;
						cd = 1;
					}
					else if (cr == -1)
					{
						dis += cp - cl;
						bia.upd(cl, -1);
						cp = cl;
						cd = 0;
					}
					else if (cl == cr)
						bia.upd(cl, -1);
					else if (cp - cl == cr - cp)
					{
						if (cd)	
						{
							dis += cr - cp;
							bia.upd(cr, -1);
							cp = cr;
						}
						else 
						{
							dis += cp - cl;
							bia.upd(cl, -1);
							cp = cl;
						}
					}
					else if (cp - cl < cr - cp)
					{
						dis += cp - cl;
						bia.upd(cl, -1);
						cp = cl;
						cd = 0;
					}
					else
					{
						dis += cr - cp;
						bia.upd(cr, -1);
						cp = cr;
						cd = 1;
					}
				}
			}
			else
			{
				scanf("%d", &x);
				bia.upd(x + 1, 1);
			}
		}
		printf("Case %d: %lld\n", Cas, dis);
	}
	return 0;
}
