#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int git(int *a) {
  return a[0]*100+a[1]*10+a[2];
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int p[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  for ( ; ; ) {
    int a = git(p), b = git(p+3), c = git(p+6);
    if (a*2 == b && a*3 == c) printf("%d %d %d\n", a, b, c);
    if (!next_permutation(p, p+9)) break;
  }
  return 0;
}
