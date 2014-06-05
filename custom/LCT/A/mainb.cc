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
    int pt, w, mx;
    node *update()
    {
      mx = w;
      for (int i = 0; i < 2; i++)
        if (c[i]) mx = max(mx, c[i]->mx);
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
    return &(*top++ = (node){0, 0, 0, 2, -inf32, -inf32});
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
  node *ask(node *x, int &ans)
  {
    for (node *y = x, *z = 0; y; ) {
      y->splay();
      if (!y->p) {
        ans = -inf32;
        if (y->c[1]) ans = max(ans, y->c[1]->mx);
        if (z) ans = max(ans, z->mx);
      }
      if (y->c[1]) y->c[1]->pt = 2;
      if (z) z->pt = 1;
      y->c[1] = z;
      z = y;
      y = y->update()->p;
    }
    return x;
  }
}

struct edge {
  int v, to, i, w;
};
vector<edge> E;
int L[maxn];
void graph_inti()
{
  E.clear();
  memset(L, -1, sizeof(L));
}
void graph_add(int u, int v, int i, int w)
{
  edge t = {v, L[u], i, w};
  L[u] = E.size();
  E.push_back(t);
}

int n;

lct::node *rt[maxn], *etr[maxn];
void travel(int u = 0, int p = -1)
{
  rt[u] = lct::make_tree();
  if (p != -1) {
    etr[E[p].i] = rt[u];
    rt[u]->w = E[p].w;
    lct::join(rt[u], rt[E[p].v]);
  }
  for (int i = L[u]; i != -1; i = E[i].to)
    if (i != p) travel(E[i].v, i^1);
}

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int T = (scanf("%d", &T), T); T--; ) {
    scanf("%d", &n);
    graph_inti();
    for (int u, v, w, i = 0; i < n-1; i++) {
      scanf("%d%d%d", &u, &v, &w);
      u--, v--;
      graph_add(u, v, i, w);
      graph_add(v, u, i, w);
    }
    lct::init();
    travel();
    char op[10];
    for (int x, y; scanf("%s", op), op[0] != 'D'; ) {
      scanf("%d%d", &x, &y);
      if (op[0] == 'C') {
        etr[x-1]->w = y;
        access(etr[x-1]);
      }
      else {
        int ans;
        lct::access(rt[x-1]);
        lct::ask(rt[y-1], ans);
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}
