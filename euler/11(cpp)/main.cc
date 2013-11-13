#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 20+10;

int m[N][N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int n = 20, result = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", m[i]+j);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      int d = 1, r = 1, rd = 1, ld = 1;
      for (int k = 0; k < 4; k++) {
        if (i+k < n) d *= m[i+k][j];
        if (j+k < n) r *= m[i][j+k];
        if (i+k < n && j+k < n)  rd *= m[i+k][j+k];
        if (i+k < n && j-k >= 0) ld *= m[i+k][j-k];
      }
      result = max(result, max(d, max(r, max(rd, ld))));
    }
  printf("%d\n", result);
  return 0;
}
