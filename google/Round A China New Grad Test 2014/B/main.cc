#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long LL;

struct r_t {
  LL a, b;
  r_t(LL _a = 0, LL _b = 0) {
    a = _a;
    b = _b;
    LL c = gcd(a, b);
    a /= c;
    b /= c;
  }
  LL gcd(LL a, LL b) {
    return b? gcd(b, a%b): a;
  }
  friend r_t operator + (const r_t &lhs, const r_t &rhs) {
    return r_t(lhs.a+rhs.a, lhs.b+rhs.b);
  }
  friend bool operator < (const r_t &lhs, const r_t &rhs) {
    return lhs.a/lhs.b < rhs.a/rhs.b;
  }
  friend bool operator == (const r_t &lhs, const r_t &rhs) {
    return lhs.a == rhs.a && lhs.b == rhs.b;
  }
};

LL f(LL n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (~n&1) return f(n>>1);
  n >>= 1;
  return f(n)+f(n+1);
}

vector<LL> g;
void init() {
  int M = 1<<16;
  for (int i = 0; i < M; i++)
    g.push_back(f(i));
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
//   freopen("output.out", "w", stdout);
#endif
  init();
  int T;
  scanf("%d", &T);
  for (int kas = 1; T--; ) {
    LL id, x, y;
    cin >> id >> x;
    if (id < 2) {
      cout << "Case #" << kas++ << ": " << g[x] << " " << g[x+1] << endl;
    } else {
      cin >> y;
      LL rv = 0;
      for ( ; ; rv++)
        if (g[rv] == x && g[rv+1] == y) {
          break;
        }
      cout << "Case #" << kas++ << ": " << rv << endl;
    }
  }
  return 0;
}
