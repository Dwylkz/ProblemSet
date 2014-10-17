#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int H = 320;
const int N = 2e5+1;
const int MOD = 1e9+7;

int r, g;

int G(int x)
{
  return x*(x+1)/2;
}

int memo[H][N];
int F(int h, int hi, int tr)
{
  if (tr < 0 || g-(G(h)-G(hi)-(r-tr)) < 0)
    return 0;

  if (hi == 0)
    return 1;

  if (memo[hi][tr] != -1)
    return memo[hi][tr];

  return memo[hi][tr] = (F(h, hi-1, tr)+F(h, hi-1, tr-hi))%MOD;
}

int main()
{
  scanf("%d%d", &r, &g);

  int lb = 1, rb = H;
  while (lb < rb) {
    int m = (lb+rb)>>1;
    memset(memo, -1, sizeof(memo));
    if (F(m, m, r) > 0)
      lb = m+1;
    else
      rb = m;
  }
  memset(memo, -1, sizeof(memo));
  printf("%d\n", F(rb-1, rb-1, r));
  return 0;
}
