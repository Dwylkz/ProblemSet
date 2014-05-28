#include <vector>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e6+10;

namespace splay {
  struct node {
    node *s[2], *p;
    int sz, w, sm, mx;
    bool root() {
      return !p;
    }
    bool which() {
      return p->s[1] == this;
    }
    node *sets(int b, node *x) {
      if (s[b] = x) x->p = this;
      return this;
    }
    node *pull() {
      sz = 1;
      sm = w+(s[0]? s[0]->sm: 0);
      for (int i = 0; i < 2; i++) if (s[i]) sz += s[i]->sz;
      mx = sm;
      if (s[0]) mx = max(mx, s[0]->mx);
      if (s[1]) mx = max(mx, s[1]->mx+sm);
      sm += s[1]? s[1]->sm: 0;
      return this;
    }
    node *spin() {
      node *y = p;
      int b = which();
      if (y->root()) p = y->p;
      else y->p->sets(y->which(), this);
      y->sets(b, s[!b])->pull();
      return sets(!b, y);
    }
    node *splay(node *x = 0) {
      for ( ; p != x; )
        if (p == x || p->p == x) spin();
        else {
          if (which() == p->which()) p->spin();
          else spin();
          spin();
        }
      return pull();
    }
    node *end(int b) {
      node *x = this;
      for ( ; x->s[b]; ) x = x->s[b];
      return x;
    }
    node *to(int b) {
      if (s[b]) return s[b]->end(!b);
      return this;
    }
    node *pick(int k) {
      node *x = this;
      for ( ; ; ) {
        int i = 1+(x->s[0]? x->s[0]->sz: 0);
        if (i == k) break;
        x = x->s[i < k];
        k -= i*(i < k);
      }
      return x;
    }
  } pool[N], *top;
  void init() {
    top = pool;
  }
  node *make(int w) {
    node t = {{0, 0}, 0, 1, w, w, w};
    *top = t;
    return top++;
  }
  node *put(node *x, int b, node *y) {
    if (x->splay()->s[b]) x->to(b)->sets(!b, y);
    else x->sets(b, y);
    return y->splay();
  }
  node *drop(node *x) {
    if (!x->splay()->s[1]) {
      if (x->s[0]) x->s[0]->p = 0;
      return x->s[0];
    }
    return x->to(1)->splay()->sets(0, x->s[0])->pull();
  }
  node *show(node *x) {
    if (x->s[0]) show(x->s[0]);
    printf(" %d", x->w);
    if (x->s[1]) show(x->s[1]);
    return x;
  }
}
using namespace splay;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int q; ~scanf("%d", &q); ) {
    init();
    node *rr = make(0), *ll = make(0)->sets(1, rr), *p = rr->splay();
    for (int i = 0; i < q; i++) {
      char op[2];
      scanf("%s", op);
      if (*op == 'D') {
        drop(p->splay()->to(0));
      } else if (*op == 'L') {
        node *x = p->splay()->to(0)->splay();
        if (x != ll) p = x;
      } else if (*op == 'R') {
        if (p != rr) p = p->splay()->to(1)->splay();
      } else {
        int x;
        scanf("%d", &x);
        if (*op == 'I') {
          put(p, 0, make(x));
        } else if (*op == 'Q') {
          ll->splay();
          node *y = p->splay(ll)->s[0]->pick(x)->splay(ll);
          int mx = y->sm-(y->s[1]? y->s[1]->sm: 0);
          if (y->s[0]) mx = max(mx, y->s[0]->mx);
          printf("%d\n", mx);
        }
      }
    }
  }
  return 0;
}
