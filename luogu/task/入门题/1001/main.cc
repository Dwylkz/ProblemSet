#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int a, b; ~scanf("%d%d", &a, &b); ) {
    printf("%d\n", a+b);
  }
  return 0;
}
