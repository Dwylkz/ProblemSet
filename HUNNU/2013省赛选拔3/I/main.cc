#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int N = 1e6+10;
typedef vector<int> vi_t;

struct edge_t {
  int v, to;
};
vector<edge_t> E;
vi_t L;
void init(int n) {
  E.clear();
  L = vi_t(n, -1);
}
void add(int u, int v) {
  edge_t t = {v, L[u]};
  L[u] = E.size();
  E.push_back(t);
}

int n, p;

vi_t ra, lb, rb, el;
struct st_t {
  int u, e;
  st_t(int _u = 0, int _e = 0):
    u(_u), e(_e) {}
};
vector<st_t> st;
void dfs(int u) {
  int top = 0;
  ra = vi_t(n, -1);
  lb.resize(n);
  rb.resize(n);
  st.resize(n);
  el.clear();
  st[++top] = st_t(u, L[u]);
  for ( ; top ;) {
    int u = st[top].u, &e = st[top].e;
    if (e == L[u]) {
      lb[u] = el.size();
      el.push_back(u);
    }
    for ( ; ~e; e = E[e].to)
      if (e != ra[u]) break;
    if (~e) {
      ra[E[e].v] = e^1;
      st[++top] = st_t(E[e].v, L[E[e].v]);
      e = E[e].to;
    } else {
      rb[u] = el.size();
      top--;
    }
  }
  st.clear();
}

struct node {
  int s;
  node *ls, *rs;
} seg[N*19], *top;
vector<node*> rt;
node *build(int l, int r) {
  node *x = top++, t = {0};
  *x = t;
  if (l == r) return x;
  int m = l+r>>1;
  x->ls = build(l, m);
  x->rs = build(m+1, r);
  return x;
}
node *put(int k, int L, int R, node *y) {
  node *x = top++;
  *x = *y;
  x->s++;
  if (L == R) return x;
  int m = L+R>>1;
  if (k <= m) x->ls = put(k, L, m, y->ls);
  else x->rs = put(k, m+1, R, y->rs);
  return x;
}
int ask(int l, int r, int L, int R, node *x, node *y) {
  int rv = 0;
  if (l <= L && R <= r) rv = y->s-x->s;
  else {
    int m = L+R>>1;
    if (l <= m) rv += ask(l, r, L, m, x->ls, y->ls);
    if (m < r) rv += ask(l, r, m+1, R, x->rs, y->rs);
  }
  return rv;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &p), n|p; ) {
    assert(n <= N);
    init(n);
    p--;
    for (int u, v, i = 0; i < n-1; i++) {
      scanf("%d%d", &u, &v);
      u--, v--;
      add(u, v), add(v, u);
    }
    dfs(p);
    init(0);
    rt.resize(n+1);
    top = seg;
    rt[n] = build(0, n);
    for (int i = n-1; i >= 0; i--) rt[i] = put(el[i], 0, n-1, rt[i+1]);
    el.clear();
    for (int i = 0; i < n; i++)
      printf("%d%c", ask(0, i, 0, n-1, rt[rb[i]], rt[lb[i]])-1, i < n-1? ' ': '\n');
  }
  return 0;
}
