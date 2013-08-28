#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int N = 1e5+10;
typedef map<string, int> msi_t;
typedef msi_t::iterator msi_i;

char b[N];

char *c;
int parsei() {
  int rv = 1;
  if (isdigit(*c)) {
    int t = 0;
    for ( ; *c && isdigit(*c); c++) t = t*10+*c-'0';
    rv = t;
  }
  return rv;
}
msi_t *parse() {
  msi_t *mm = new msi_t();
  for ( ; *c; c++)
    if (*c == '(') {
      c++;
      msi_t *t = parse();
      int cnt = parsei();
      c--;
      for (msi_i i = t->begin(); i != t->end(); i++)
        (*mm)[i->first] += i->second*cnt;
      delete t;
    } else if (*c == ')') {
      c++;
      break;
    } else if (isalpha(*c)) {
      string t = "";
      t += *c++;
      for (int d = 1; *c && islower(*c) && d < 3; d++, c++) t += *c;
      int cnt = parsei();
      c--;
      (*mm)[t] += cnt;
    }
  return mm;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%s", b); ) {
    c = b;
    msi_t *m = parse();
    int b = 0;
    for (msi_i i = m->begin(); i != m->end(); i++) {
      if (b) putchar('+');
      b = 1;
      if (i->second > 1) printf("%d%s", i->second, i->first.data());
      else printf("%s", i->first.data());
    }
    puts("");
    delete m;
  }
  return 0;
}
