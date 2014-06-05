#include <map>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int N = 1<<17;

int s[N<<1];
void put(int x, int y) {
  for (s[++x] = y, x += -x&x; x < N; x += -x&x)
    s[x] = max(s[x], y);
}
int ask(int x, int rv = 0) {
  for (x++; x; x -= -x&x) rv = max(rv, s[x]);
  return rv;
}

int x, y, f[N];

int main() {
#if 1
	freopen("input.txt", "r", stdin);
#endif
  for (int n; ~scanf("%d", &n); ) {
    int res = 0;
    for (int a, i = 0; i < n; i++) {
      scanf("%d", &a);
      int t = ask(a)+1;
      res = max(res, t);
      put(a, t);
    }
    printf("%d\n", res);
  }
	return 0;
}
