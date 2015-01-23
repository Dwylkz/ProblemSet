#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int N = 1e3+5;
const int K = 1e2+5;

int Add(int a, int b, int c)
{
  return (a+b)%c;
}

int Mul(int a, int b, int c)
{
  return 1ll*a*b%c;
}

int n, k, m, f[N][K];

int main()
{
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1; i < 10; i++)
    f[1][i%k]++;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j < k; j++)
      for (int o = 0; o < 10; o++) {
        int next = Add(Mul(10, j, k), o, k);
        f[i][next] = Add(f[i][next], f[i-1][j], m);
      }
  for (int i = 1; i <= n; i++)
    for (int j = 2; j < k; j++)
      f[i][j] = Add(f[i][j], f[i][j-1], m);
  if (n == 1) {
    printf("%d\n", f[1][0]);
    return 0;
  }
  int res = f[n-1][k-1];
  for (int i = 2; i < n; i++)
    res = Add(res, Mul(f[n-i][k-1], f[i][0], m), m);
  res = Add(res, f[n][0], m);
  printf("%d\n", res);
  return 0;
}
