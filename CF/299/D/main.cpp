#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1010,
	  maxm = 22,
	  maxk = 11,
	  maxs = 1024,
	  maxq = 362880,
	  mod = 1e9 + 7;
typedef long long LL;
int n, m, k, g[maxn][maxn], fac[maxk], dp[maxm][maxm][maxq];
void Init() {
	fac[0] = 1;
	for (int i = 1; i < maxk; i++) {
		fac[i] = fac[i - 1] * i;
	}
}
void Decode(int l, int x, int *t) {
	int id = 0, h[maxk];
	memset(h, 0, sizeof(h));
	for (int i = l - 1; 0 <= i; i--) {
		int rm = (x - 1) / fac[i], rank = 0;
		for (int j = 1; j <= l; j++) {
			rank += !h[j];
			if (rank == rm + 1) {
				t[id++] = j;
				h[j] = 1;
				break;
			}
		}
		x %= fac[i];
	}
}
int Encode(int l, int *t) {
	int res = 0;
	for (int i = 0; i < l; i++) {
		int cnt = 0;
		for (int j = i + 1; j < l; j++) {
			if (t[j] < t[i]) {
				cnt++;
			}
		}
		res += cnt * fac[l - i - 1];
	}
	return res;
}
int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
	Init();
#if 1
	for (int i = 0; i < maxk; i++) {
		printf(" %d", fac[i]);
	}
	puts("");
	int tp[] = {1, 4, 3, 5}, ec = Encode(4, tp);
	printf("%d\n", ec);
	Decode(4, ec, tp);
	for (int i = 0; i < 4; i++) {
		printf(" %d", tp[i]);
	}	
	puts("");
#endif
	while (~scanf("%d%d%d", &n, &m, &k)) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", g[i] + j);
				g[i][j];
			}
		}
		if (k < n + m - 2) {
			puts("0");
			continue;
		}
		/*memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int l = i + j + 1;
				for (int s = 0; s < fac[i + j + 1]; s++) {
					if (!dp[i][j][s]) {
						continue;
					}
					int t[maxk], ha[maxk], h = 1, o = k;
					for (int p = 0; p < l; p++) {
						ha[t[p]] = 1;
					}
					if (g[i][j]) {
						h = o = g[i][j];
					}
					Decode(l, i, t);
					for (int p = h; p <= o; p++) {
						if (ha[p]) {
							continue;
						}
						t[l] = p; 
						dp[i][j][Encode(l + 1, t)] = 1;
					}
				}
			}
		}*/
		int res = 0;
		for (int i = 0; i < maxq; i++) {
			res += dp[n - 1][m - 1][i];
		}
		printf("%d\n", res);
	}
	return 0;
}
