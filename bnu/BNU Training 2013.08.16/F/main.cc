#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2e3+10;
typedef long long LL;

int x, n;

int b[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int k = 1; k <= T; k++) {
    scanf("%d%d", &x, &n);
    memset(b, 0, sizeof(b));
    LL sum = 0;
    for (int i = 0; i < n; i++) {
      int c;
      scanf("%d", &c);
      if (x-c >= 0) sum += b[x-c];
      b[c]++;
    }
    printf("%d. %lld\n", k, sum);
  }
  return 0;
}
