#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 25e4+10;

template<int N, int M> struct sam_t {
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
  int go(char *k) {
    node *x = s;
    int l = 0, t = 0;
    for (char *i = k; *i; i++) {
      int j = *i-'a';
      for ( ; x && !x->s[j]; x? t = x->l: t = 0) x = x->p;
      if (x) {
        x = x->s[j];
        l = max(l, ++t);
      } else x = s;
    }
    return l;
  }
};

char s[N];
sam_t<N, 26> zkl;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%s", s); ) {
    int n = strlen(s);
    zkl.init();
    for (char *i = s; *i; i++) zkl.put(*i-'a');
    scanf("%s", s);
    printf("%d\n", zkl.go(s));
  }
  return 0;
}
