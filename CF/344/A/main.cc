#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int n;
char m[10];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    char p[10];
    scanf("%s", p);
    int g = 1;
    for (int i = 1; i < n; i++) {
      scanf("%s", m);
      if (p[1] == m[0]) g++;
      strcpy(p, m);
    }
    printf("%d\n", g);
  }
  return 0;
}
