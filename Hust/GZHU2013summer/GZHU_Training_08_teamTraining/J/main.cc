#include <cstdio>
#include <map>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;
typedef map<int, int> MII;

struct seg_t {
  seg_t *ls, *rs;
  int s;
} seg[N*22], *top;
void init() {
  top = seg;
}
seg_t *build(int l, int r) {
  seg_t *x = top++;
  *x = (seg_t){0, 0, 0};
  if (l < r) {
    int m = l+r>>1;
    x->ls = build(l, m);
    x->rs = build(m+1, r);
  }
  return x;
}
seg_t *insert(int k, int L, int R, seg_t *y) {
  seg_t *x = top++;
  *x = *y;
  x->s++;
  if (L < R) {
    int m = L+R>>1;
    if (k <= m) x->ls = insert(k, L, m, y->ls);
    else x->rs = insert(k, m+1, R, y->rs);
  }
  return x;
}
int ask(int l, int r, int L, int R, seg_t *x, seg_t *y) {
  int ans = 0;
  if (l <= L && R <= r) ans = y->s-x->s;
  else {
    int m = L+R>>1;
    if (l <= m) ans += ask(l, r, L, m, x->ls, y->ls);
    if (m < r) ans += ask(l, r, m+1, R, x->rs, y->rs);
  }
  return ans;
}

int n, m, s[N], rs[N];
seg_t *rt[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    init();
    rt[0] = build(1, n);
    MII pm;
    for (int i = 1; i <= n; i++) {
      scanf("%d", s+i);
      pm[s[i]] = 1;
    }
    int rank = 0;
    for (MII::iterator i = pm.begin(); i != pm.end(); i++) {
      i->second = ++rank;
      rs[rank] = i->first;
    }
#if 0
    for (int i = 1; i <= n; i++)
      printf("%d%c", rs[i], i < n? ' ': '\n');
    for (int i = 1; i <= n; i++)
      printf("%d%c", pm[s[i]], i < n? ' ': '\n');
#endif
    for (int i = 1; i <= n; i++)
      rt[i] = insert(pm[s[i]], 1, n, rt[i-1]);
    for ( ; m--; ) {
      int l, r, k;
      scanf("%d%d%d", &l, &r, &k);
      int L = 1, R = n;
      for ( ; L < R; ) {
        int m = L+R>>1, x = ask(L, m, 1, n, rt[l-1], rt[r]);
        if (k <= x) R = m;
        else {
          L = m+1;
          k -= x;
        }
      }
      printf("%d\n", rs[L]);
    }
  }
  return 0;
}
