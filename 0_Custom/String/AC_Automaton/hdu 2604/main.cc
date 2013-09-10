#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 7+10;
const int M = 2;

template<class T> struct aca_t {
  enum {n = N, m = M};
  struct node {
    node *s[m], *p;
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
      for (int i = 0; i < m; i++)
        mt[x-s][x->s[i]-s] = 1;
  }
};

int n, m;
aca_t<int> zkl;

int mt[N][N], r, ans[N][N];
void init() {
  memset(ans, 0, sizeof(ans));
  for (int i = 0; i < r; i++) ans[i][i] = 1;
}
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
  memcpy(a, mt, sizeof(mt));
  for (init(); b; b >>= 1) {
    if (b&1) mul(ans, a, ans, c);
    mul(a, a, a, c);
  }
}
int qmod(int a, int b, int c, int rv = 1) {
  for ( ; b; b >>= 1) {
    if (b&1) rv = (rv*a)%c;
    a = (a*a)%c;
  }
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
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < r; j++)
      mt[i+r][j] = mt[i][j];
    mt[i+r][i+r] = 1;
  }
  r <<= 1;
  for ( ; ~scanf("%d%d", &n, &m); ) {
//     m = 101;
    qmod(n, m);
#if 1
    printf("tot = %d\n", qmod(2, n, m));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < r; j++) printf(" %d", ans[i][j]);
      puts("");
    }
#endif
    printf("%d\n", (m+qmod(2, n, m)-ans[r>>1][3]-ans[r>>1][5])%m);
  }
  return 0;
}
