#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 5e5+10;

struct node {
  node *p, *s[2];
  int size, key;
  int side() {
    return p->s[1] == this;
  }
  int rank() {
    return s[0]? 1+s[0]->size: 1;
  }
  node *push() {
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
  node *set(int b, node *x) {
    if (push()->s[b] = x) x->p = this;
    return pull();
  }
  node *get(int b) {
    return push()->s[b];
  }
  node *cut(int b, node *&x) {
    if (x = push()->s[b]) s[b]->p = 0;
    s[b] = 0;
    return pull();
  }
  node *spin() {
    node *y = p->push();
    int b = push()->side();
    if (p = y->p) p->s[y->side()] = this;
    if (y->s[b] = s[!b]) s[!b]->p = y;
    return (s[!b] = y)->pull()->p = this;
  }
  node *fine(node *x = 0) {
    for ( ; p != x; spin())
      if (p->p != x)
        if (side() == p->side()) p->spin();
        else spin();
    return pull();
  }
  node *pick(int k, node *y = 0) {
    node *x = this;
    for ( ; x->rank() != k; ) {
      int b = x->rank() < k;
      k -= b*x->rank();
      x = x->get(b);
    }
    return x->fine(y);
  }
} s[N], *top;
void init() {
  top = s;
}
node *make(int key) {
  return &(*top++ = (node){0, {}, 1, key});
}

int n, k;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int nc;
  scanf("%d", &nc);
  for ( ; nc--; ) {
    scanf("%d%d", &n, &k);
    init();
    node *rt = make(-1)->set(1, make(-2));
    for (int i = 1; i <= n; i++) {
      rt->get(1)->set(0, make(i));
      rt = rt->get(1)->get(0)->fine();
    }
    int p = 1;
    while (rt->size > 3) {
      p = (p-1+k-1)%(rt->size-2)+1;
      node *x;
      rt = rt->pick(p);
      rt = rt->pick(p+2, rt)->cut(0, x)->fine();
      if (rt->size < 5) printf("%d ", x->key);

    }
    printf("%d\n", rt->pick(2)->key);
  }
  return 0;
}
