//Kimady::S.X.Dwylkz
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
//Namespace
namespace dtd{
	//Constant
	const long long INFLL = ~0uLL>>1;
	const int INFI = ~0u>>1;
	const int MAXN = 100;
	const int MAXM = 100;
	const int MOD = 1e+7;
	//Type Definition
	typedef unsigned int UI;
	typedef long long LL;
	typedef long double LD;
	typedef int AI[MAXN];
	typedef bool AB[MAXN];
	typedef double AD[MAXN];
	typedef LL ALL[MAXN];
	typedef LD ALD[MAXN];
	typedef AI AI2[MAXM];
	typedef AB AB2[MAXM];
	typedef AD AD2[MAXM];
	typedef ALL ALL2[MAXM];
	typedef ALD ALD2[MAXM];
}
using namespace std;
using namespace dtd;
//Macro
#define Bug puts("Here")
//Global
struct Vec {
	double x, y;
	Vec(double _x = 0, double _y = 0) {
		x = _x;
		y = _y;
	}
	friend Vec operator - (Vec p, Vec q) {
		return Vec(p.x - q.x, p.y - q.y);
	}
	double mod() {
		return sqrt(x * x + y * y);
	}
} _Vec;
int n, b[9];
Vec s[9], h;
double v;
//Main
int main()
{
#if 0
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	int Case = 1;
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; i++) {
			b[i] = i;
			scanf("%lf%lf", &s[i].x, &s[i].y);
		}
		b[0] = 0;
		scanf("%lf%lf%lf", &s[0].x, &s[0].y, &v);
		double res = INFI;
		int cnt = 0;
		do {
			cnt++;
			double tmd = 0;
			for (int i = 1; i <= n; i++) {
				tmd += (s[b[i]] - s[b[i - 1]]).mod();
			}
			tmd += (s[b[0]] - s[b[n]]).mod();
			tmd = tmd * 3600/ v + n * 3600;
			res = fmin(res, tmd);
		} while (next_permutation(b + 1, b + n + 1));
#if 0
		printf("cnt = %d\n", cnt);
#endif
		int h = res / 3600.0,
			m = (res - h * 3600.0) / 60.0,
			s = ceil(res - h * 3600.0 - m * 60.0);
		printf("Case %d: %d hour(s) %d minute(s) %d second(s)\n", 
				Case++, h, m, s);
	}
	return 0;
}
