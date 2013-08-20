#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 3e5+10;

namespace graph {
  struct edge_t {
    int v, to;
  };
  vector<edge_t> E;
  int L[N];
  void init(int n) {
    E.clear();
    memset(L, -1, sizeof(int)*n);
  }
  void add(int u, int v) {
    edge_t t = {v, L[u]};
    L[u] = E.size();
    E.push_back(t);
  }
}
using namespace graph;
namespace lct {
  struct lct_t {
    lct_t *s[2], *p;
    int rev, w, mx;
    lct_t *sets(int b, lct_t *x) {
      if (s[b] = x) x->p = this;
      return this;
    }
    bool root() {
      return !p || !(p->s[0] == this || p->s[1] == this);
    }
    bool which() {
      return p->s[1] == this;
    }
    lct_t *set() {
      swap(s[0], s[1]);
      rev ^= 1;
      return this;
    }
    lct_t *update() {
      mx = w;
      for (int i = 0; i < 2; i++)
        mx = max(mx, s[i]->mx);
      return this;
    }
    lct_t *push() {
      if (rev) {
        for (int i = 0; i < 2; i++)
          if (s[i]) s[i]->set();
        rev = 0;
      }
      return this;
    }
    lct_t *rotate() {
      lct_t *y = p->push();
      int b = push()->which();
      y->sets(b, s[!b])->update();
      if (y->root()) p = y->p;
      else y->p->sets(y->which(), this);
      return sets(!b, y);
    }
    lct_t *splay() {
      for ( ; !root(); ) 
        if (p->root()) rotate();
        else {
          if (which() == p->which()) p->rotate();
          else rotate();
          rotate();
        }
      return update();
    }
    lct_t *end(int b) {
      lct_t *x = this;
      for ( ; x->push()->s[b]; x = x->s[b]) ;
      return x;
    }
  } lct[N], *top;
  void init() {
    top = lct;
  }
  lct_t *make(int w) {
    *top = (lct_t){{0, 0}, 0, w, w};
    return top++;
  }
  lct_t *access(lct_t *x) {
    for (lct_t *y = x, *z = 0; y; z = y, y = y->p)
      y->splay()->push()->sets(1, z)->update();
    return x->splay();
  }
  lct_t *join(lct_t *x, lct_t *y) {
    return x->p = y;
  }
  lct_t *cut(lct_t *x) {
    if (access(x)->s[0]) x->s[0]->p = 0;
    x->s[0] = 0;
    return x;
  }
  lct_t *find(lct_t *x) {
    return access(x)->end(0);
  }
  lct_t *rooting(lct_t *x) {
    return access(x)->set();
  }
}
using namespace lct;

int n, m, w[N];
lct_t *rt[N];

void dfs(int u, int p = -1) {
  rt[u] = make(w[u]);
  if (~p) join(rt[u], rt[E[p].v]);
  for (int i = L[u]; ~i; i = E[i].to)
    if (i != p) dfs(E[i].v, i^1);
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    graph::init(n+1);
    for (int i = 0; i < n-1; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      add(u, v);
      add(v, u);
    }
    for (int i = 1; i <= n; i++) scanf("%d", w+i);
    lct::init();
    dfs(1);
    scanf("%d", &m);
    for ( ; m--; ) {
      int op, x, y;
      scanf("%d%d%d", &op, &x, &y);
      if (op == 1) {
      } else if (op == 2) {
      } else if (op == 4) {
      } else {
        int z;
        scanf("%d", &z);
      }
    }
  }
  return 0;
}
