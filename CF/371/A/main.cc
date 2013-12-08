#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e2+10;

int n, k, h[N][2];

int main() {
#if 0
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &k); ) {
    memset(h, 0, sizeof(h));
    for (int i = 0; i < n; i++) {
      int ai;
      scanf("%d", &ai);
      h[i%k][ai-1]++;
    }
    int res = 0;
    for (int i = 0; i < k; i++)
      res += n/k-max(h[i][0], h[i][1]);
    printf("%d\n", res);
  }
  return 0;
}
