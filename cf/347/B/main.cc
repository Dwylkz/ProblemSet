#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int N = 1e5+10;

int n, s[N], h[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) scanf("%d", s+i);
    int yes = 0;
    for (int i = 0; i < n; i++)
      if (s[i] != i && s[s[i]] == i) {
        swap(s[s[i]], s[i]);
        yes = 1;
        break;
      }
    if (!yes) {
      for (int i = 0; i < n; i++)
        if (s[i] != i) {
          swap(s[s[i]], s[i]);
          break;
        }
    }
    int rv = 0;
    for (int i = 0; i < n; i++) rv += s[i] == i;
    printf("%d\n", rv);
  }
  return 0;
}
