#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 6e1 + 10;
const double eps = 1e-8;
typedef long long LL;

int n, t;
LL f[maxn][maxn][maxn];
LL dfs(int n, int t, int k) 
{
  if (f[n][t][k] != -1) return f[n][t][k];
  if (!t) return f[n][t][k] = 1;
  LL tp = 0;
  for (int i = 0; i <= k; i++)
    if (n-i >= t-1) {
      tp += dfs(n-i, t-1, i);
    }
  return f[n][t][k] = tp;
}

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
	for ( ; ~scanf("%d%d", &n, &t); ) {
    memset(f, -1, sizeof(f));
    dfs(n, t, n);
    printf("%lld\n", f[n][t][n]);
	}
	return 0;
}
