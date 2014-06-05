#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
const int N = 3e2+10;

int n, a[N];

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) 
      scanf("%d", a+i);
    int p = 0;
    if (a[p]) {
      putchar('P');
      a[p]--;
    }
    p++;
    while (p < n) {
      putchar('R');
      while (a[p-1] || a[p]) {
        if (a[p]) {
          putchar('P');
          a[p]--;
        }
        if (a[p-1] || a[p]) {
          putchar('L');
          if (a[p-1]) {
            putchar('P');
            a[p-1]--;
          }
          putchar('R');
        }
      }
      p++;
    }
    puts("");
  }
  return 0;
}
