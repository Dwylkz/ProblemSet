#include <cstdlib>
#include <cstdio>
#include <cstring>
const int N = 2e3+10;
const int M = 1e9+7;

int n, k;

int memo[N][N];
int f(int n, int k) {
	if (k == 0)
		return 1;

	if (memo[n][k] != -1)
		return memo[n][k];

	int sum = 0;
	for (int i = 1; i*i <= n; i++) {
		if (n%i != 0)
			continue;

		sum = (sum+f(i, k-1))%M;
		if (n/i != i)
			sum = (sum+f(n/i, k-1))%M;
	}

	memo[n][k] = sum;
	return sum;
}

int main()
{
  while(scanf("%d%d", &n, &k) != EOF) {
		memset(memo, -1, sizeof(memo));
		int res = 0;
		for (int i = 1; i <= n; i++)
			res = (res+f(i, k-1))%M;

		printf("%d\n", res);
  }
  return 0;
}
