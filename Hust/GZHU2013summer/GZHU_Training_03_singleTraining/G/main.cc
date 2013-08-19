#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 5e4 + 10;
typedef long long LL;

int l[maxn], F[maxn], n;

int calc(int n)
{
  int sum = 0, p = n, i;
  for (i = 1; i*i <= n; i++) {
    sum += n/i-1;
    sum += (p-n/i)*(i-2);
    p = n/i;
  }
  if ((i-1)*(i-1) != n) sum += (p-(n/i))*(i-2);
  return sum;
}

void test()
{
  int mx = 100;
  for (int i = 2; i < mx; i++) {
    l[i] = 0;
    for (int j = 1; j*j <= i; j++) {
      if (i % j == 0) {
        l[i]++;
        if (j != 1 && j*j != i) l[i]++;
      }
    }
  }
  F[0] = l[0] = 0;
  for (int i = 1; i < mx; i++) {
    F[i] = F[i-1] + l[i];
#if 1
    printf("%d: %d == %d?\n", i, F[i], calc(i));
#endif
  }
} 

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  test();
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d", &n);
    printf("%d\n", calc(n));
  }
  return 0;
}
