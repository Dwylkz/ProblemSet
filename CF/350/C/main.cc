#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int N = 1e6+10;
const int M = 100;
#define _i(t) t::iterator

struct bomb_t {
  int x, y;
  bomb_t input() {
    scanf("%d%d", &x, &y);
    return *this;
  }
  void to(const bomb_t &t) const {
    if (x != t.x) printf("1 %d %c\n", abs(x-t.x), x < t.x? 'R': 'L');
    if (y != t.y) printf("1 %d %c\n", abs(y-t.y), y < t.y? 'U': 'D');
  }
  int mod() const {
    return abs(x)+abs(y);
  }
  friend bool operator < (const bomb_t &lhs, const bomb_t &rhs) {
    if (lhs.mod() != rhs.mod()) return lhs.mod() < rhs.mod();
    if (lhs.x != rhs.x) return lhs.x < rhs.x;
    return lhs.y < rhs.y;
  }
};
typedef map<bomb_t, bool> mbb_t;

int n;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    int rv = 0;
    mbb_t m;
    for (int i = 0; i < n; i++) {
      bomb_t t;
      t.input();
      m[t] = 1;
      rv += 1+(t.x != 0)+(t.y != 0)<<1;
    }
    printf("%d\n", rv);
    bomb_t o = {0, 0};
    for (_i(mbb_t) i = m.begin(); i != m.end(); i++) {
      o.to(i->first);
      puts("2");
      i->first.to(o);
      puts("3");
    }
  }
  return 0;
}
