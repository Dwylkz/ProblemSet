#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
typedef long long LL;
struct BIA {
	enum {sz = maxn};
	int n;
	LL t[sz];
	void Init(int _n = 0) {
		n = _n;
		memset(t, 0, sizeof(t));
	}
	int Low(int x) {
		return -x & x;
	}
	void Insert(LL k, int x) {
		for ( ; x <= n; x += Low(x)) {
			t[x] += k;
		}
	}
	LL Ask(int x, LL res = 0) {
		for ( ; x; x -= Low(x)) {
			res += t[x];
		}
		return res;
	}
};
struct OP {
	int l, r, d;
};
OP op[maxn];
BIA s, o;
int n, m, k;
int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d%d%d", &n, &m, &k)) {
		s.Init(n);
		for (int i = 1; i <= n; i++) {
			int si;
			scanf("%d", &si);
			s.Insert(si, i);
			s.Insert(-si, i + 1);
		}
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &op[i].l, &op[i].r, &op[i].d);
		}
		o.Init(m);
		for (int i = 0; i < k; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			o.Insert(1, x);
			o.Insert(-1, y + 1);
		}
		for (int i = 1; i <= m; i++) {
			LL times = o.Ask(i);
			s.Insert(op[i].d * times, op[i].l);
			s.Insert(-op[i].d * times, op[i].r + 1);
		}
		for (int i = 1; i <= n; i++) {
			if (1 < i) {
				putchar(' ');
			}
			printf("%lld", s.Ask(i));
		}
		puts("");
	}
	return 0;
}
