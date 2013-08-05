#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;

struct seg_node {
  seg_node *ls, *rs;
  int l, r, c[3], tag;
  int mid()
  {
    return l + r >> 1;
  }
  int len()
  {
    return r - l + 1;
  }
  void set(int _tag)
  {
    tag = _tag;
    for (int i = 0; i < 3; i++)
      c[i] = (i == tag) * len();
  }
  void push()
  {
    if (tag != -1) {
      ls->set(tag);
      rs->set(tag);
    }
    tag = -1;
  }
  void update()
  {
    for (int i = 0; i < 3; i++)
      c[i] = ls->c[i] + rs->c[i];
  }
} seg[maxn<<1], *top;
void build(seg_node *x, int l, int r)
{
  *x = (seg_node){0, 0, l, r, {r-l+1, 0, 0}, -1};
  if (l == r) return ;
  build(x->ls = ++top, l, x->mid());
  build(x->rs = ++top, x->mid()+1, r);
}
void cover(seg_node *x, int l, int r, int c)
{
  if (l <= x->l && x->r <= r)
    x->set(c);
  else {
    x->push();
    if (l <= x->mid()) cover(x->ls, l, r, c);
    if (x->mid() < r) cover(x->rs, l, r, c);
    x->update();
  }
}
int ask(seg_node *x, int l, int r, int c)
{
  int rv = 0;
  if (l <= x->l && x->r <= r)
    rv = x->c[c];
  else {
    x->push();
    if (l <= x->mid()) rv += ask(x->ls, l, r, c);
    if (x->mid() < r) rv += ask(x->rs, l, r, c);
    x->update();
  }
  return rv;
}

int a, t;

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &a, &t); ) {
    build(top = seg, 0, t-1);
    for ( ; a--; ) {
      char op[2];
      int d1, d2, c = 2;
      scanf("%1s%d%d", op, &d1, &d2);
      d1--, d2--;
      if (d1 > d2) {
        c = 1;
        swap(d1, d2);
      }
      if (op[0] == 'F') cover(seg, d1, d2, c);
      else printf("%d %d %d\n",
          ask(seg, d1, d2, 1),
          ask(seg, d1, d2, 0),
          ask(seg, d1, d2, 2));
    }
  }
  return 0;
}
