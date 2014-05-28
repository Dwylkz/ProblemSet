#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e6+10;

char b[N], a[N], c[N], d[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; gets(b), strcmp(b, "END"); ) {
    if (sscanf(b, "\"%[A-Z ]\" %[A-Z ]", a, c) == 2
        && strlen(b) == strlen(a)+strlen(c)+3) {
      if (!strcmp(a, c)) printf("Quine(%s)\n", a);
      else puts("not a quine");
    } else puts("not a quine");
  }
  return 0;
}
