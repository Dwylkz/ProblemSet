#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cctype>
using namespace std;
const int N = 2e5+10;

struct Node {
  int size, key;
  int mkey;
  int add_tag, reverse_tag;
  Node *p, *s[2];
  int rank() {
    return s[0]? s[0]->size+1: 1;
  }
  int side() {
    return p->s[1] == this;
  }
  Node *set_add(int _add) {
    add_tag += _add;
    key += _add;
    mkey += _add;
    return this;
  }
  Node *set_reverse() {
    reverse_tag ^= 1;
    swap(s[0], s[1]);
    return this;
  }
  Node* push() {
    for (int b = 0; b < 2; b++) {
      if (!s[b]) continue;
      if (add_tag) s[b]->set_add(add_tag);
      if (reverse_tag) s[b]->set_reverse();
    }
    add_tag = reverse_tag = 0;
    return this;
  }
  Node *pull() {
    mkey = key;
    for (int b = size = 1; ~b; b--) {
      if (!s[b]) continue;
      size += s[b]->size;
      mkey = min(mkey, s[b]->mkey);
    }
    return this;
  }
  Node *set(int b, Node *x) {
    if (push()->s[b] = x) x->p = this;
    return pull();
  }
  Node *get(int b) {
    return push()->s[b];
  }
  Node *cut(int b, Node *&x) {
    if (x = push()->s[b]) x->p = 0;
    return s[b] = 0, pull();
  }
  Node *spin() {
    Node *y = p->push();
    int b = push()->side();
    if (p = y->p) p->s[y->side()] = this;
    if (y->s[b] = s[!b]) s[!b]->p = y;
    return (s[!b] = y->pull())->p = this;
  }
  Node *fine(Node *y = 0) {
    for (push(); p != y; spin())
      if (p->p != y)
        if (side() != p->side()) spin();
        else p->spin();
    return pull();
  }
  Node *pick(int k, Node *y = 0) {
    Node *x = this;
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
Node *make(int w) {
  Node t = {1, w, w, 0};
  return &(*top++ = t);
}
void show(Node *t) {
  if (!t) return ;
  show(t->get(0));
  printf(" %2d", t->key);
  show(t->s[1]);
  t->pull();
}

int n, m;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  scanf("%d", &n);
  init();
  Node *rt = make(-1)->set(1, make(-2));
  for (int i = 0; i < n; i++) {
    int w;
    scanf("%d", &w);
    Node *x = make(w);
    rt->s[1]->set(0, x);
    rt = x->fine();
  }
  scanf("%d", &m);
  for ( ; m--; ) {
    char op[20];
    int a, b, c;
    Node *x, *y;
    scanf("%s%d", op, &a);
    x = rt->pick(a);
    if (*op == 'D') {
      x = x->get(1)->pick(2, x)->cut(0, y);
    } else {
      scanf("%d", &b);
      if (*op == 'I') {
        x = x->get(1)->pick(1);
        x = x->get(1)->pick(1, x)->set(0, make(b));
      } else {
        x = x->get(1)->pick(b-a+2, x)->get(0);
        if (*op == 'M') {
          printf("%d\n", x->mkey);
        } else if (*op == 'A') {
          scanf("%d", &c);
          x->set_add(c);
        } else if (op[3] == 'E') {
          x->set_reverse();
        } else {
          scanf("%d", &c);
          if (c = (c%x->size+x->size)%x->size) {
            x = x->pick(x->size-c, x->p)->cut(1, y);
            x = x->pick(1, x->p)->set(0, y);
          }
        }
      }
    }
    rt = x->fine();
#if 0
    printf("%-12s: [ ", op), show(rt), puts(" ]");
#endif
  }
  return 0;
}
