//coder: SXDwylkz
//heads
#include <cmath>
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
//namespaces
using namespace std;
//constants
const char input[] = "input.in",
	  output[] = "output.out";
const int inf32 = 0x7fffffff,
	  maxn = 1e5 + 10;
const long long inf64 = 0x7fffffffffffffffLL; 
//structure
//type definition
typedef long long LL;
//global variable
LL N, M, K;
//access and mutator
LL Calc(LL n, LL m) {
	return ((n - 1) * n / 2) * ((m - 1) * m / 2);
}
LL IE(LL n, LL m, LL k) {
	LL r = k / m, c = k % m;
	n = r + bool(c);
	m = r? m: c;
	return Calc(n, c) + Calc(r, m) - Calc(r, c);
}
LL Enum(LL n, LL m, LL k) {
	LL res = 0;
	for (int i = 1; i <= m; i++) {
		if (k / i + bool(k % i) <= n) {
			res = max(res, IE(n, i, k));
		}
	}
	return res;
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
			scanf("%lld%lld%lld", &N, &M, &K);
			printf("Case #%d: %lld\n", Case, max(Enum(N, M, K), Enum(M, N, K)));
		}
	}
	return 0;
}
