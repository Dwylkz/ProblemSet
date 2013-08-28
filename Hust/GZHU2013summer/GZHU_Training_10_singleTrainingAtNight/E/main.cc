#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
const int N = 30+10;

int n, q, m[N][N];

void mul(int t[][N], int x[][N], int y[][N]) {
  int z[N][N] = {0};
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        z[i][j] |= x[i][k]&y[k][j];
  memcpy(t, z, sizeof(z));
}
int ans[N][N];
void qmod(int b) {
  int o[N][N];
  memcpy(o, m, sizeof(m));
  memset(ans, 0, sizeof(ans));
  for (int i = 0; i < n; i++) ans[i][i] = 1;
  for ( ; b; b >>= 1) {
    if (b&1) mul(ans, ans, o);
    mul(o, o, o);
  }
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &q); ) {
    memset(m, 0, sizeof(m));
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < 4; i++) {
        char b[10];
        scanf("%*2s%s", b);
        if (isdigit(b[0])) {
          int t = 0;
          for (int j = 0; j < strlen(b); j++)
            t = t*10+b[j]-'0';
          b[0] = t-1;
        } else b[0] = b[0]-'A'+n;
        m[k][b[0]] = 1;
      }
    }
    n += 5;
    for ( ; q--; ) {
      int t;
      scanf("%d", &t);
      qmod(t);
      int s = 0;
      for (int i = n-5; i < n; i++) s += ans[0][i];
      if (s) {
        int b = 0;
        for (int i = n-5; i < n; i++) if (ans[0][i]) {
          if (b) putchar(' ');
          b = 1;
          putchar('A'+i-(n-5));
        }
        puts("");
      } else puts("TT loves to lie");
    }
  }
  return 0;
}
