#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
typedef map<int, int> mii_t;
typedef mii_t::iterator mii_i; 
const int N = 1e5+10;

struct ft_t {
  int s[N];
  void init() {
    memset(s, 0, sizeof(s));
  }
  void put(int x, int c) {
    for (x++; x < N; x += -x&x) s[x] = max(s[x], c);
  }
  int ask(int x, int rv = 0) {
    for (x++; x; x -= -x&x) rv = max(rv, s[x]);
    return rv;
  }
};

int n, s[N], f[N], g[N];
ft_t zkl;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    mii_t m;
    for (int i = 0; i < n; i++) {
      scanf("%d", s+i);
      m[s[i]] = 1;
    }
    int r = 1;
    for (mii_i i = m.begin(); i != m.end(); i++) i->second = r++;
    for (int i = 0; i < n; i++) s[i] = m[s[i]]-1;
    zkl.init();
    for (int i = 0; i < n; i++) {
      int t = zkl.ask(s[i]-1)+1;
      f[i] = t;
      zkl.put(s[i], t);
    }
    zkl.init();
    for (int i = n-1; i >= 0; i--) {
      int t = zkl.ask(s[i]-1)+1;
      g[i] = t;
      zkl.put(s[i], t);
    }
    int mx = 1;
    for (int i = 0; i < n; i++) mx = max(mx, min(f[i], g[i])-1<<1|1);
    printf("%d\n", mx);
  }
  return 0;
}
