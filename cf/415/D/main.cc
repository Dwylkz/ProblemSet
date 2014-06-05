#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
const int N = 2e3+10;
const int MOD = 1e9+7;

int n, k, f[N][N];

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &k); ) {
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; i++) f[1][i] = 1;
		int c = 0;
		for (int i = 2; i <= k; i++)
			for (int j = 1; j <= n; j++) {
				for (int x = 1; x*x <= j; x++)
					if (j%x == 0) {
						f[i][j] = f[i][j]+f[i-1][x];
						if (f[i][j] > MOD) f[i][j] -= MOD;
						if (j/x != x) {
							f[i][j] = f[i][j]+f[i-1][j/x];
							if (f[i][j] > MOD) f[i][j] -= MOD;
						}
					}
			}
		int ret = 0;
		for (int i = 1; i <= n; i++) {
			ret = ret+f[k][i];
			if (ret > MOD) ret -= MOD;
		}
		printf("%d\n", ret);
  }
  return 0;
}
