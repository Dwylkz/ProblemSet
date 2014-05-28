#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e6+10;

namespace trie {
  struct node {
    node *s[32];
    int sz;
  } pool[N], *top;
  void init() {
    top = pool;
  }
  node *make() {
    node t = {0};
    *top = t;
    return top++;
  }
  void push(node *x, char *s) {
    x->sz++;
    for ( ; *s; s++) {
      int k = *s-'a';
      if (!x->s[k]) x->s[k] = make();
      x = x->s[k];
      x->sz++;
    }
  }
}
using namespace trie;

char b[N];
node *rt;
int n, ans;

int ask(node *x, char *s) {
  int rv = 0;
  for ( ; *s; s++) {
    if (x->sz < 2) break;
    int k = *s-'a';
    x = x->s[k];
    rv++;
  }
  return rv;
}

void solve(int n) {
  if (!n) return ;
  scanf("%s", b);
  string t = b;
  push(rt, b);
  solve(n-1);
  ans += ask(rt, (char*)t.data());
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d", &n);
    init();
    rt = make();
    ans = 0;
    solve(n);
    printf("%d\n", ans);
  }
  return 0;
}
