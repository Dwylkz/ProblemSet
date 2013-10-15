#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3+10;

int c[4], n, m, a[N], b[N];

int sum(int *s, int l) {
  int result = 0;
  for (int i = 0; i < l; i++)
    result += min(s[i]*c[0], c[1]);
  return min(result, c[2]);
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d%d", c, c+1, c+2, c+3); ) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    for (int i = 0; i < m; i++) scanf("%d", b+i);
    printf("%d\n", min(sum(a, n)+sum(b, m), c[3]));
  }
  return 0;
}
