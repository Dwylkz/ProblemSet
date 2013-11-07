#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ctime>
using namespace std;
const int N = 1e5+10;
typedef long long LL;

struct treap_t {
  struct node {
    node *s[2];
    int size, weight;
    LL key, sum[5];
    int rank() {
      return s[0]? 1+s[0]->size: 1;
    }
    node *pull() {
      size = 1;
      for (int i = 0; i < 2; i++) {
        if (!s[i]) continue;
        size += s[i]->size;
      }
      memset(sum, 0, sizeof(sum));
      if (s[0]) memcpy(sum, s[0]->sum, sizeof(sum));
      sum[rank()%5] += key;
      if (s[1]) {
        for (int i = 0; i < 5; i++)
          sum[(i+rank())%5] += s[1]->sum[i];
      }
      return this;
    }
  } s[N], *top;
  int random() {
    static int x = 0x1811, y = 0x1118;
    x = 36969*(x&0x7fffffff)+(x>>16);
    y = 18000*(y&0x7fffffff)+(y>>16);
    return (x<<16)+y;
  }
  void init() {
    top = s;
  }
  node *make() {
    node t = {{0}, 1, random(), 0, {0}};
    *top = t;
    return top++;
  }
  void merge(node *x, node *y, node *&t) {
    if (!x || !y) t = x? x: y;
    else if (x->weight < y->weight)
      merge(x->s[1], y, x->s[1]), t = x->pull();
    else merge(x, y->s[0], y->s[0]), t = y->pull();
  }
  void split(node *t, int k, node *&x, node *&y) {
    if (!k) x = 0, y = t;
    else if (t->size == k) x = t, y = 0;
    else if (k <= t->rank()-1)
      y = t, split(t->s[0], k, x, y->s[0]), y->pull();
    else x = t, split(t->s[1], k-t->rank(), x->s[1], y), x->pull();
  }
  void show(node *t) {
    if (t) show(t->s[0]), printf(" %lld", t->key), show(t->s[1]);
  }
  int find(node *t, int k) {
    if (!t) return 1;
    if (t->key == k) return 1+t->rank();
    if (k < t->key) return find(t->s[0], k);
    return t->rank()+find(t->s[1], k);
  }
  void put(node *&t, int k, node *x) {
    node *a, *b;
    split(t, k, a, b);
    merge(a, x, a);
    merge(a, b, t);
  }
  void drop(node *&t, int k) {
    node *a, *b;
    split(t, k, a, b);
    split(a, k-1, a, t);
    merge(a, b, t);
  }
};

treap_t zkl;
int n;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    zkl.init();
    treap_t::node *rt = 0;
    for ( ; n--; ) {
      char op[20];
      scanf("%s", op);
      if (*op == 's') {
        printf("%lld\n", rt->sum[3]);
      } else {
        int x;
        scanf("%d", &x);
        if (*op == 'a') {
          int k = zkl.find(rt, x);
          treap_t::node *y = zkl.make();
          y->key = y->sum[1] = x;
          zkl.put(rt, k-1, y);
        } else if (*op == 'd') {
          int k = zkl.find(rt, x);
          zkl.drop(rt, k-1);
        }
      }
    }
  }
  return 0;
}
