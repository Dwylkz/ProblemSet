#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;

struct treap_t {
  struct node {
    node *l, *r;
    int size, weight, key, count;
    int add_tag;
    int rank() {
      return l? l->size+1: 1;
    }
    node *set_add(int _add) {
      add_tag += _add;
      key += _add;
    }
    node *push() {
      if (add_tag) {
        if (l) l->set_add(add_tag);
        if (r) r->set_add(add_tag);
      }
      add_tag = 0;
      return this;
    }
    node *pull() {
      size = 1+(l? l->size: 0)+(r? r->size: 0);
      return this;
    }
  } s[N], *top;
  void init() {
    top = s;
  }
  node *make(int key) {
    node t = {0, 0, 1, rand()*rand(), key, 1, 0};
    *top = t;
    return top++;
  }
  node *pick(node *t, int k) {
    node *result;
    if (!t) result = 0;
    if (t->rank() == k) result = t;
    else {
      t->push();
      if (k <= t->rank()) result = pick(t->l, k);
      else result = pick(t->r, k-t->rank());
      t->pull();
    }
    return result;
  }
  void merge(node *x, node *y, node *&t) {
    if (!x || !y) t = x? x: y;
    else if (x->weight < y->weight)
      x->push(), merge(x->r, y, x->r), t = x->pull();
    else y->push(), merge(x, y->l, y->l), t = y->pull();
  }
  void split(node *t, int k, node *&x, node *&y) {
    if (!k) x = 0, y = t;
    else if (t->size == k) x = t, y = 0;
    else if (k < t->rank())
      y = t->push(), split(t->l, k, x, y->l), y->pull();
    else x = t->push(), split(t->r, k-t->rank(), x->r, y), x->pull();
  }
  void slice(node *&t, int l = -1, int r = -1) {
    static node *a, *b;
    if (~l) split(t, l-1, a, b), split(b, r-l+1, t, b);
    else merge(t, b, b), merge(a, b, t);
  }
  void show(node *t) {
    if (!t) return ;
    t->push();
    show(t->l);
    printf(" %d", t->key);
    show(t->r);
    t->pull();
  }
  int find(node *t, int key) {
    int result;
    if (!t) result = 1;
    else if (t->key == key) result = t->rank()+1;
    else {
      t->push();
      if (key < t->key) result = find(t->l, key);
      else result = t->rank()+find(t->r, key);
      t->pull();
    }
    return result;
  }
};
typedef treap_t::node node;

treap_t zkl;
int n, m;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    zkl.init();
    node *rt = 0;
    int result = 0;
    for ( ; n--; ) {
      char op[20];
      int k;
      scanf("%s%d", op, &k);
      if (*op == 'I') {
        int x = zkl.find(rt, k);
        zkl.slice(rt, 1, x-1);
        if (x-1) rt->count++;
        else zkl.merge(rt, zkl.make(k), rt);
        zkl.slice(rt);
      } else if (*op == 'A') {
        rt->set_add(k);
      } else if (*op == 'S') {
        rt->set_add(-k);
      } else if (*op == 'F') {
        printf("%d\n", k <= rt->size? zkl.pick(rt, k)->key: -1);
      }
      if (rt) {
        int x = zkl.find(rt, m-1);
        node *y;
        result += x-1;
        zkl.slice(rt, 1, x);
        zkl.split(rt, x-1, y, rt);
        zkl.slice(rt);
      }
    }
    printf("%d\n", result);
  }
  return 0;
}
