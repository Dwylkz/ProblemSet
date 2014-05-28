#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
using namespace std;
const int N = 1e3+10;
typedef map<string, string> mss_t;

char b[N], b1[N], b2[N];

void parse(mss_t &m) {
  for (char *s = b+1; *s && sscanf(s, "%[a-z]:%[-0-9],", b1, b2); ) {
    m[b1] = b2;
    s += strlen(b1)+1+strlen(b2)+1;
  }
#if 0
  puts(__func__);
  for (mss_t::iterator i = m.begin(); i != m.end(); i++)
    printf("\tget %s %s\n", i->first.data(), i->second.data());
#endif
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  getchar();
  for ( ; T--; ) {
    mss_t o, n;
    gets(b);
    parse(o);
    gets(b);
    parse(n);
    int p = 0, yes = 1;
    mss_t::iterator i;
    for (i = n.begin(); i != n.end(); i++)
      if (o.find(i->first) == o.end()) {
        if (p) putchar(',');
        else putchar('+');
        p = 1;
        yes = 0;
        printf("%s", i->first.data());
      }
    if (p) puts("");
    p = 0;
    for (i = o.begin(); i != o.end(); i++)
      if (n.find(i->first) == n.end()) {
        if (p) putchar(',');
        else putchar('-');
        p = 1;
        yes = 0;
        printf("%s", i->first.data());
      }
    if (p) puts("");
    p = 0;
    for (i = o.begin(); i != o.end(); i++)
      if (n.find(i->first) != n.end() && i->second != n[i->first]) {
        if (p) putchar(',');
        else putchar('*');
        p = 1;
        yes = 0;
        printf("%s", i->first.data());
      }
    if (p) puts("");
    if (yes) puts("No changes");
    puts("");
  }
  return 0;
}
