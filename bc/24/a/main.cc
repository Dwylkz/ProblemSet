#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

bool IsPrime(int x)
{
  for (int i = 2; i*i <= x; i++)
    if (x%i == 0)
      return false;
  return true;
}

int n;

int main()
{
  while (~scanf("%d", &n)) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      if (IsPrime(x))
        sum += x;
    }
    printf("%d\n", sum);
  }
  return 0;
}
