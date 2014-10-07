#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;
const int N = 2e3+10;
const int M = 1e9+7;

int Add(int a, int b)
{
  return (a+b)%M;
}

int Mul(int a, int b)
{
  return 1ll*a*b%M;
}

int n, h, a[N];

int memo[N][N];
int MemDfs(int i, int l)
{
  if (i == -1)
    return l == 0;

  if (memo[i][l] != -1)
    return memo[i][l];

  if (l == a[i]) {
    int ret = MemDfs(i-1, l); // ##
    if (l > 0)
      ret = Add(ret, MemDfs(i-1, l-1)); // (#
    return memo[i][l] = ret;
  }

  if (l == a[i]-1) {
    int ret = Mul(MemDfs(i-1, l), l+1); // ()
    if (l+1 <= h)
      ret = Add(ret, Mul(MemDfs(i-1, l+1), l+1)); // #)
    return memo[i][l] = ret;
  }

  return memo[i][l] = 0;
}

int main()
{
  scanf("%d%d", &n, &h);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    a[i] = h-a[i];
  }
  memset(memo, -1, sizeof(memo));
  printf("%d\n", MemDfs(n-1, 0));
  return 0;
}
