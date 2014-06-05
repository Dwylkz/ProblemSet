#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3+10;

int n, s[N][N], t[N][N], f[3][N][N], p[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        scanf("%d", s[i]+j);
    memcpy(f[0], s, sizeof(s));
    for (int k = 0; k < 2; k++) {
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          f[k+1][j][i] += p[i]*s[i][j];
    }
  }
  return 0;
}
