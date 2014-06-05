#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e2+10;

int n, x, y, c[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    c[0] = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", c+i);
      c[i] += c[i-1];
    }
    scanf("%d%d", &x, &y);
    int result = 0;
    for (int i = 1; i <= n; i++)
      if (x <= c[i-1] && c[i-1] <= y
          && x <= c[n]-c[i-1] && c[n]-c[i-1] <= y) {
        result = i;
        break;
      }
    printf("%d\n", result);
  }
  return 0;
}
