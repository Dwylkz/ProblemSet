#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int N = 512;

int n;
char b[N];

int lexer(char *s, vector<string> &tl) {
  for ( ; *s; s++)
    if (isspace(*s)) ;
    else if (*s == '$') {
      string t = "";
      for (t += *s++; isalnum(*s); s++) t += *s++;
      s--;
    } else if (*s == '=') {
    }
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T, f = 0;
  scanf("%d", &T);
  for ( ; T--; ) {
    if (f) puts("");
    f = 1;
    scanf("%d", &n);
    gets(b);
    map<string, string> env;
    bool end = 0;
    for ( ; n--; ) {
      vector<string> t;
      gets(b);
      if (!lexer(b, t) || end) continue;
      if (t.size() < 2) end = 1;
      else if (t.size() < 3) {
      } else {
      }
    }
  }
  return 0;
}
