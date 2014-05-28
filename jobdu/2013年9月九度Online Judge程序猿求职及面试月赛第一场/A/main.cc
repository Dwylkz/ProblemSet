#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
typedef map<int, int> mii_t;
#define _i(t) t::iterator
const int N = 1e5+10;

struct ft_t {
  int s[N];
  void init() {
    memset(s, 0, sizeof(s));
  }
  void put(int x, int y) {
    for (x++; x < N; x += -x&x) s[x] = max(s[x], y);
  }
  int ask(int x, int rv = 0) {
    for (x++; x; x -= -x&x) rv = max(rv, s[x]);
    return rv;
  }
} zkl;

int n, a[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    mii_t m;
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
      m[a[i]] = 1;
    }
    int r = 1;
    for (_i(mii_t) i = m.begin(); i != m.end(); i++)
      i->second = r++;
    int rv = 0;
    zkl.init();
    for (int i = 0; i < n; i++) {
      int t = zkl.ask(m[a[i]]-1)+1;
      rv = max(t, rv);
      zkl.put(m[a[i]], t);
    }
    printf("%d\n", rv);
  }
  return 0;
}
