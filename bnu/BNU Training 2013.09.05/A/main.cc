#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5;
const int M = 3*N+10;

int f[M];

int dfs(int n) {
  if (n == 1) return f[1] = 1;
  if (n < M && f[n]) return f[n];
  int rv;
  if (n&1) rv = dfs(3*n+1);
  else rv = dfs(n>>1);
  rv = max(rv, n);
  if (n < M) f[n] = rv;
  return rv;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int i = 1; i <= N; i++)
    if (!f[i]) dfs(i);
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    int i, n;
    scanf("%d%d", &i, &n);
    printf("%d %d\n", i, f[n]);
  }
  return 0;
}
