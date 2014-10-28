#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

const int N = 2e5+5;
const int MOD = 1e9+7;

int Add(int a, int b)
{
  return (a+b)%MOD;
}

int r, g;

int G(int x)
{
  return x*(x+1)/2;
}

int H(int n)
{
  int ret = 1;
  while (G(ret) <= n)
    ret++;
  return ret;
}

int memo[2][N];
int F(int h)
{
  for (int i = 0; i < 2; i++)
    for (int j = 0; j <= r; j++)
      memo[i][j] = 0;

  int *p = memo[0], *q = memo[1];
  p[0] = 1;
  for (int i = 1; i < h; i++) {
    for (int j = 0; j <= r; j++) {
      if (G(i)-j > g)
        continue;

      q[j] = Add(q[j], p[j]);
      if (j >= i)
        q[j] = Add(q[j], p[j-i]);
    }
    swap(p, q);
    for (int j = 0; j <= r; j++)
      q[j] = 0;
  }
  return accumulate(p, p+r+1, 0, Add);
}

int main()
{
  scanf("%d%d", &r, &g);
  printf("%d\n", F(H(r+g)));
  return 0;
}
