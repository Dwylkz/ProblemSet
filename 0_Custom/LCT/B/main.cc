#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cerrno>
using namespace std;
const int maxn = 1e4 + 10;
const int inf32 = 0x7fffffff;
typedef long long LL;
#define eprintf(x...) fprintf(stderr, x)

namespace lct {
  const int N = maxn;
  struct node {
    node *c[2], *p;
    int pt;
    node *update()
    {
      return this;
    }
    node *rotate()
    {
      node *y = p;
      p = y->p;
      if (y->pt != 2) p->c[y->pt] = this;
      if (y->c[pt] = c[!pt]) c[!(c[!pt]->pt = pt)]->p = y;
      (y->p = this)->c[!pt] = y->update();
      swap(pt, y->pt);
      y->pt ^= 1;
      return this;
    }
    node *splay()
    {
      for ( ; pt != 2; ) {
        (pt == p->pt? p: this)->rotate();
        if (pt != 2) rotate();
      }
      return update();
    }
    node *end(int b)
    {
      node *x = this;
      for ( ; x->c[b]; x = x->c[b]) ;
      return x;
    }
  } pool[N], *top;
  node *init()
  {
    return top = pool;
  }
  node *make_tree()
  {
    return &(*top++ = (node){0, 0, 0, 2});
  }
  node *access(node *x)
  {
    for (node *y = x, *z = 0; y; ) {
      y->splay();
      if (y->c[1]) y->c[1]->pt = 2;
      if (z) z->pt = 1;
      y->c[1] = z;
      z = y;
      y = y->update()->p;
    }
    return x;
  }
  node *find_root(node *x)
  {
    return access(x)->splay()->end(0)->splay();
  }
  node *cut(node *x)
  {
    access(x);
    if (x->c[0]) {
      x->c[0]->pt = 2;
      x->c[0] = 0;
    }
    return x;
  }
  node *join(node *x, node *y)
  {
    access(x)->p = y;
    return access(x);
  }
}

int n, m;

lct::node *rt[maxn];

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    scanf("%d", &n);
    lct::init();
    for (int i = 0; i < n; i++)
      rt[i] = lct::make_tree();
    char op[10];
    for (int x, y; m--; ) {
      scanf("%s%d%d", op, &x, &y);
      if (op[0] == 'C') {
        lct::join(find_root(rt[x-1]), rt[y-1]);
      } else if (op[0] == 'D') {
      } else {
      }
    }
  }
  return 0;
}
