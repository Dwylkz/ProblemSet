#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ctime>
using namespace std;
const int N = 1e4+10;

struct node {
  node *s[2];
  int size, weight;
  int key;
  int rank() {
    return s[0]? s[0]->size+1: 1;
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
  srand((unsigned)time(0));
  top = s;
}
node *make(int key) {
  return &(*top++ = (node){{}, 1, rand()*rand(), key});
}
void merge(node *x, node *y, node *&t) {
  if (!x || !y) t = x? x: y;
  else if (x->weight < y->weight)
    x, merge(x->s[1], y, x->s[1]), t = x->pull();
  else y, merge(x, y->s[0], y->s[0]), t = y->pull();
}
void split(node *t, int k, node *&x, node *&y) {
  if (!k) x = 0, y = t;
  else if (t->size == k) x = t, y = 0;
  else if (k < t->rank())
    y = t, split(t->s[0], k, x, y->s[0]), y->pull();
  else x = t, split(t->s[1], k-t->rank(), x->s[1], y), x->pull();
}
void slice(node *&t, int l = -1, int r = -1) {
  static node *a, *b;
  if (~l) split(t, l-1, a, b), split(b, r-l+1, t, b);
  else merge(t, b, b), merge(a, b, t);
}

int n, m, k;

int main() {
  for ( ; ~scanf("%d%d%d", &n, &k, &m), n|k|m; ) {
    node *rt = 0;
    init();
    for (int i = 1; i <= n; i++)
      merge(rt, make(i), rt);
    int p = m;
    while (rt->size > 1) {
      slice(rt, p, p);
      slice(rt = 0);
      p = ((p-1)+k-1)%rt->size+1;
    }
    printf("%d\n", rt->key);
  }
  return 0;
}
