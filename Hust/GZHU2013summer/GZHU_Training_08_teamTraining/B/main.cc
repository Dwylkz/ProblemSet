#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e7;

char b[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    int a, b;
    scanf("%X%X", &a, &b);
    getchar();
    for (int c; (c = getchar()) && c != '\n'; )
      if (c != ' ') {
        char lhs[10], rhs[10];
        if (c == '8') {
          getchar();
          scanf("%s%s", lhs, rhs);
          if (lhs[0] == 'A') a += b;
          else b += a;
        } else {
          getchar();
          scanf("%s", lhs);
          if (lhs[0] == 'A') a += a;
          else b += b;
        }
      }
    printf("%X %X\n", a, b);
  }
  return 0;
}
