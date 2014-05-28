#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3+10;
typedef long long ll_t;

struct ft_t {
  ll_t d[N], t[N];
  void put(ll_t x, ll_t k) {
    for (int i = x+1; i < N; i += -i&i) d[i] ^= k, t[i] ^= (x&1)*k;
  }
  ll_t ask(ll_t x, ll_t lr = 0, ll_t rr = 0) {
    for (int i = x+1; i; i -= -i&i) lr ^= d[i], rr ^= t[i];
    return (x+1&1)*lr^rr;
  }
};
struct ft2_t {
  ft_t d[N], t[N];
  void init() {
    memset(this, 0, sizeof(this));
  }
  void put(ll_t x, ll_t y, ll_t k) {
    for (int i = x+1; i < N; i += -i&i)d[i].put(y, k), t[i].put(y, (x&1)*k);
  }
  ll_t ask(ll_t x, ll_t y, ll_t lr = 0, ll_t rr = 0) {
    for (int i = x+1; i; i -= -i&i) lr ^= d[i].ask(y), rr ^= t[i].ask(y);
    return (x+1&1)*lr^rr;
  }
  void draw(ll_t x0, ll_t y0, ll_t x1, ll_t y1, ll_t k) {
    put(x0, y0, k), put(x1+1, y0, k), put(x0, y1+1, k), put(x1+1, y1+1, k);
  }
  ll_t pick(ll_t x0, ll_t y0, ll_t x1, ll_t y1) {
    return ask(x1, y1)^ask(x0-1, y1)^ask(x1, y0-1)^ask(x0-1, y0-1);
  }
};

int n, m;
ft2_t zkl;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    zkl.init();
    for (int op, x0, y0, x1, y1; m--; ) {
      scanf("%d%d%d%d%d", &op, &x0, &y0, &x1, &y1);
      if (op == 1) printf("%lld\n", zkl.pick(x0, y0, x1, y1));
      else {
        ll_t k;
        scanf("%lld", &k);
        zkl.draw(x0, y0, x1, y1, k);
      }
    }
  }
  return 0;
}
