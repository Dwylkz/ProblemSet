#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 3600+10;

struct e_t {
  int i, s, e;
  void input(int _i) {
    i = _i;
    int h, m;
    scanf("%2d:%2d", &h, &m);
    s = h*60+m;
    scanf("%2d:%2d", &h, &m);
    e = h*60+m;
  }
  friend bool operator < (const e_t &lhs, const e_t &rhs) {
    return lhs.e == rhs.e? lhs.s < rhs.s: lhs.e < rhs.e;
  }
} e[N];

struct ft_t {
  int s[N];
  void init() {
    memset(s, 0, sizeof(s));
  }
  void put(int x, int y) {
    for (x++; x < N; x += -x&x) s[x] += y; 
  }
  int ask(int x, int rv = 0) {
    for (x++; x; x -= -x&x) rv += s[x]; 
    return rv;
  }
};

int t, na, nb;
ft_t c[2];

int main() {
#if 1
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ks = 1; T--; ks++) {
    printf("Case #%d: ", ks);
    scanf("%d%d%d", &t, &na, &nb);
    for (int i = 0; i < na; i++) e[i].input(0);
    for (int i = na; i < na+nb; i++) e[i].input(1);
    int n = na+nb;
    sort(e, e+n);
    int rv[2] = {0};
    c[0].init(), c[1].init();
    for (int i = 0; i < n; i++) {
      int j = e[i].i, h = e[i].s, o = e[i].e+t;
#if 0
      printf("%d %d: %d\n", h, o, c[j].ask(h));
#endif
      if (c[j].ask(h) <= 0) {
        rv[j]++;
        c[j].put(h, 1);
      }
      c[j].put(h, -1);
      c[!j].put(o, 1);
    }
    printf("%d %d\n", rv[0], rv[1]);
  }
  return 0;
}
