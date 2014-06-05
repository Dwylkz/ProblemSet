#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 100+10;

char s[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    int c;
    scanf("%d", &c);
    getchar();
    gets(s);
    int n;
    scanf("%d", &n);
    printf("%d ", c);
    for (int i = 0, l = strlen(s), z = 0, p; i < n; i++) {
      scanf("%d", &p);
      z = ((z+p)%l+l)%l;
      putchar(s[z]);
    }
    puts("");
  }
  return 0;
}
