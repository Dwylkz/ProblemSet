//coder: SXDwylkz
//heads
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
//namespaces
using namespace std;
//constants
const char input[] = "input.in",
	  output[] = "output.out";
const int inf32 = 0x7fffffff,
	  maxn = 5e4 + 10;
const long long inf64 = 0x7fffffffffffffffLL; 
//structure
struct Vec {
	double x, y;
	Vec(double _x = 0, double _y = 0) {
		x = _x;
		y = _y;
	}
	friend Vec operator - (Vec p, Vec q) {
		return Vec(p.x - q.x, p.y - q.y);
	} 
	double Mod() {
		return sqrt(x * x + y * y);
	}
} _Vec;
//type definition
typedef long long LL;
//global variable
Vec vec[maxn];
int n;
//access and mutator
double chk(double x) {
	Vec s(x, 0);
	double max = 0;
	for (int i = 0; i < n; i++) {
		max = fmax(max, (s - vec[i]).Mod());
	}
	return max;
}
//main
int main() {
#if 1
	freopen(input, "r", stdin);
	//freopen(output, "w", stdout);
#endif
	int T;
	while (~scanf("%d", &T)) {
		for (int Case = 1; Case <= T; Case++) {
			scanf("%d", &n);
			for (int i = 0; i < n; i++) {
				scanf("%lf%lf", &vec[i].x, &vec[i].y);
			}
			double l = -10010, r = 10010, res = inf32;
			while (l - r <= 1e-6) {
				double m = (l + r) / 2, a = chk(l), b = chk(r);
				if (a - b <= 1e-6) {
					res = a;
					break;
				} else if (a < b) {
					b = m - 1e-6;
				} else {
					a = m + 1e-6;
				}
			}
			printf("Case #%d: %.6lf\n", Case, res);
		}
	}
	return 0;
}
