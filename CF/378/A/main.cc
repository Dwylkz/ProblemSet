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
    int w[3] = {0};
    for (int i = 1; i <= 6; i++)
      if (abs(a-i) < abs(b-i)) w[0]++;
      else if (abs(a-i) == abs(b-i)) w[1]++;
      else w[2]++;
    printf("%d %d %d\n", w[0], w[1], w[2]);
  }
  return 0;
}
