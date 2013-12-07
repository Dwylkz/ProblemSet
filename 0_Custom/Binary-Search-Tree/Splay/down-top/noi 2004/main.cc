#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;

struct Splay {
  struct Node {
    int size, key;
    Node *p, *s[2];
    int side() {
      return p->s[1] == this;
    }
    int rank() {
      return s[0]? s[0]->size+1: 1;
    }
    Node *pull() {
      size = 1;
      for (int i = 0; i < 2; i++)
        if (s[i]) size += s[i]->size;
      return this;
    }
    Node *spin() {
      Node *y = p;
      int b = side();
      if (p = y->p) p->s[y->side()] = this;
      if (y->s[b] = s[!b]) s[!b]->p = y;
      return (s[!b] = y->pull())->p = this;
    }
    Node *fine(Node *y = 0) {
      for ( ; p != y; spin())
        if (side() != p->side()) spin();
        else p->spin();
      return pull();
    }
    Node *set(int b, Node *x) {
      if (s[b] = x) x->p = this;
      return pull();
    }
    Node *get(int b) {
      return s[b];
    }
    Node *cut(int b, Node *&x) {
      if (x = s[b]) x->p = 0;
      s[b] = 0;
      return pull();
    }
    Node *pick(int k, Node *y = 0) {
      Node *x = this;
      for ( ; x->rank() != k; ) {
        int b = x->rank() < k;
        k -= x->rank()*b;
        x = x->s[b];
      }
      return fine(y);
    }
  } s[N], *top;
  void init() {
    top = s;
  }
  Node *make(int key) {
    Node t = {1, key, 0};
    return &(*top++ = t);
  }
  void merge(Node *x, Node *y, Node *&t) {
    if (!x || !y) t = x? x: y;
    else t = x->pick(x->size)->set(1, y);
  }
  void split(Node *t, int k, Node *&x, Node *&y) {
    if (k <= 0) x = 0, y = t;
    else if (k >= t->size) x = t, y = 0;
    else x = t->pick(k)->cut(1, y);
  }
  void slice(Node *&t, int l = -1, int r = -1) {
    static Node *a, *b;
    if (~l) split(t, l-1, a, b), split(b, r-l+1, t, b);
    else merge(t, b, b), merge(a, b, t);
  }
  void show(Node *t, int d) {
    if (!t) return ;
    show(t->s[0], d);
    printf(" %d", t->key+d);
    show(t->s[1], d);
  }
  int find(Node *t, int k) {
    int result = 1;
    for ( ; t; ) {
      int b = t->key <= k;
      result += b*t->rank();
      t = t->s[b];
    }
    return result;
  }
  int size(Node *t) {
    return t? t->size: 0;
  }
};
typedef Splay::Node Node;

Splay zkl;
int n, m;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    zkl.init();
    Node *rt = 0;
    int d = 0, left = 0;
    for (int i = 0; i < n; i++) {
      char op[20];
      int k;
      scanf("%s%d", op, &k);
      if (*op == 'I') {
        if (k >= m) {
          if (!rt) rt = zkl.make(k-d);
          else {
            int r = zkl.find(rt, k-d)-1;
#if 1
            printf("r=%d\n", r);
#endif
            zkl.slice(rt, 0, r);
            zkl.merge(rt, zkl.make(k-d), rt);
            zkl.slice(rt);
          }
        }
      } else if (*op == 'A') {
        d += k;
      } else if (*op == 'S') {
        d -= k;
      } else if (*op == 'F') {
        if (k > zkl.size(rt)) printf("%d\n", -1);
        else {
          rt = rt->pick(k);
          printf("%d\n", rt->key+d);
        }
      }
#if 0
      printf("d=%d, r=%d\n", m-d-1, r);
#endif
      if (rt) {
        int r = zkl.find(rt, m-d-1)-1;
        if (r) {
          zkl.slice(rt, 0, r);
          left += zkl.size(rt);
          zkl.slice(rt = 0);
        }
      }
#if 1
      printf("%s %d: [ ", op, k), zkl.show(rt, 0), puts(" ]");
#endif
    }
    printf("%d\n", left);
  }
  return 0;
}
