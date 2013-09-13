#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e2+10;
const int M = 4;
const int mod = 1e5;

template<class T, int n, int m> struct aca_t {
  struct node {
    node *s[m], *p;
    int ac;
  } s[n], *top, *rt, *q[n];
  void init() {
    memset(top = s, 0, sizeof(s));
    rt = top++;
  }
  void put(T *k, int l, int ac) {
    node *x = rt;
    for (int i = 0; i < l; i++) {
      if (!x->s[k[i]]) x->s[k[i]] = top++;
      x = x->s[k[i]];
    }
    x->ac = ac;
  }
  void link() {
    int l = 0;
    for (int i = 0; i < m; i++)
      if (rt->s[i]) (q[l++] = rt->s[i])->p = rt;
      else rt->s[i] = rt;
    for (int h = 0; h < l; h++)
      for (int i = 0; i < m; i++)
        if (q[h]->s[i]) {
          (q[l++] = q[h]->s[i])->p = q[h]->p->s[i];
          q[h]->s[i]->ac |= q[h]->s[i]->p->ac;
        } else q[h]->s[i] = q[h]->p->s[i];
  }
  void tom(int mt[][n]) {
    for (node *x = s; x < top; x++)
      for (int i = 0; i < m; i++)
        if (!x->s[i]->ac) mt[x-s][x->s[i]-s] = 1;
  }
};

int n, m;
char b[N];
aca_t<char, N, M> zkl;

int mt[N][N], r, ans[N][N];
void mul(int c[][N], int a[][N], int b[][N]) {
  int t[N][N];
  for (int i = 0; i < r; i++)
    for (int j = 0; j < r; j++)
      for (int k = t[i][j] = 0; k < r; k++)
        t[i][j] += 1LL*a[i][k]*b[k][j]%mod;
  memcpy(c, t, sizeof(t));
}
void qmod(int b) {
  int a[N][N];
  memset(ans, 0, sizeof(ans));
  memcpy(a, mt, sizeof(mt));
  for (int i = 0; i < r; i++) ans[i][i] = 1;
  for ( ; b; b >>= 1, mul(a, a, a))
    if (b&1) mul(ans, a, ans);
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &m, &n); ) {
    zkl.init();
    b[0] = 0, zkl.put(b, 1, 0);
    b[0] = 1, zkl.put(b, 1, 0);
    b[0] = 2, zkl.put(b, 1, 0);
    b[0] = 3, zkl.put(b, 1, 0);
    for ( ; m--; ) {
      scanf("%s", b);
      int l = strlen(b);
      for (int i = 0; i < l; i++)
        if (b[i] == 'A') b[i] = 0;
        else if (b[i] == 'C') b[i] = 1;
        else if (b[i] == 'G') b[i] = 2;
        else b[i] = 3;
      zkl.put(b, l, 1);
    }
    zkl.link();
    memset(mt, 0, sizeof(mt));
    zkl.tom(mt);
    r = zkl.top-zkl.s;
    qmod(n);
    int rv = 0;
    for (int i = 0; i < r; i++) rv = (rv+ans[0][i])%mod;
    printf("%d\n", rv);
  }
  return 0;
}
