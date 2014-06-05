#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int a, b;

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &a, &b); ) {
    int c = a;
    while (a >= b) {
      c += a/b;
      a = a/b+a%b;
    } 
    printf("%d\n", c);
  }
  return 0;
}
