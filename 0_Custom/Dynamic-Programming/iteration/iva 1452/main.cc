#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int n, m;

void show() {
  int f = 0;
  for (int i = 2; i <= n; i++) {
    f = (f+m)%i;
    printf(" %d", f+1);
  }
  puts("");
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d%d", &n, &m);
    int f = 0;
    for (int i = 2; i <= n; i++) {
      f = (f+m)%i;
      if (i > n-3) {
        if (i > n-2) putchar(' ');
        printf("%d", f+1);
      }
    }
    puts("");
#if 1
    show();
#endif
    break;
  }
  return 0;
}
