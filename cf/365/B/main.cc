#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;

int n, a[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    int result = n > 1? 2: 1;
    for (int i = 1; i < n; i++) {
      int t = 2;
      for (i++; i < n && a[i] == a[i-1]+a[i-2]; i++) t++;
      i--;
      result = max(result, t);
    }
    printf("%d\n", result);
  }
  return 0;
}
