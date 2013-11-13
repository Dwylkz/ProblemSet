#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;

int n, k, s[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &k); ) {
    k = n-k;
    if (!k) {
      puts("-1");
      continue;
    }
    for (int i = 0; i < n; i++) s[i] = i+1;
    for (int i = k-1; i; i--) s[i] = s[i-1];
    s[0] = k;
    for (int i = 0; i < n; i++)
      printf("%d%c", s[i], i < n-1? ' ' : '\n');
  }
  return 0;
}
