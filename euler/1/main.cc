#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int sum = 0;
  for (int i = 1; i < 1000; i++)
    if (i%3 == 0 || i%5 == 0) sum += i;
  printf("%d\n", sum);
  return 0;
}
