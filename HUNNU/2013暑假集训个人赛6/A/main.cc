#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int x, y, z;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d%d%d", &x, &y, &z);
    double s = (x+y)/3.0;
    printf("%.0f\n", z*(x-s)/s);
  }
  return 0;
}
