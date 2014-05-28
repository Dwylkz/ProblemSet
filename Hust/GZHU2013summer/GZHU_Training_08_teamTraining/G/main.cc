#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e4+10;

struct atk_t {
  int t, d;
  void input() {
    scanf("%d%d", &t, &d);
  }
  friend bool operator < (atk_t lhs, atk_t rhs) {
    return lhs.t < rhs.t;
  }
} atk[N];

int m, n;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &m, &n); ) {
    for (int i = 0; i < n; i++) {
      atk[i].input();
    }
    sort(atk, atk+n);
    int mx = m, cd = -11, sl = mx/10, dead = 0;
    for (int i = 0; i < n; i++) {
      if (atk[i].t-cd >= 10) sl = mx/10;
      cd = atk[i].t;
      int d;
      if (sl >= atk[i].d) {
        sl -= atk[i].d;
      } else {
        atk[i].d -= sl;
        sl = 0;
        m -= atk[i].d;
      } 
      if (m <= 0) {
        dead = 1;
        break;
      }
    }
    if (dead) puts("I'm dead!");
    else printf("%d\n", m);
  }
  return 0;
}
