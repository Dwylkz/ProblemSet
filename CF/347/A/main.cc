#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e2+10;

int n, s[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) scanf("%d", s+i);
    sort(s, s+n, greater<int>());
    reverse(s+1, s+n-1);
    for (int i = 0; i < n; i++)
      printf("%d%c", s[i], i < n-1? ' ': '\n');
  }
  return 0;
}
