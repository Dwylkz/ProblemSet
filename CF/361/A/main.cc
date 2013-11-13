#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e2+10;

int n, k, s[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &k); ) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        printf("%d%c", i == j? k: 0, j < n-1? ' ': '\n');
  }
  return 0;
}
