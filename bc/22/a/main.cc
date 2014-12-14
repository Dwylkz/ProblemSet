#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
#include <bitset>

using namespace std;

int n;

int main()
{
  int kase;
  scanf("%d", &kase);
  while (kase--) {
    scanf("%d", &n);
    for (int i = 32; i > 0; i--)
      if (n>>(i-1)&1) {
        int b[32];
        for (int j = 0; j < i; j++)
          b[j] = n>>j&1;
        reverse(b, b+i);
        n = 0;
        for (int j = 0; j < i; j++)
          n |= b[j]<<j;
        break;
      }
    printf("%d\n", n);
  }
  return 0;
}
