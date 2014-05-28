#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
const int mod = 10007;
typedef long long LL;

void mt_set_id(int x[4][4])
{
  memset(x, 0, sizeof(x));
  for (int i = 0; i < 4; i++) x[i][i] = 1;
}
bool mt_is_id(int x[4][4])
{
  for (int i = 0; i < 4; i++)
    if (x[i][i] != 1) return 0;
  return 1;
}
void mt_mul(int t[4][4], int lhs[4][4], int rhs[4][4])
{
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      for (int k = t[i][j] = 0; k < 4; k++)
        t[i][j] = (t[i][j]+lhs[i][k]*rhs[k][j])%mod;
}
#define mt_ma(x, lhs, rhs) {\
  int __##x[4][4];\
  mt_mul(__##x, lhs, rhs);\
  memcpy(x, __##x, sizeof(__##x));\
}

struct node {
  node *ls, *rs;
  int l, r, s[4][4], tag[4][4];
  int mid()
  {
    return l+r>>1;
  }
  int len()
  {
    return r-l+1;
  }
  void set(int m[4][4])
  {
    mt_ma(tag, tag, m);
    mt_ma(s, m, s);
  }
  void push()
  {
    if (mt_is_id(tag)) return ;
    ls->set(tag);
    rs->set(tag);
    mt_set_id(tag);
  }
  void update()
  {
    for (int i = 0; i < 3; i++)
      s[i][0] = ls->s[i][0] + rs->s[i][0];
  }
} seg[maxn<<1], *top;
void build(int l, int r, node *x = seg)
{
  *x = (node){0, 0, l, r,
    {
      0, 0, 0, 0,
      0, 0, 0, 0,
      0, 0, 0, 0,
      r-l+1, 0, 0, 0
    },
    {
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, 1, 0,
      0, 0, 0, 1
    }
  };
#if 0
  fprintf(stderr, "node (%d, %d)\n", l, r);
  for (int i = 0; i < 4; i++)
    fprintf(stderr, "\t%d\n", x->s[i][0]);
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      fprintf(stderr, "\t%d%c", x->tag[i][j], j<3? ' ': '\n');
#endif
  if (l == r) return ;
  build(l, x->mid(), x->ls = ++top);
  build(x->mid()+1, r, x->rs = ++top);
}
void cover(int l, int r, int c[4][4], node *x = seg)
{
  if (l <= x->l && x->r <= r) x->set(c);
  else {
    x->push();
    if (l <= x->mid()) cover(l, r, c, x->ls);
    if (x->mid() < r) cover(l, r, c, x->rs);
    x->update();
  }
}
int ask(int l, int r, int p, node *x = seg)
{
  int ans = 0;
  if (l <= x->l && x->r <= r) ans = x->s[p][0];
  else {
    x->push();
    if (l <= x->mid()) ans += ans + ask(l, r, p, x->ls);
    if (x->mid() < r) ans += ask(l, r, p, x->rs);
    x->update();
  }
  return ans%mod;
}

void op_make(int m[4][4], int op, int c)
{
  c %= mod;
  if (op == 1) {
    int t[4][4] = {
      1, 0, 0, c,
      2*c%mod, 1, 0, c*c%mod,
      3*c*c%mod, 3*c%mod, 1, c*c%mod*c%mod,
      0, 0, 0, 1
    };
    memcpy(m, t, sizeof(t));
  } else if (op == 2) {
    int t[4][4] = {
      c, 0, 0, 0,
      0, c*c%mod, 0, 0,
      0, 0, c*c%mod*c%mod, 0,
      0, 0, 0, 1
    };
    memcpy(m, t, sizeof(t));
  } else if (op == 3) {
    int t[4][4] = {
      0, 0, 0, c,
      0, 0, 0, c*c%mod,
      0, 0, 0, c*c%mod*c%mod,
      0, 0, 0, 1
    };
    memcpy(m, t, sizeof(t));
  }
#if 0
  puts("make");
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      printf("%4d%c", m[i][j], j<3? ' ': '\n');
  puts("/make");
#endif
}

int n, m;

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; scanf("%d%d", &n, &m), n || m; ) {
    build(0, n-1, top = seg);
    for ( ; m--; ) {
      int op, x, y, z, m[4][4];
      scanf("%d%d%d%d", &op, &x, &y, &z);
      if (op < 4) {
        op_make(m, op, z);
        cover(x-1, y-1, m);
#if 0
        for (int i = 0; i < n; i++)
          printf("%d%c", ask(i, i, 1), i<n-1? ' ': '\n');
#endif
      } else printf("%d\n", ask(x-1, y-1, z-1));
    }
  }
  return 0;
}
