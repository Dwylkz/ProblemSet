#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;
const int inf = 0x3f3f3f3f;

template<int N, int M> struct sam_t {
  static const int n = N*2;
  struct node {
    node *s[M], *p;
    int l;
  } s[n], *top, *back;
  node *make(int l) {
    memset(top, 0, sizeof(node));
    top->l = l;
    return top++;
  }
  void init() {
    top = s;
    back = make(0);
  }
  void put(int k) {
    node *x = make(back->l+1), *y = back;
    back = x;
    for ( ; y && !y->s[k]; y = y->p) y->s[k] = x;
    if (!y) x->p = s;
    else {
      node *w = y->s[k];
      if (w->l == y->l+1) x->p = w;
      else {
        node *z = make(0);
        *z = *w;
        z->l = y->l+1;
        x->p = w->p = z;
        for ( ; y && y->s[k] == w; y = y->p) y->s[k] = z;
      }
    }
  }
  vector<node*> e[n];
  node* q[n];
  int qt;
  void topo() {
    for (int i = 0; i < top-s; i++) {
      memset(f[i], 0, sizeof(f[i]));
      e[i].clear();
    }
    for (node *x = s+1; x < top; x++) e[x->p-s].push_back(x);
    qt = 0;
    q[qt++] = s;
    for (int h = 0; h < qt; h++)
      for (int i = 0; i < e[q[h]-s].size(); i++)
        q[qt++] = e[q[h]-s][i];
  }
  int f[n][11];
  void eat(char *k, int id) {
    node *x = s;
    int t = 0;
    for (char *i = k; *i; i++) {
      int j = *i-'a';
      for ( ; x && !x->s[j]; t = x? x->l: 0) x = x->p;
      if (x) {
        x = x->s[j];
        f[x-s][id] = max(f[x-s][id], ++t);
      } else x = s;
    }
  }
  int go(int m) {
    int rv = 0;
    for (int h = qt-1; h; h--) {
      int t = inf, k = q[h]-s, j = q[h]->p-s;
      for (int i = 0; i < m; i++) {
        t = min(t, f[k][i]);
        // remember to pass the match length to parents
        f[j][i] = max(f[j][i], min(f[k][i], q[h]->p->l));
      }
      rv = max(t, rv);
    }
    return rv;
  }
};

char s[N];
sam_t<N, 26> zkl;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  scanf("%s", s);
  zkl.init();
  for (char *i = s; *i; i++) zkl.put(*i-'a');
  zkl.topo();
  int id;
  for (id = 0; ~scanf("%s", s); id++) zkl.eat(s, id);
  if (!id) printf("%d\n", zkl.back->l);
  else printf("%d\n", zkl.go(id));
  return 0;
}
