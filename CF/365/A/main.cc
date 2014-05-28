#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int n, k;

bool look(int n) {
  int b[10] = {0};
  for ( ; n > 9; n /= 10)
    b[n%10] = 1;
  b[n%10] = 1;
  for (int i = 0; i <= k; i++)
    if (!b[i]) return 0;
  return 1;
}


int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &k); ) {
    int result = 0;
    for (int i = 0; i < n; i++) {
      int ai;
      scanf("%d", &ai);
      result += look(ai);
    }
    printf("%d\n", result);
  }
  return 0;
}
