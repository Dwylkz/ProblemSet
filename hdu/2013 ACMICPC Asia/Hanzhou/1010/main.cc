#include <cstdio>
#include <map>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll_t;
const int N = 2e5+10;
typedef map<int, int> mii_t;

struct seg_t {
  struct node {
    int l, r, mx, tag;
    ll_t sm;
    node *ls, *rs;
    int mid() {
      return l+r>>1;
    }
    int len() {
      return r-l+1;
    }
    void set(int _tag) {
      tag = _tag;
      sm = 1LL*_tag*len();
      mx = _tag;
    }
    void push() {
      if (~tag) {
        ls->set(tag);
        rs->set(tag);
        tag = -1;
      }
    }
    void pull() {
      sm = ls->sm+rs->sm;
      mx = max(ls->mx, rs->mx);
    }
  } s[N<<1], *top;
  void init() {
    top = s;
  }
  node *make(int l, int r, int *a) {
    node *x = top++, t = {l, r, 0, -1, 0};
    *x = t;
    if (l == r) x->sm = x->mx = a[l];
    else {
      x->ls = make(l, x->mid(), a);
      x->rs = make(x->mid()+1, r, a);
      x->pull();
    }
    return x;
  }
  void draw(int l, int r, int c, node *x) {
    if (l <= x->l && x->r <= r) x->set(c);
    else {
      int m = x->mid();
      x->push();
      if (l <= m) draw(l, r, c, x->ls);
      if (m < r) draw(l, r, c, x->rs);
      x->pull();
    }
  }
  int upper(int l, int k, node *x) {
    int rv = -1;
    if (x->mx <= k) rv = -1;
    else if (x->l == x->r) rv = x->l;
    else {
      x->push();
      if (l <= x->mid() && k < x->ls->mx) rv = upper(l, k, x->ls);
      else rv = upper(l, k, x->rs);
      x->pull();
    }
    return rv;
  }
  ll_t sum(int l, int r, node *x) {
    ll_t rv = 0;
    if (l <= x->l && x->r <= r) rv = x->sm;
    else {
      int m = x->mid();
      x->push();
      if (l <= m) rv += sum(l, r, x->ls);
      if (m < r) rv += sum(l, r, x->rs);
      x->pull();
    }
    return rv;
  }
} zkl;

int n, s[N], ban[N], mex[N], pos[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n), n; ) {
    for (int i = 0; i < n; i++) {
      scanf("%d", s+i);
      s[i] = min(s[i], N-1);
    }
    memset(ban, 0, sizeof(ban));
    int p = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] < N) ban[s[i]] = 1;
      for ( ; ban[p]; p++) ;
      mex[i] = p;
    }
    memset(ban, -1, sizeof(ban));
    memset(pos, -1, sizeof(pos));
    for (int i = n-1; ~i; i--) {
      if (~ban[s[i]]) pos[i] = ban[s[i]];
      else pos[i] = n;
      ban[s[i]] = i;
    }
    zkl.init();
    seg_t::node *rt;
    rt = zkl.make(0, n-1, mex);
    ll_t rv = 0;
    for (int i = 0; i < n; i++) {
      rv += zkl.sum(i, n-1, rt);
      int l = zkl.upper(i, s[i], rt);
      if (~l && l <= pos[i]-1) zkl.draw(l, pos[i]-1, s[i], rt);
    }
    printf("%lld\n", rv);
  }
  return 0;
}
