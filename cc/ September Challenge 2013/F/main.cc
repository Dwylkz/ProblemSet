#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5+10;
const int inf = 0x7f3f3f3f;

struct edge_t {
  int v, to;
};
vector<edge_t> E;
int L[N];
void init() {
  E.clear();
  memset(L, -1, sizeof(L));
}
void add(int u, int v) {
  edge_t t = {v, L[u]};
  L[u] = E.size();
  E.push_back(t);
}

int n, q, w[N];

int el[N], lb[N], rb[N], tm;
// Eular traversal
void et(int u) {
  el[tm] = u;
  lb[u] = tm++;
  for (int e = L[u]; ~e; e = E[e].to) et(E[e].v);
  rb[u] = tm;
}

struct node {
  int l, r, mn, sm, tag;
  node *ls, *rs;
  int mid() {
    return l+r>>1;
  }
  void set(int _tag) {
    tag += _tag;
    mn += _tag;
    if (mn < 1) {
      if (l == r) {
        mn = inf;
        sm = 0;
      } else {
        push();
        pull();
      }
    }
  }
  void push() {
    if (tag) {
      ls->set(tag);
      rs->set(tag);
      tag = 0;
    }
  }
  void pull() {
    sm = ls->sm+rs->sm;
    mn = min(ls->mn, rs->mn);
  }
} seg[N<<1] ,*top;
void build(int l, int r, node *x) {
  node t = {l, r, 0, 0, 0};
  *x = t;
  if (l == r) {
    x->mn = w[el[l]];
    x->sm = 1;
    return ;
  }
  build(l, x->mid(), x->ls = ++top);
  build(x->mid()+1, r, x->rs = ++top);
  x->pull();
}
void draw(int l, int r, int c, node *x = seg) {
  if (l <= x->l && x->r <= r) x->set(c);
  else {
    int m = x->mid();
    x->push();
    if (l <= m) draw(l, r, c, x->ls);
    if (m < r) draw(l, r, c, x->rs);
    x->pull();
  }
}
int ask(int l, int r, node *x = seg) {
  int rv = 0;
  if (l <= x->l && x->r <= r) rv = x->sm;
  else {
    int m = x->mid();
    x->push();
    if (l <= m) rv += ask(l, r, x->ls);
    if (m < r) rv += ask(l, r, x->rs);
    x->pull();
  }
  return rv;
}
void show() {
  printf("sm: ");
  for (int i = 0; i < tm; i++)
    printf(" %4d", ask(i, i));
  puts("");
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    init();
    for (int u, i = 1; i <= n; i++) {
      scanf("%d%d", w+i, &u);
      assert(w[i] <= 1e9);
      add(u, i);
    }
    et(tm = 0);
#if 0
    printf("el: ");
    for (int i = 0; i < tm; i++)
      printf(" %4d", el[i]);
    puts("");
    printf("w : ");
    for (int i = 0; i < tm; i++)
      printf(" %4d", w[el[i]]);
    puts("");
    printf("lb: ");
    for (int i = 0; i < tm; i++)
      printf(" %4d", lb[i]);
    puts("");
    printf("rb: ");
    for (int i = 0; i < tm; i++)
      printf(" %4d", rb[i]);
    puts("");
#endif
    build(0, tm-1, top = seg);
    scanf("%d", &q);
    assert(q <= 1e5);
    for (int op, a, x; q--; ) {
#if 0
      show();
#endif
      scanf("%d%d", &op, &a);
      assert(0 <= a && a <= n);
      if (op == 1) {
        scanf("%d", &x);
        assert(1 <= x && x <= 1e4);
        if (lb[a]+1 < rb[a])
          draw(lb[a]+1, rb[a]-1, -x);
      } else {
        if (lb[a]+1 < rb[a])
          printf("%d\n", ask(lb[a]+1, rb[a]-1));
        else printf("%d\n", 0);
      }
    }
  }
  return 0;
}
