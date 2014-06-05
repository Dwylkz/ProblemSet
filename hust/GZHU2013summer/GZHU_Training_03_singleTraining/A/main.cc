#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long LL;

struct node {
  node *ls, *rs;
  string t;
} n[maxn], *t;
struct dlist {
  node *h, *o;
  void init()
  {
    t = n;
    h = o = new_node();
  }
  node *new_node()
  {
    *t = (node){0, 0, ""};
    return t++;
  }
  node *add_head()
  {
    h->ls = new_node();
    h->ls->rs = h;
    return h = h->ls;
  }
  node *add_tail()
  {
    o->rs = new_node();
    o->rs->ls = o;
    return o = o->rs;
  }
};

dlist d;
char s[maxn];

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%s", s); ) {
    d.init();
    node *x = d.h;
    for (char *i = s; *i; i++)
      if (*i == '[') {
        x = d.add_head();
      } else if (*i == ']') {
        x = d.add_tail();
      } else x->t += *i;
    for (x = d.h; x; x = x->rs) printf("%s", x->t.data());
    puts("");
  }
  return 0;
}
