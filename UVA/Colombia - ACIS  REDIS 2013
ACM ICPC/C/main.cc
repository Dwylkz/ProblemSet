#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6+10;

struct hex_t {
  int v[6], h;
  void locate(int c) {
    for (int i = 0; i < 6; i++)
      if (v[i] == c) {
        h = i;
        break;
      }
  }
  int left() {
    return v[(h-1+6)%6];
  }
  int right() {
    return v[(h+1)%6];
  }
  void input(char *i) {
    int j = 0;
    h = 0;
    for (char *c; c = strsep(&i, " "); j++)
      v[j] = *c-'0';
  }
  void show() {
    for (int i = 0; i < 6; i++)
      printf(" %d", v[i]);
    puts("");
  }
};

char b[N];
hex_t h[7];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; gets(b); ) {
    int yes = 0;
    h[0].input(b);
    for (int i = 1; i < 7; i++) {
      gets(b);
      h[i].input(b);
    }
#if 0
    for (int i = 0; i < 7; i++) h[i].show();
#endif
    for (int i = 0; i < 7; i++) {
      int p[6];
      for (int j = 0, k = 0; j < 7; j++)
        if (i != j) p[k++] = j;
      for ( ; ; ) {
        int flag = 1;
        h[p[0]].locate(h[i].v[0]);
        for (int k = 1; k < 6; k++) {
          h[p[k]].locate(h[i].v[k]);
          if (h[p[k-1]].left() != h[p[k]].right()) {
            flag = 0;
            break;
          }
        }
        if (flag && h[p[5]].left() == h[p[0]].right()) {
          yes = 1;
          break;
        }
#if 0
        for (int i = 0; i < 6; i++) printf(" %d", p[i]);
        puts("");
#endif
        if (!next_permutation(p, p+6)) break;
      }
    }
    puts(yes? "YES": "NO");
  }
  return 0;
}
