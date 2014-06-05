//Head
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
//Dwylkz
namespace Dwylkz{
	//Type
	typedef unsigned int UI;
	typedef long long LL;
	typedef long double LD;
	//Constant
	const double EPS = 1e-8;
	const LL INFLL = ~0uLL >> 1;
	const int INFI = ~0u >> 1;
	const int MAXN = 505;
	const int MOD = 1e9 + 7;
	//Array
	typedef int AI[MAXN];
	typedef bool AB[MAXN];
	typedef double AD[MAXN];
	typedef LL ALL[MAXN];
	typedef LD ALD[MAXN];
	typedef vector<int> VI;
}
using namespace Dwylkz;
//Macro
#define MS(c, a) memset(c, a, sizeof c)
#define Rep(c, a, b) for (int c = a; c < int(b); c++)
#define Nre(c, a, b) for (int c = a; c > int(b); c--)
#define FK puts("Here")
//Global
struct Vec{
	double x, y;
	Vec(double _x = 0, double _y = 0){
		x = _x, y = _y;
	}
} _Vec;
struct Seg{
	Vec a, b;
	double A, B, C;
	Seg(Vec _a = _Vec, Vec _b = _Vec){
		a = _a, b = _b;
		double dx = a.x - b.x, dy = a.y - b.y;
		A = -dy, B = dx, C = dy * a.x - dx * a.y;
	}
	friend bool operator | (Seg &p, Seg &q){
		return fabs(p.A * q.B - p.B * q.A) < EPS;
	}
	friend Vec operator & (Seg &p, Seg &q){
		double x = p.B * q.C - p.C * q.B,
			   y = p.A * q.C - p.C * q.A,
			   d = p.A * q.B - p.B * q.A;
		return Vec(x / d, y / -d);
	}
	bool inc(Vec &o){
		double lx = min(a.x, b.x), rx = max(a.x, b.x),
			   ly = min(a.y, b.y), ry = max(a.y, b.y);
		return  lx + EPS <= o.x && o.x + EPS <= rx &&
				ly + EPS <= o.y && o.y + EPS <= ry;
	}
} _Seg;
struct Cir{
	Vec o;
	double r;
	Cir(Vec _o = _Vec, double _r = 0){
		o = _o, r = _r;
	}
} _Cir;
//Main
int main(){
#if 0
	freopen("test.txt", "r", stdin);
	//freopen("test.out", "w", stdout);
#endif
	double y1, y2, yw, xb, yb, r;
	while (~scanf("%lf%lf%lf%lf%lf%lf", &y1, &y2, &yw, &xb, &yb, r)){
		Vec glu(0, y1), gll(0, y2), b(xb, yb);
		Seg w(Vec(0, yw - r), Vec(1, yw - r));
		Cir c1(y1, r), c2(y2, r), c(b, r);
	}
	return 0;
}
