#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const double EPS = 1e-6;

int main() {
#if 0
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
  for (int cas = 1; cas <= T; cas++) {
		printf("Case #%d:", cas);
		double c, f, x, r = 2.0;
		scanf("%lf%lf%lf", &c, &f, &x);
		double cur = 0.0, ret = 0.0;
		while (cur < x) {
			double nxt1 = ret+(x-cur)/r;
			double nxt2 = ret+c/r+(x-cur)/(r+f);
			if (nxt1 < nxt2) {
				ret += (x-cur)/r;
				cur = x;
			} else {
				ret += c/r;
				r += f;
			}
		}
		printf(" %.7f\n", ret);
  }
  return 0;
}
