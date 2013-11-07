#pragma comment(linker,"/STACK:32768000,32768000")
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ctime>
using namespace std;
const int N = 3e5+10;

struct treap_t {
  struct node {
    node *s[2];
    int size, weight;
    int key, reverse_tag;
    int rank() {
      return s[0]? s[0]->size+1: 1;
    }
    node *set() {
      reverse_tag ^= 1, swap(s[0], s[1]);
      return this;
    }
    node *push() {
      for (int i = 0; i < 2; i++) {
        if (!s[i]) continue;
        if (reverse_tag) s[i]->set();
      }
      reverse_tag = 0;
      return this;
    }
    node *pull() {
      size = 1;
      for (int i = 0; i < 2; i++) {
        if (!s[i]) continue;
        size += s[i]->size;
      }
      return this;
    }
  } s[N], *top;
  void init() {
    top = s;
  }
  node *make(int key) {
    static int seed = 0x18111118;
    seed += 1811*(seed<<11)+1118*(seed>>18)+29;
    node t = {{0}, 1, seed, key, 0};
    *top = t;
    return top++;
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
  void show(node *t, int l, int i = 0) {
    if (!t) return ;
    t->push();
    show(t->s[0], l, i);
    printf("%d%c", t->key, i+t->rank() < l? ' ': '\n');
    show(t->s[1], l, i+t->rank());
    t->pull();
  }
  void slice(node *&t, int l = -1, int r = -1) {
    static node *a, *b;
    if (~l) split(t, l-1, a, b), split(b, r-l+1, t, b);
    else merge(t, b, b), merge(a, b, t);
  }
  void put(node *&t, int k, node *x) {
    node *a, *b;
    split(t, k, a, b);
    merge(a, x, a);
    merge(a, b, t);
  }
};

treap_t zkl;
int n, m;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; scanf("%d%d", &n, &m); ) {
    if (n < 0 && m < 0) break;
    zkl.init();
    treap_t::node *rt = 0;
    for (int i = 1; i <= n; i++)
      zkl.merge(rt, zkl.make(i), rt);
    for ( ; m--; ) {
      char op[20];
      int a, b, c;
      scanf("%s%d%d", op, &a, &b);
      if (*op == 'C') {
        scanf("%d", &c);
        zkl.slice(rt, a, b);
        treap_t::node *x = 0;
        zkl.slice(x);
        zkl.put(x, c, rt);
        rt = x;
      } else {
        zkl.slice(rt, a, b);
        rt->set();
        zkl.slice(rt);
      }
    }
    zkl.show(rt, rt->size);
  }
  return 0;
}
