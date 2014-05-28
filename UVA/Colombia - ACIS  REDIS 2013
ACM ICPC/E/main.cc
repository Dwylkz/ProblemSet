#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int N = 1e6+10;

struct word_t {
  string w, s;
  word_t(string _w = "") {
    s = w = _w;
    if (s.length() > 2) sort(s.begin()+1, s.end()-1);
  }
  friend bool operator < (const word_t &lhs, const word_t &rhs) {
    return lhs.s < rhs.s;
  }
};

char b[N];
set<word_t> d;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T), gets(b);
  for ( ; T--; ) {
    gets(b);
    d.clear();
    for (char *i = b, *s; s = strsep(&i, " "); ) {
      if (d.count(word_t(s))) {
        if (d.find(word_t(s))->w > string(s)) {
          d.erase(word_t(s));
          d.insert(word_t(s));
        }
      } else d.insert(word_t(s));
    }
    gets(b);
    int space = 0;
    for (char *i = b, *s; s = strsep(&i, " "); ) {
      if (space) putchar(' ');
      space = 1;
      if (d.count(word_t(s))) printf("%s", d.find(word_t(s))->w.data());
      else printf("%s", s);
    }
    puts("");
  }
  return 0;
}
