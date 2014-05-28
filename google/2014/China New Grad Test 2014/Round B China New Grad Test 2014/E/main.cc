#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e6+10;

char buff[N];

void get_buff() {
  char *i;
  for (i = buff; ~(*i = getchar()); i++) {}
  *i = 0;
}

struct dfs_t {
  char *c;
  void comment_free() {
    for ( ; *c; c++)
      if (*c == '/' && *(c+1) == '*') {
        c += 2;
        comment_free();
        c--;
      } else if (*c == '*' && *(c+1) == '/') {
        c += 2;
        return ;
      }
  }
  void operator () (char *buff) {
    for (c = buff; *c; c++)
      if (*c == '/' && *(c+1) == '*') {
        c += 2;
        comment_free();
        c--;
      } else putchar(*c);
  }
} parse;

int main() {
#if 1
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
#endif
  get_buff();
  puts("Case #1:");
  parse(buff);
  return 0;
}
