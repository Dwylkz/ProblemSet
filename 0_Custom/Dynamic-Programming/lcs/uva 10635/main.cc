#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 250*250+10;

int n, p, q, s[N], m[N];
void put(int x, int c) {
  for (x++; x < N; x += -x&x) s[x] = max(s[x], c);
}
int ask(int x, int rv = 0) {
  for (x++; x; x -= -x&x) rv = max(rv, s[x]);
  return rv;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int Case = 1; Case <= T; Case++) {
    scanf("%d%d%d", &n, &p, &q);
    memset(m, -1, sizeof(m));
    for (int i = 0, pi; i <= p; i++) {
      scanf("%d", &pi);
      m[pi] = i;
    }
    memset(s, 0, sizeof(s));
    int rv = 2;
    for (int qi, i = 0; i <= q; i++) {
      scanf("%d", &qi);
      if (!i) put(m[qi], 1);
      else if (~m[qi]) {
        int t = ask(m[qi])+1;
        rv = max(rv, t);
        put(m[qi], t);
      }
    }
    printf("Case %d: %d\n", Case, rv);
  }
  return 0;
}
