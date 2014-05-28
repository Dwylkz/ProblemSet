#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 25+10;

struct p_t {
  int t, i;
  p_t &input(int _i = 0) {
    i = _i;
    scanf("%d", &t);
    return *this;
  }
  friend bool operator < (p_t lhs, p_t rhs) {
    if (lhs.t != rhs.t) return lhs.t < rhs.t;
    return lhs.i < rhs.i;
  }
} a[N];

int s[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int n; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) {
      a[i] = p_t().input(i);
    }
    sort(a, a+n);
    for (int i = 0; i < n; i++)
      if (i) s[i] = s[i-1]+a[i].t;
      else s[i] = a[i].t;
    int res = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] <= 300) {
        res += s[i];
        cnt++;
      }
    }
    printf("%d %d\n", cnt, res);
    for (int i = 0; i < n; i++)
      if (s[i] <= 300) printf("%d\n", a[i].i+1);
  }
  return 0;
}
