#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3+10;
const int M = 26;

struct node {
  node *s[M];
  int sz;
} s[N*N], *top, *rt;
node *make() {
  memset(top, 0, sizeof(node));
  return top++;
}
void init() {
  top = s;
  rt = make();
}
void put(char *s) {
  node *x = rt;
  for ( ; *s; s++) {
    int k = *s-'a';
    x->sz++;
    if (!x->s[k]) x->s[k] = make();
    x = x->s[k];
  }
  x->sz++;
}
int ask(char *s) {
  int result = 0;
  node *x = rt;
  for ( ; *s; s++) {
    int k = *s-'a';
    x = x->s[k];
    result++;
    if (x->sz < 2) break;
  }
  return result;
}

int n;
char word[N][N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    init();
    for (int i = 0; i < n; i++) {
      scanf("%s", word[i]);
      put(word[i]);
    }
    for (int i = 0; i < n; i++) {
      int l = ask(word[i]);
      for (int j = 0; j < l; j++) putchar(word[i][j]);
      puts("");
    }
  }
  return 0;
}
