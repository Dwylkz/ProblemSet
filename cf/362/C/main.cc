#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int N = 5e3+10;
typedef map<int, int> Mii;

struct Bia {
  int s[N];
  void init() {
    memset(s, 0, sizeof(s));
  }
  void add(int x) {
    for (x++; x < N; x += -x&x) s[x]++;
  }
  int ask(int x) {
    int result = 0;
    for (x++; x; x -= -x&x) result += s[x];
    return result;
  }
};

struct Ft {
  struct Node {
    int l, r, sm;
    Node *ls, *rs;
  } s[N*N], *top;
  void init() {
    top = s;
  }
  Node *phi(int l, int r) {
    Node t = {l, r, 0}, *x = top++;
    *x = t;
    if (l < r) {
      int m = l+r>>1;
      x->ls = phi(l, m);
      x->rs = phi(m+1, r);
    }
    return x;
  }
  Node *insert(int k, Node *y) {
    Node *x = top++;
    *x = *y;
    x->sm++;
    if (x->l < x->r) {
      int m = x->l+x->r>>1;
      if (k <= m) x->ls = insert(k, y->ls);
      else x->rs = insert(k, y->rs);
    }
    return x;
  }
  int ask(int l, int r, Node *x, Node *y) {
    int result = 0;
    if (l <= x->l && x->r <= r) result = y->sm-x->sm;
    else {
      int m = x->l+x->r>>1;
      if (l <= m) result += ask(l, r, x->ls, y->ls);
      if (m < r) result += ask(l, r, x->rs, y->rs);
    }
    return result;
  }
};
typedef Ft::Node Node;

Ft zkl;
Mii m;
Node *rt[N];
int n, a[N];

int isort(int s[], int n) {
  int result = 0;
  for (int i = 1; i < n; i++) {
    int j = i;
    for ( ; j > 0 && a[j-1] > a[j]; ) {
      swap(a[j], a[j-1]);
      result++;
      j--;
    }
  }
  return result;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    int cnt = isort(a, n);
    zkl.init();
    rt[0] = zkl.phi(0, n);
    for (int i = 0; i < n; i++) rt[i+1] = zkl.insert(a[i], rt[i]);
#if 0
    printf("cnt=%d\n", cnt);
#endif
    m.clear();
    int result = 0;
    for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++) {
        int d = cnt
          -zkl.ask(a[i]+1, n, rt[0], rt[i])
          -zkl.ask(a[j]+1, n, rt[0], rt[j])
          +zkl.ask(a[j]+1, n, rt[0], rt[i])
          +zkl.ask(a[i]+1, n, rt[0], rt[j]);
        if (a[i] < a[j]) d += 2;
        else d -= 2;
        m[d]++;
      }
    printf("%d %d\n", m.begin()->first, m.begin()->second);
  }
  return 0;
}
