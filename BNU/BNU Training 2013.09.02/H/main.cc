#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
typedef map<int, int> mii_t;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    int n, sp = -1;
    scanf("%d", &n);
    mii_t ms, mb;
    for ( ; n--; ) {
      char op[10];
      int s, p;
      scanf("%s%d%*s%*s%d", op, &s, &p);
      if (*op == 's') {
        ms[p] += s;
      } else {
        mb[p] += s;
      }
      for ( ; ms.size() && mb.size()
          && ms.begin()->first <= mb.rbegin()->first; ) {
        sp = ms.begin()->first;
        int d = min(ms.begin()->second, mb.rbegin()->second);
        ms.begin()->second -= d;
        mb.rbegin()->second -= d;
        if (!ms.begin()->second) ms.erase(ms.begin());
        mii_t::iterator i = mb.end();
        if (!(--i)->second) mb.erase(i);
      }
      char a[10] = "-", b[10] = "-", c[10] = "-";
      if (ms.size()) sprintf(a, "%d", ms.begin()->first);
      if (mb.size()) sprintf(b, "%d", mb.rbegin()->first);
      if (~sp) sprintf(c, "%d", sp);
      printf("%s %s %s\n", a, b, c);
    }
  }
  return 0;
}
