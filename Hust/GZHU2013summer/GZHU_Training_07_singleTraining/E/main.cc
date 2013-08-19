#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;

int n, s[N];

struct seg_t {
  seg_t *ls, *rs;
  int l, r, sm, lm, rm;
  int mid() {
    return l+r>>1;
  }
  void update(seg_t *_ls, seg_t *_rs) {
    int com = s[_ls->r] == s[_rs->l]? 0: s[_ls->r] < s[_rs->l]? -1: 1;
    sm = _ls->sm + _rs->sm;
    lm = _ls->lm;
    rm = _rs->rm;
    if (com) {
      if (!_ls->rm && !_rs->lm && com) sm++;
      if (_ls->rm != com) sm++;
      if (com != _rs->lm) sm++;
      if (!_ls->lm) lm = com;
      if (!_rs->rm) rm = com;
    } else if (_ls->rm != _rs->lm) sm++;
  }
} seg[N<<1], *top;
void build(int l, int r, seg_t *x) {
  *x = (seg_t){0, 0, l, r, 0, 0};
  if (l == r) return ;
  build(l, x->mid(), x->ls = ++top);
  build(x->mid()+1, r, x->rs = ++top);
  x->update(x->ls, x->rs);
}
seg_t ask(int l, int r, seg_t *x = seg) {
  seg_t ans = *x;
  return ans;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) scanf("%d", s+i);
    build(0, n-1, top = seg);
    int m;
    scanf("%d", &m);
    for ( ; m--; ) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", ask(l, r).sm);
    }
  }
  return 0;
}
