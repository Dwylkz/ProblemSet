#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2e5+10;

struct treap_t {
  struct node {
    node *s[2];
    int size, weight;
    int sum, sum_tag, reverse_tag;
    int rank() {
      return 1+(s[0]? s[0]->size: 0);
    }
    node *set(int _sum, int _reverse) {
      sum += _sum;
      sum_tag += _sum;
      if (_reverse) {
        reverse_tag ^= _reverse;
        swap(s[0], s[1]);
      }
      return this;
    }
    node *push() {
      for (int i = 0; i < 2; i++)
        if (s[i]) s[i]->set(sum_tag, reverse_tag);
      reverse_tag = sum_tag = 0;
      return this;
    }
    node *pull() {
      size = 1;
      for (int i = 0; i < 2; i++)
        if (s[i]) size += s[i]->size;
      return this;
    }
  } s[N], *top;
  int random() {
    static unsigned int x = 0x18111118;
    return x += 0x1811*(x>>11)+0x1118*(x<<18)+29;
  }
  void init() {
    top = s;
  }
  node *make() {
    node t = {0, 0, 1, random(), 0, 0, 0};
    *top = t;
    return top++;
  }
  node *pick(node *t, int k) {
    node *x = 0;
    if (t->rank() == k) x = t;
    else {
      if (k < t->push()->rank()) x = pick(t->s[0], k);
      else x = pick(t->s[1], k-t->rank());
      t->pull();
    }
    return x;
  }
  void merge(node *x, node *y, node *&t) {
    if (!x || !y) t = x? x: y;
    else if (x->weight < y->weight)
        x->push(), merge(x->s[1], y, x->s[1]), t = x->pull();
    else y->push(), merge(x, y->s[0], y->s[0]), t = y->pull();
  }
  void split(node *t, int a, node *&x, node *&y) {
    if (!a) x = 0, y = t;
    else if (t->size == a) x = t, y = 0;
    else if (a <= t->rank()-1)
      y = t->push(), split(t->s[0], a, x, y->s[0]), y->pull();
    else x = t->push(), split(t->s[1], a-t->rank(), x->s[1], y), x->pull();
  }
  void slice(node *&t, int l, int r, int b = 1) {
    static node *x, *y;
    if (b) split(t, l-1, x, y), split(y, r-l+1, t, y);
    else merge(t, y, y), merge(x, y, t);
  }
  void show(node *t) {
    if (t) t->push(), show(t->s[0]), printf(" %d", t->sum), show(t->s[1]); 
  }
  void put(node *&t, int k, node *x) {
    node *a, *b;
    split(t, k, a, b);
    merge(a, x, a);
    merge(a, b, t);
  }
  void drop(node *&t, int k) {
    node *x, *y;
    split(t, k, x, y);
    split(x, k-1, x, t);
    merge(x, y, t);
  }
  void loop_fix(node *&t, int &i, int l) {
    if (l <= t->size) return ;
    node *x, *y;
    i -= l-t->size;
    split(t, l-t->size, x, y);
    merge(y, x, t);
  }
  void loop_to(node *t, int &i, int b) {
    if (i+b > t->size) i = 1;
    else if (i+b < 1) i = t->size;
    else i += b;
  }
};

treap_t zkl;
int n, m, k1, k2;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int kas = 1; ~scanf("%d%d%d%d", &n, &m, &k1, &k2), n|m|k1|k2; kas++) {
    printf("Case #%d:\n", kas);
    zkl.init();
    treap_t::node *rt = 0;
    for (int i = 0; i < n; i++) {
      int w;
      scanf("%d", &w);
      treap_t::node *x = zkl.make();
      x->sum = w;
      zkl.merge(rt, x, rt);
    }
    for (int i = 1; m--; ) {
      char op[20];
      scanf("%s", op);
      if (*op == 'r') {
        zkl.loop_fix(rt, i, i+k1-1);
        zkl.slice(rt, i, i+k1-1);
        rt->set(0, 1);
        zkl.slice(rt, 0, 0, 0);
      } else if (*op == 'd') {
        zkl.drop(rt, i);
        zkl.loop_to(rt, i, 0);
      } else if (*op == 'q') {
        printf("%d\n", zkl.pick(rt, i)->sum);
      } else {
        int x;
        scanf("%d", &x);
        if (*op == 'a') {
          zkl.loop_fix(rt, i, i+k2-1);
          zkl.slice(rt, i, i+k2-1);
          rt->set(x, 0);
          zkl.slice(rt, 0, 0, 0);
        } else if (*op == 'i') {
          treap_t::node *y = zkl.make();
          y->sum = x;
          zkl.put(rt, i, y);
        } else if (*op == 'm') {
          if (x == 1) zkl.loop_to(rt, i, -1);
          else zkl.loop_to(rt, i, 1);
        }
      }
    }
  }
  return 0;
}
