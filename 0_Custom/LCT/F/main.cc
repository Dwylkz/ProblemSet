#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2e6 + 10;
typedef long long LL;

namespace lct {
  struct node {
    node *s[2], *p;
    int rev, sz;
    node *sets(int b, node *x) {
      if (s[b] = x) x->p = this;
      return this;
    }
    bool root() {
      return !p || !(p->s[0] == this || p->s[1] == this);
    }
    bool which() {
      return p->s[1] == this;
    }
    node *set() {
      swap(s[0], s[1]);
      rev ^= 1;
      return this;
    }
    node *push() {
      if (rev) {
        for (int i = 0; i < 2; i++)
          if (s[i]) s[i]->set();
        rev = 0;
      }
      return this;
    }
    node *update() {
      sz = 1;
      for (int i = 0; i < 2; i++)
        if (s[i]) sz += s[i]->sz;
      return this;
    }
    node *rotate() {
      node *y = p->push();
      int b = push()->which();
      y->sets(b, s[!b])->update();
      if (y->root()) p = y->p;
      else y->p->sets(y->which(), this);
      return sets(!b, y);
    }
    node *splay() {
      for ( ; !root(); ) 
        if (p->root()) rotate();
        else {
          if (which() == p->which()) p->rotate();
          else rotate();
          rotate();
        }
      return update();
    }
    node *end(int b) {
      node *x = this;
      for ( ; x->push()->s[b]; x = x->s[b]) ;
      return x;
    }
  } lct[N], *top;
  void init() {
    top = lct;
  }
  node *make() {
    *top = (node){{0, 0}, 0, 0, 1};
    return top++;
  }
  node *access(node *x) {
    for (node *y = x, *z = 0; y; z = y, y = y->p)
      y->splay()->push()->sets(1, z)->update();
    return x->splay();
  }
  node *join(node *x, node *y) {
    return x->p = y;
  }
  node *cut(node *x) {
    if (access(x)->s[0]) x->s[0]->p = 0;
    x->s[0] = 0;
    return x->update();
  }
  node *find(node *x) {
    return access(x)->end(0);
  }
  node *rooting(node *x) {
    return access(x)->set();
  }
  int ask(node *x) {
    if (access(x)->s[0]) return x->s[0]->sz;
    return 0;
  }
}
using namespace lct;

node *rt[N];
int n;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    init();
    for (int i = 0; i < n; i++) rt[i] = make();
    for (int i = 0; i < n; i++) {
      int k;
      scanf("%d", &k);
      if (i+k < n) join(rt[i], rt[i+k]);
    }
    int q;
    scanf("%d", &q);
    for ( ; q--; ) {
      int i, j;
      scanf("%d%d", &i, &j);
      if (i == 1) {
        printf("%d\n", ask(rt[j])+1);
      } else {
        LL k;
        scanf("%lld", &k);
        cut(rt[j]);
        if (j+k < n) join(rt[j], rt[j+k]);
      }
    }
  }
  return 0;
}
