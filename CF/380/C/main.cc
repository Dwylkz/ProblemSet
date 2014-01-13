#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1<<20;
#define _l(x) x<<1
#define _r(x) x<<1|1

char s[N];
int m;

struct Node {
  int mx, lb, rb;
  friend Node operator + (Node lhs, Node rhs) {
    Node ret;
    ret.mx = min(lhs.rb, rhs.lb);
    ret.lb = lhs.lb+rhs.lb-ret.mx;
    ret.rb = lhs.rb+rhs.rb-ret.mx;
    ret.mx = ret.mx*2+lhs.mx+rhs.mx;
    return ret;
  }
} t[N<<1];
Node ask(int l, int r, int lb = 1, int rb = N, int x = 1) {
  if (l <= lb && rb <= r) return t[x];
  int m = lb+rb>>1;
  Node ret = {};
  if (l <= m) ret = ask(l, r, lb, m, _l(x))+ret;
  if (m < r) ret = ret+ask(l, r, m+1, rb, _r(x));
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%s", s); ) {
    int n = strlen(s);
    for (int i = 0; i < n; i++)
      t[i+N] = (Node){0, s[i] == ')', s[i] == '('};
    for (int i = N-1; i; i--) t[i] = t[_l(i)]+t[_r(i)];
    scanf("%d", &m);
    while (m--) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", ask(l, r).mx);
    }
  }
  return 0;
}
