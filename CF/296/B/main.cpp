#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 10,
	  mod = 1e9 + 7;
//Module_Group
//usage: MG<long long prim_>
template<long long m> struct MG {
	typedef long long LL;
	LL x;
	//constructor
	//usage: MG(long long vaule)
	MG(LL _x = 0): x(_x % m) {
	}
	friend MG operator + (MG p, MG q) {
		return (p.x + q.x) % m;
	}
	friend MG operator - (MG p, MG q) {
		return MG((p.x - q.x + m) % m);
	}
	friend MG operator * (MG p, MG q) {
		return MG((p.x * q.x) % m);
	}
	friend MG operator / (MG p, MG q) {
		MG a(1);
		LL b = m - 2;
		for (; b; b >>= 1) {
			if (b & 1) {
				a = a * q;
			}
			q = q * q;
		}
		return p * a;
	}
};
typedef MG<mod> Int;
enum dpTag{eq, ic, gt, lt};
int n;
Int dp[maxn][4];
char a[maxn], b[maxn];
int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	while (~scanf("%d%s%s", &n, a + 1, b + 1)) {
		dp[0][eq] = 1;
		for (int i = 1; i < 4; i++) {
			dp[0][i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			int g, l, e;
			if (a[i] == '?' && b[i] == '?') {
				g = l = 45;
				e = 10;
			} else if (a[i] != '?' && b[i] != '?') {
				g = a[i] > b[i];
				l = a[i] < b[i];
				e = a[i] == b[i];
			} else {
				if (a[i] == '?') {
					g = '9' - b[i];
					l = b[i] - '0';
				} else {
					g = a[i] - '0';
					l = '9' - a[i];
				}
				e = 1;
			}
			dp[i][eq] = dp[i - 1][eq] * e;
			dp[i][ic] = dp[i - 1][gt] * l + dp[i - 1][lt] * g
				+ dp[i - 1][ic] * (g + l + e);
			dp[i][gt] = dp[i - 1][gt] * (g + e) + dp[i - 1][eq] * g;
			dp[i][lt] = dp[i - 1][lt] * (l + e) + dp[i - 1][eq] * l;
		}
#if 0
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < 4; j++) {
				printf("%10lld", dp[i][j]);
			}
			puts("");
		}
		printf("total = %lld\n", dp[n][eq] + dp[n][ic] + dp[n][gt] + dp[n][lt]);
#endif
		printf("%lld\n", dp[n][ic]);
	}
	return 0;
}
