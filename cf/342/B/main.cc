#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
typedef pair<int, int> pii_t;
#define _l first
#define _r second
typedef map<int, pii_t> mib_t;
const int N = 1e5+10;

int n, m, s, f;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d%d", &n, &m, &s, &f); ) {
    mib_t x;
    for (int i = 0, t, l, r; i < m; i++) {
      scanf("%d%d%d", &t, &l, &r);
      x[t] = pii_t(l, r);
    }
    string rv = "";
    int d = s < f? 1: -1, c = s < f? 'R': 'L';
    for (int t = 1; s != f; t++) {
      int to = s+d;
      if (x.find(t) != x.end()) {
        if (x[t]._l <= s+d && s+d <= x[t]._r
            || x[t]._l <= s && s <= x[t]._r) rv += 'X';
        else {
          s += d;
          rv += c;
        }
      } else {
        rv += c;
        s += d;
      }
    } 
    puts(rv.data());
  }
  return 0;
}
