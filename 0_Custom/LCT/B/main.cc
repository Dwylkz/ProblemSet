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
    int rev;
    int type()
    {
      if (!p || p->c[0] != this && p->c[1] != this) return 2;
      return p->c[0] != this;
    }
    node *set()
    {
      swap(c[0], c[1]);
      rev ^= 1;
      return this;
    }
    node *push()
    {
      if (rev) {
        for (int i = 0; i < 2; i++)
          if (c[i]) c[i]->set();
        rev = 0;
      }
      return this;
    }
    node *update()
    {
      return this;
    }
    node *rotate()
    {
      p->p->push();
      node *y = p->push();
      int b = push()->type(), pb = y->type();
      if (p = y->p, pb < 2) p->c[pb] = this;
      if (y->c[b] = c[!b]) c[!b]->p = y;
      return c[!b] = y, y->update()->p = this;
    }
    node *splay()
    {
      for ( ; type() < 2; type() < 2? rotate(): 0)
        type() == p->type()? p->rotate(): rotate();
      return update();
    }
    node *end(int b)
    {
      node *x = this;
      for ( ; x->push()->c[b]; x = x->c[b]) ;
      return x;
    }
  } pool[N], *top;
  node *init()
  {
    return top = pool;
  }
  node *make_tree()
  {
    return &(*top++ = (node){0, 0, 0, 0});
  }
  node *access(node *x)
  {
    for (node *y = x, *z = 0; y; z = y, y = y->update()->p)
      y->splay()->c[1] = z;
    return x;
  }
  node *find_root(node *x)
  {
    return access(x)->splay()->end(0)->splay();
  }
  node *cut(node *x)
  {
    access(x);
    x->c[0] = 0;
    return x;
  }
  node *join(node *x, node *y)
  {
    access(x)->p = y;
    return access(x);
  }
  node *rooting(node *x)
  {
    return access(x)->splay()->set();
  }
}
using namespace lct;

int n, m;

lct::node *rt[maxn];

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    init();
    for (int i = 0; i < n; i++) rt[i] = make_tree();
    char op[10];
    for (int x, y; m--; ) {
      scanf("%s%d%d", op, &x, &y);
      if (x > y) swap(x, y);
      if (op[0] == 'C') {
        rooting(rt[x]);
        join(rt[x], rt[y]);
      } else if (op[0] == 'D') {
        rooting(rt[x]);
        cut(rt[y]);
      } else puts(find_root(rt[x-1]) == find_root(rt[y-1])? "Yes": "No");
    }
  }
  return 0;
}
