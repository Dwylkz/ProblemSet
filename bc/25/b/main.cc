#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

const int N = 50+5;
const int M = 1000000007;

int Add(int a, int b)
{
  return (a+b)%M;
}

int Mul(int a, int b)
{
  return 1ll*a*b%M;
}

int n, f[N][N], com[N][N];

int Func(int r, int c)
{
  int ret = 0;
  for (int i = 1; i <= r; i++) {
    int sub = 0;
    for (int j = 0; j <= i; j++)
      if (r-j > 0)
        sub = Add(sub, Mul(com[i][j], f[r-j][c]));
    ret = Add(ret, Mul(com[r][i], sub));
  }
  return ret;
}

int main()
{
  com[0][0] = 1;
  for (int i = 1; i < N; i++) {
    com[i][0] = 1;
    for (int j = 1; j < N; j++)
      com[i][j] = Add(com[i-1][j-1], com[i-1][j]);
  }
  for (int i = 1; i < N; i++)
    f[i][1] = f[1][i] = 1;
  for (int i = 2; i < N; i++) {
    f[i][i] = Func(i, i-1);
    for (int j = i+1; j < N; j++)
      f[i][j] = f[j][i] = Func(i, j-1);
  }
  // for (int i = 1; i < 5; i++)
  //   for (int j = 1; j < 5; j++)
  //     printf("%4d%c", f[i][j], j < 4? ' ': '\n');
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    printf("%d\n", f[n][m]);
  }
  return 0;
}
