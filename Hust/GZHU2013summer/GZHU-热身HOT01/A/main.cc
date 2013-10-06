#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2e5+10;

/* Splay
 * */
template<int N> struct splay_t {
  struct node {
    node *s[2], *p;
    int sz, w, add_tag, reverse_tag;
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
    node *add(int _add_tag) {
      w += _add_tag;
      add_tag += _add_tag;
      return this;
    }
    node *reverse() {
      swap(s[0], s[1]);
      reverse_tag ^= 1;
      return this;
    }
    node *push() {
      for (int i = 0; i < 2; i++)
        if (s[i]) {
          if (add_tag) s[i]->add(add_tag);
          if (reverse_tag) s[i]->reverse();
        }
      add_tag = reverse_tag = 0;
      return this;
    }
    node *pull() {
      sz = 1;
      for (int i = 0; i < 2; i++) if (s[i]) sz += s[i]->sz;
      return this;
    }
    node *spin() {
      node *y = p->push();
      int b = push()->which();
      if (y->root()) p = y->p;
      else y->p->sets(y->which(), this);
      y->sets(b, s[!b])->pull();
      return sets(!b, y);
    }
    node *splay(node *x = 0) {
      for (push(); p != x; )
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
      for ( ; x->push()->s[b]; ) x = x->s[b];
      return x;
    }
    node *to(int b) {
      if (s[b]) return s[b]->end(!b);
      return this;
    }
    int rank() {
      return 1+(s[0]? s[0]->sz: 0);
    }
    node *pick(int k) {
      node *x = this;
      for ( ; ; ) {
        int i = x->push()->rank();
        if (i == k) break;
        x = x->s[i < k];
        k -= i*(i < k);
      }
      return x;
    }
  } s[N], *top;
  void init() {
    top = s;
  }
  node *make(int w) {
    node t = {{0, 0}, 0, 1, w, 0, 0};
    *top = t;
    return top++;
  }
  node *put(node *x, int b, node *y) {
    if (x->splay()->s[b])
      x->to(b)->sets(!b, y);
    else x->sets(b, y);
    return y->splay();
  }
  node *drop(node *x) {
    if (!x->splay()->push()->s[1]) {
      if (x->push()->s[0]) x->s[0]->p = 0;
      return x->s[0];
    }
    return x->to(1)->splay()->push()->sets(0, x->s[0])->pull();
  }
  node *show(node *x) {
    if (x->s[0]) show(x->s[0]);
    printf(" %d", x->w);
    if (x->s[1]) show(x->s[1]);
    return x;
  }
  node *loop_to(node *x, node *lb, node *rb, int b) {
    x->splay();
    if (b) {
      if (x->to(1) == rb) return lb->splay()->to(1);
      return x->to(1);
    }
    if (x->to(0) == lb) return rb->splay()->to(0);
    return x->to(0);
  }
  node *split(node *x, node *p) {
    x->splay(p)->to(1)->splay(p)->push()->sets(0, 0);
    x->p = 0;
    return x;
  }
  node *combine(node *x, node *p, int k) {
    int rem = x->splay(p)->rank()+k-1-x->sz;
    if (rem > 0) {
      node *q = split(x->pick(rem), p);
      x->splay(p)->pick(x->sz)->push()->sets(1, p);
    }
    return x;
  }
};

typedef splay_t<N> splay_i;
typedef splay_i::node node;
splay_i zkl;

int n, m, k1, k2;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d%d", &n, &m, &k1, &k2), n|m|k1|k2; ) {
    zkl.init();
    node *rb = zkl.make(-2), *lb = zkl.make(-1)->sets(1, rb)->splay();
    for (int i = 0; i < n; i++) {
      int wi;
      scanf("%d", &wi);
      zkl.put(rb, 0, zkl.make(wi));
    }
    node *p = lb->splay()->pick(2);
    for ( ; m--; ) {
      char op[20];
      scanf("%s", op);
      if (*op == 'r') {
        rb->splay(lb->splay());
        zkl.combine(p, rb, k1);
        node *q = p->pick(p->rank()+k1-1),
             *l = p->splay()->to(0),
             *r = q->splay()->to(1);
        r->splay(l->splay())->s[0]->reverse();
        p = q;
      } else if (*op == 'd') {
        node *q = zkl.loop_to(p, lb, rb, 1);
        zkl.drop(p);
        p = q;
      } else if (*op == 'q') {
        printf("%d\n", p->w);
      } else {
        int x;
        scanf("%d", &x);
        if (*op == 'a') {
          rb->splay(lb->splay());
          zkl.combine(p, rb, k2);
          node *q = p->pick(p->rank()+k2-1),
               *l = p->splay()->to(0),
               *r = q->splay()->to(1);
          r->splay(l->splay())->s[0]->add(x);
        } else if (*op == 'i') {
          zkl.put(p, 1, zkl.make(x));
        } else {
          p = zkl.loop_to(p, lb, rb, x-1);
        }
      }
#if 0
      rb->splay(lb->splay());
      printf("after %10s, p in %2d=%2d: ", op, p->splay(rb)->rank(), p->w);
      zkl.show(rb->s[0]);
      puts("");
#endif
    }
  }
  return 0;
}
