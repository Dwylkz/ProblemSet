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

const int N = 5e3+5;

double f[N][N], ps[N];
int n, t, ts[N], sts[N];

int main()
{
  scanf("%d%d", &n, &t);
  for (int i = 1; i <= n; i++) {
    scanf("%lf%d", ps+i, ts+i);
    ps[i] /= 100.0;
    if (ts[i] == 1)
      ps[i] = 1.0;
  }
  for (int i = 1; i <= n; i++)
    sts[i] = sts[i-1]+ts[i];
  f[0][0] = 1.0;
  for (int i = 1; i <= t; i++) {
    for (int j = 0; j < n; j++) {
    }
  }
  double e = 0.0;
  for (int j = 1; j <= n; j++)
    e += f[t][j]*j;
  printf("%f\n", e);
  return 0;
}
