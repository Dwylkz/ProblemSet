#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5e3+10;

int n, a[N];

int DivideAndConquer(int* a, int lower, int upper, int base = 0)
{
  int minval = *min_element(a+lower, a+upper);
  int lval = minval-base;
  for (int i = lower; i < upper; i++) {
    int j = i;
    while (j < upper && a[j] != minval)
      j++;
    lval += DivideAndConquer(a, i, j, minval);
    i = j;
  }
  return min(lval, upper-lower);
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  printf("%d\n", DivideAndConquer(a, 0, n));
  return 0;
}
