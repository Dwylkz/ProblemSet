#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 25e4+10;

template<class T, int N, int M> struct sam_t {
  static const int n = N*3;
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
    node *x = make(back->l+1), *y = back, *r = make(-x->l);
    r->p = back = x;
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
  int f[n], g[n];
  vector<node*> e[n];
  node *q[n];
  void go() {
    for (int i = 0; i < top-s; i++) {
      e[i].clear();
      g[i] = 0;
    }
    for (node *x = s+1; x < top; x++) e[x->p-s].push_back(x);
    for (int i = 0; i <= back->l; i++) f[i] = 0;
    int qt = 0;
    q[qt++] = s;
    for (int h = 0; h < qt; h++)
      for (int i = 0; i < e[q[h]-s].size(); i++)
        q[qt++] = e[q[h]-s][i];
    for (int h = qt-1; h; h--) {
      node *x = q[h];
      g[x-s] += (x->l < 0);
      if (x->l >= 0) f[x->l] = max(f[x->l], g[x-s]);
      g[x->p-s] += g[x-s];
    }
  }
};

char s[N];
sam_t<char, N, 26> zkl;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%s", s); ) {
    int n = strlen(s);
    zkl.init();
    for (char *i = s; *i; i++) zkl.put(*i-'a');
    zkl.go();
    for (int i = 1; i <= n; i++) printf("%d\n", zkl.f[i]);
  }
  return 0;
}
