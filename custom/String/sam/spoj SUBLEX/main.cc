#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 9e4+10;
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
  node* q[n];
  int c[n];
  void topo() {
    for (int i = 0; i <= back->l; i++) c[i] = 0;
    for (int i = top-s-1; ~i; i--) c[s[i].l]++;
    for (int i = 1; i <= back->l; i++) c[i] += c[i-1];
    for (int i = top-s-1; ~i; i--) q[--c[s[i].l]] = s+i;
  }
  int e[n][M], ec[n], f[n];
  void go() {
    topo();
    for (int i = 0; i < top-s; i++) {
      f[i] = 1;
      ec[i] = 0;
    }
    for (int h = top-s-1; ~h; h--) {
      int u = q[h]-s;
      for (int i = 0; i < M; i++) {
        int v = q[h]->s[i]-s;
        if (q[h]->s[i]) {
          e[u][ec[u]++] = i;
          f[u] += f[v];
        }
      }
    }
  }
  void show() {
    for (int i = 0; i < top-s; i++) printf(" %ld", q[i]-s);
    puts("");
    for (node *x = s; x < top; x++) {
      printf("%2ld, p = %2ld, f = %2lld:", x-s, x->p? x->p-s: -1, f[x-s]);
      for (int i = 0; i < M; i++)
        if (x->s[i]) printf(" %c: %ld", i+'a', x->s[i]-s);
      puts("");
    }
  }
  char p[n];
  void ask(int k) {
    int l = 0;
    for (node *x = s; k; ) {
      int u = x-s;
      for (int i = 0; i < ec[u]; i++) {
        int ch = e[u][i], j = x->s[ch]-s;
        if (f[j] < k) k -= f[j];
        else {
          k--;
          p[l++] = ch+'a';
          x = x->s[ch];
          break;
        }
      }
    }
    p[l] = 0;
    puts(p);
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
  zkl.go();
  //     zkl.show();
  int q;
  scanf("%d", &q);
  for (int k; q--; ) {
    scanf("%d", &k);
    zkl.ask(k);
  }
  return 0;
}
