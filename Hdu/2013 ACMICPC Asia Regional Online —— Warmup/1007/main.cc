#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;
const int N = 1e5+10;

struct node {
  node *s[2];
} it[N], *top, *rt;
node *make() {
  memset(top, 0, sizeof(it[0]));
  return top++;
}
void init() {
  top = it;
  rt = make();
}
void put(int k) {
  node *x = rt;
  for (int i = 19; i >= 0; i--) {
    int j = k>>i&1;
    if (!x->s[j]) x->s[j] = make();
    x = x->s[j];
  }
}
int ask(int k) {
  node *x = rt;
  int rv = 0;
  for (int i = 19; i >= 0; i--) {
    int j = k>>i&1;
    if (x->s[!j]) {
      x = x->s[!j];
      rv |= 1<<i;
    } else x = x->s[j];
    if (!x) {
      rv |= k&((1<<i)-1);
      break;
    }
  }
  int o = 0;
  for (int i = 0; i < 20; i++) o += (rv>>i&1);
  return o;
}

int n;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    init();
    scanf("%d", &n);
    int rv = 0;
    for (int i = 0; i < n; i++) {
      int ai = 0;
      scanf("%X", &ai);
      if (i) rv = max(rv, ask(ai));
      put(ai);
    }
    printf("%d\n", rv);
  }
  return 0;
}
