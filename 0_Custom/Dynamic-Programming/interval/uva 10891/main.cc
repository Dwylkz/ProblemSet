#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e2+10;

int n, f[N][N][2][2], g[N][N][2][2], v[N];

int dfs(int l, int r, int oe, int ab) {
  if (l == r)  {
    g[l][r][oe][ab] = 1;
    return f[l][r][oe][ab] = (oe == ab)*v[l];
  }
  if (g[l][r][oe][ab]) return f[l][r][oe][ab];
  int mx = 0;
  if (oe == ab) {
    for (int i = r-l+1, ls = 0, rs = 0; i >= 0; i--) {
      mx = max(mx, ls+dfs(l+i-1, r, oe^1, ab));
      mx = max(mx, dfs(l, r-i+1, oe^1, ab)+rs);
      ls += v[l+i];
      rs += v[r-i];
    }
  } else {
    for (int i = r-l+1; i >= 0; i--) {
      mx = max(mx, dfs(l+i-1, r, oe^1, ab));
      mx = max(mx, dfs(l, r-i+1, oe^1, ab));
    }
  }
  g[l][r][oe][ab] = 1;
  return f[l][r][oe][ab] = mx;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n), n; ) {
    for (int i = 0; i < n; i++) scanf("%d", v+i);
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    dfs(0, n-1, 0, 0);
    printf("%d", f[0][n-1][0][0]-f[0][n-1][0][1]);
  }
  return 0;
}
