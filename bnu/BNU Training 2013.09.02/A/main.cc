#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e2+10;

struct p_t{
  int o, c, i;
  void input(int _i) {
    i = _i;
    scanf("%d", &c);
    o = c;
  }
  friend bool operator < (p_t lhs, p_t rhs) {
    if (lhs.o != rhs.o) return lhs.o < rhs.o;
    return lhs.i > rhs.i;
  }
} a[N];
int n, p, ans[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    int sum = 0;
    scanf("%d%d", &p, &n);
    for (int i = 0; i < n; i++) {
      a[i].input(i);
      sum += a[i].o;
    }
    if (p > sum) {
      puts("IMPOSSIBLE");
      continue;
    }
    sort(a, a+n);
    for (int j = 0; j < n && p/(n-j); ) {
      int av = p/(n-j);
      for (int i = j; i < n; i++) {
        int d = min(a[i].c, av);
        a[i].c -= d;
        p -= d;
        if (!a[i].c) j++;
      }
    }
    for (int i = n-1; p && i >= 0; i--) {
      a[i].c--;
      p--;
    }
    for (int i = 0; i < n; i++) {
#if 0
      printf("%d = %d, %d\n", a[i].i, a[i].o, a[i].c);
#endif
      ans[a[i].i] = a[i].o-a[i].c;
    }
    for (int i = 0; i < n; i++)
      printf("%d%c", ans[i], i < n-1? ' ': '\n');
  }
  return 0;
}
