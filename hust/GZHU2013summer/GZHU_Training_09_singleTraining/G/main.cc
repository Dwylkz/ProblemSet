#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2;
const int mod = 20130719;


int f[N][N] = {
  0, 1,
  1, 1,
};
int i[N][N] = {
  1, 0,
  0, 1
};
int mat[N][N] = {
  0, 0,
  1, 0
};
int ans[N][N];
void mul(int z[N][N], int x[N][N], int y[N][N]) {
  int t[N][N] = {0};
  for (int n = 0; n < N; n++)
    for (int p = 0; p < N; p++)
      for (int m = 0; m < N; m++)
        t[n][p] += 1LL*x[n][m]*y[m][p]%mod;
  memcpy(z, t, sizeof(t));
}
int qmod(int b) {
  int c[N][N], a[N][N];
  memcpy(c, i, sizeof(i));
  memcpy(a, f, sizeof(f));
  for ( ; b; b >>= 1) {
    if (b&1) mul(c, c, a);
    mul(a, a, a);
  }
  mul(ans, c, mat);
  return ans[1][0];
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int n; ~scanf("%d", &n); ) {
    if (n < 2) printf("%d\n", mat[n][0]);
    else printf("%d\n", qmod(n-1));
  }
  return 0;
}
