#include <cstdlib>
#include <vector>
#include <map>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
using namespace std;
const int maxn = 1e6+10;
const int mod = 1e9 + 7;
typedef long long LL;
#define Rep(c, a, b) for (int c = a; c < (b); c++)
LL a, b, n, fac[maxn];
LL qmod(LL a, LL b) {
	LL t = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			t = t * a % mod;
		}
		a = a * a % mod;
	}
	return t;
}
bool test(LL n) {
	for ( ; n; n /= 10) {
		LL t = n % 10;
		if (t != a && t != b) {
			return 0;
		}
	}
	return 1;
}
int main()
{
#if 1
	freopen("input.txt", "rt", stdin);
#endif
	fac[0] = 1;
	for (int i = 1; i < maxn; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	while (~scanf("%lld%lld%lld", &a, &b, &n)) {
		LL res = 0;
		for (int i = 0; i <= n; i++) {
			if (test(i * a + (n - i) * b)) {
				LL d = fac[i] * fac[n - i] % mod;
				res += fac[n] * qmod(d, mod - 2) % mod;
				res %= mod;
			}
		}
		printf("%lld\n", res);
	} 
	return 0;
}
