#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e6+10;

char l[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%[^\n]\n", l); ) {
    int rv = 0, f = 0;
    for (char *i = l, *s; s = strsep(&i, " "); ) {
      int v = atoi(s);
      if (f+v < v) f = v;
      else f += v;
      if (f < 0) f = 0;
      rv = max(rv, f);
    }
    printf("%d\n", rv);
  }
  return 0;
}
