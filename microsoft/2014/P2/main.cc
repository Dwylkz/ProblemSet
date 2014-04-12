#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int M = 1e9+7;

int n;

int main() {
#if 1
	freopen("input.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		printf("Case %d:", cas);
		scanf("%d", &n);
		int ret = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= n; k++) {
					if (i == j && j != k ||
							i == k && k != j ||
							j == k && k != i) continue;
					ret = (ret+i*j*k)%M;
				}
		printf(" %d\n", ret);
	}
	return 0;
}
