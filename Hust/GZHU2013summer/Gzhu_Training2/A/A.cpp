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
#define PI (acos(-1.0))
#define MAXN ()

struct Vec
{
	long double x, y;
	Vec(long double _x = 0, long double _y = 0): x(_x), y(_y) {};
	friend Vec operator - (Vec p, Vec q)
	{
		return Vec(p.x - q.x, p.y - q.y);
	}
	long double mod()
	{
		return sqrt(x * x + y * y);
	}
	friend long double operator * (Vec p, Vec q) 
	{
		return p.x * q.x + p.y * q.y;
	}
	Vec inp()
	{
		scanf("%Lf%Lf", &x, &y);
		return *this;
	}
} _Vec;

int main()
{
#if 1
	freopen("test.txt", "rt", stdin);
#endif
	int T, Cas = 1;

	scanf("%d", &T);
	while (T--)
	{
		Vec o, a, b;
		o.inp();
		a.inp();
		b.inp();
		a = a - o;
		b = b - o;
		long double r = a.mod(), lre, rre,
			   ang = (a.mod() && b.mod())? acos(a * b / (a.mod() * b.mod())): 0;
		lre = r * ang;
		rre = r * 2 * PI - lre; 
		printf("Case %d: %Lf\n", Cas++, min(lre, rre));
	}

	return 0;
}
