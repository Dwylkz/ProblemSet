#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <iostream>
using namespace std;

struct treap_t {
  struct node {
    node *s[2];
    int size, weight;
    int key, cover_tag, sum,
        max_sum, lsum, rsum, reverse_tag;
    int rank() {
      return s[0]? s[0]->size+1: 1;
    }
    node *set_cover(int _key) {
      key = _key;
      cover_tag = 1;
      sum = size*key;
      max_sum = lsum = rsum = max(key, sum);
      return this;
    }
    node *set_reverse() {
      reverse_tag ^= 1;
      swap(s[0], s[1]);
      swap(lsum, rsum);
      return this;
    }
    node *push() {
      for (int i = 0; i < 2; i++) {
        if (!s[i]) continue;
        if (cover_tag) s[i]->set_cover(key);
        if (reverse_tag) s[i]->set_reverse();
      }
      cover_tag = reverse_tag = 0;
      return this;
    }
    node *merge_sum(node *x, node *y) {
      if (!x || !y) {
        x? *this = *x: *this = *y;
        return this;
      }
      sum = x->sum+y->sum;
      lsum = max(x->lsum, x->sum+y->lsum);
      rsum = max(y->rsum, x->rsum+y->sum);
      max_sum = max(x->max_sum, y->max_sum);
      max_sum = max(max_sum, max(lsum, rsum));
      max_sum = max(max_sum, x->rsum+y->lsum);
      return this;
    }
    node *pull() {
      size = 1;
      max_sum = sum = lsum = rsum = key;
      for (int i = 0; i < 2; i++) {
        if (!s[i]) continue;
        size += s[i]->size;
      }
      return merge_sum(node(*this).merge_sum(s[0], this), s[1]);
    }
  };
  node *give(node *t = 0) {
    static node *top = 0;
    static int size = 1;
    if (t) t->s[1] = top, top = t;
    else {
      if (!top) {
        top = new node[size<<=1];
        for (int i = 0; i < size-1; i++)
          top[i].s[1] = top+i+1;
        top[size-1].s[1] = 0;
      }
      t = top, top = top->s[1];
    }
    return t;
  }
  node *make(int key) {
    static int seed = 0x18111118;
    node t = {{0}, 1, seed, key, 0, key, key, key, key, 0};
    seed += 0x18*(seed<<11)+0x11*(seed>>18)+0x29;
    return &(*give() = t);
  }
  void drop(node *&t) {
    if (!t) return ;
    drop(t->s[0]), drop(t->s[1]);
    give(t), t = 0;
  }
  void merge(node *x, node *y, node *&t) {
    if (!x || !y) t = x? x: y;
    else if (x->weight < y->weight)
      x->push(), merge(x->s[1], y, x->s[1]), t = x->pull();
    else y->push(), merge(x, y->s[0], y->s[0]), t = y->pull();
  }
  void split(node *t, int k, node *&x, node *&y) {
    if (!k) x = 0, y = t;
    else if (t->size == k) x = t, y = 0;
    else if (k < t->rank())
      y = t->push(), split(t->s[0], k, x, y->s[0]), y->pull();
    else x = t->push(), split(t->s[1], k-t->rank(), x->s[1], y), x->pull();
  }
  void slice(node *&t, int l = -1, int r = -1) {
    static node *a, *b;
    if (~l) split(t, l-1, a, b), split(b, r-l+1, t, b);
    else merge(t, b, b), merge(a, b, t);
  }
  void show(node *t) {
    if (!t) return ;
    t->push();
    show(t->s[0]);
    printf(" %2d", t->key);
    show(t->s[1]);
    t->pull();
  }
  int ask_sum(node *t) {
    return t? t->sum: 0;
  }
  int ask_max_sum(node *t) {
    return t? t->max_sum: 0;
  }
};
typedef treap_t::node node;

int get_int() {
  int x = 0, c = getchar(), b = 1;
  for ( ; isspace(c); ) c = getchar();
  if (c == '-') b = -1, c = getchar();
  for ( ; isdigit(c); c = getchar()) x = x*10+c-'0';
  return x*b;
}

treap_t zkl;
int n, m;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    node *rt = 0;
    for (int i = 0; i < n; i++)
      zkl.merge(rt, zkl.make(get_int()), rt);
    for ( ; m--; ) {
      char op[20];
      scanf("%s", op);
      if (op[2] == 'X') {
        printf("%d\n", zkl.ask_max_sum(rt));
      } else {
        int posi = get_int(), tot = get_int();
        if (*op == 'I') {
          node *x = 0;
          zkl.split(rt, posi, x, rt);
          for (int i = 0; i < tot; i++)
            zkl.merge(x, zkl.make(get_int()), x);
          zkl.merge(x, rt, rt);
        } else {
          zkl.slice(rt, posi, posi+tot-1);
          if (*op == 'D') {
            zkl.drop(rt);
          } else if (*op == 'M') {
            rt->set_cover(get_int());
          } else if (*op == 'R') {
            rt->set_reverse();
          } else if (*op == 'G') {
            printf("%d\n", zkl.ask_sum(rt));
          }
          zkl.slice(rt);
        }
      }
    }
    zkl.drop(rt);
  }
  return 0;
}
