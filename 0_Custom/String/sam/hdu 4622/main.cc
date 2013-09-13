#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2e3+10;
const int M = 26;

// Suffix automaton: Two states, either disjoined or one is another's proper subset.
// JJ burst sky.
struct sam_t {
  static const int n = N<<1;
  struct node {
    node *s[M], *p;
    int l;
    int range() {
      return l-(p? p->l: 0);
    }
  } s[n], *top, *back;
  void init() {
    dist = 0;
    top = s;
    back = make(0);
  }
  node *make(int l, int b = 0) {
    memset(top, 0, sizeof(node));
    top->l = l;
    return top++;
  }
  int dist;
  void put(int k) {
    node *x = make(back->l+1, 1), *y = back;
    back = x;
    for ( ; y && !y->s[k]; y = y->p) y->s[k] = x;
    if (!y) {
      x->p = s;
      dist += x->range();
    } else {
      node *w = y->s[k];
      if (w->l == y->l+1) {
        x->p = w;
        dist += x->range();
      } else {
        node *z = make(0);
        dist -= w->range();
        *z = *w;
        z->l = y->l+1;
        x->p = w->p = z;
        dist += x->range()+w->range()+z->range();
        for ( ; y && y->s[k] == w; y = y->p) y->s[k] = z;
      }
    }
  }
};

char s[N];
sam_t zkl;
int ans[N][N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
      zkl.init();
      for (char *j = s+i; *j; j++) {
        zkl.put(*j-'a');
        ans[i+1][j-s+1] = zkl.dist;
      }
    }
    int q;
    scanf("%d", &q);
    for ( ; q--; ) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", ans[l][r]);
    }
  }
  return 0;
}
