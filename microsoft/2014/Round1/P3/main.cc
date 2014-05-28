#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
const int N = 1e5+10;
const double EPS = 1e-7;

struct Vertex {
	double x, y;
	Vertex(double _x = 0.0, double _y = 0.0): x(_x), y(_y) {}
	friend Vertex operator - (const Vertex& a, const Vertex& b) {
		return Vertex(a.x-b.x, a.y-b.y);
	}
	void Input() {scanf("%lf%lf", &x, &y);}
	double Mod() {return sqrt(x*x+y*y);}
};

Vertex vs[N];
int n;

double Look(double x) {
	double ret = 0.0;
	Vertex o(x, 0.0);
	for (int i = 0; i < n; i++)
		ret += (o-vs[i]).Mod();
	return ret;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
  for (int cas = 1; cas <= T; cas++) {
		scanf("%d", &n);
		double lb, rb;
		for (int i = 0; i < n; i++) {
			vs[i].Input();
			if (!i) lb = rb = vs[i].x;
			else {
				lb = min(lb, vs[i].x);
				rb = max(rb, vs[i].x);
			}
		}
		while (lb < rb-EPS) {
			double d = (rb-lb)/3.0;
			double lm = lb+d;
			double rm = rb-d;
			if (Look(lm) < Look(rm)) rb = rm;
			else lb = lm;
		}
		printf("Case %d: %.6f\n", cas, lb);
  }
  return 0;
}
