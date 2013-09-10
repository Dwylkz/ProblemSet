#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 6+10;
const int M = 2;

template<class T> struct aca_t {
  enum {n = N, m = M};
  struct node {
    node *s[m], *p;
    int ac;
  } s[n], *top, *rt, *q[n];
  void init() {
    memset(top = s, 0, sizeof(s));
    rt = top++;
  }
  void put(T *k, int l) {
    node *x = rt;
    for (int i = 0; i < l; i++) {
      if (!x->s[k[i]]) x->s[k[i]] = top++;
      x = x->s[k[i]];
    }
    x->ac = 1;
  }
  void link() {
    int l = 0;
    for (int i = 0; i < m; i++)
      if (rt->s[i]) (q[l++] = rt->s[i])->p = rt;
      else rt->s[i] = rt;
    for (int h = 0; h < l; h++)
      for (int i = 0; i < m; i++)
        if (q[h]->s[i]) (q[l++] = q[h]->s[i])->p = q[h]->p->s[i];
        else q[h]->s[i] = q[h]->p->s[i];
  }
  void tom(int mt[n][n]) {
    for (node *x = s; x < top; x++)
      for (int i = 0; i < m; i++) {
        int k = x-s, j = x->s[i]-s;
        if (!x->s[i]->ac) mt[k][j] = 1;
      }
  }
};

int n, m;
aca_t<int> zkl;

int mt[N][N], r, ans[N][N];
void mul(int c[N][N], int a[N][N], int b[N][N], int m) {
  int t[N][N];
  for (int i = 0; i < r; i++)
    for (int j = 0; j < r; j++)
      for (int k = t[i][j] = 0; k < r; k++)
        t[i][j] = (t[i][j]+a[i][k]*b[k][j])%m;
  memcpy(c, t, sizeof(t));
}
void qmod(int b, int c) {
  int a[N][N];
  memset(ans, 0, sizeof(ans));
  memcpy(a, mt, sizeof(mt));
  for (int i = 0; i < r; i++) ans[i][i] = 1;
  for ( ; b; b >>= 1, mul(a, a, a, c))
    if (b&1) mul(ans, a, ans, c);
}
int qmod(int a, int b, int c, int rv = 1) {
  for ( ; b; b >>= 1, a = (a*a)%c)
    if (b&1) rv = (rv*a)%c;
  return rv;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int f[] = {0, 0, 0}, g[] = {0, 1, 0};
  zkl.init();
  zkl.put(f, 3), zkl.put(g, 3);
  zkl.link();
  zkl.tom(mt), r = zkl.top-zkl.s;
  for ( ; ~scanf("%d%d", &n, &m); ) {
    qmod(n, m);
    int rv = 0;
    for (int i = 0; i < 6; i++) rv = (rv+ans[0][i])%m;
    printf("%d\n", rv);
  }
  return 0;
}
