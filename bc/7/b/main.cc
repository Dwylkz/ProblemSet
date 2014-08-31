#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
#include <cmath>

using namespace std;

const int N = 1e1+10;

int n;
double s[N][N], f[N], l[N];

void Init()
{
  f[0] = 1.0;
  for (int i = 1; i < N; i++)
    f[i] = f[i-1]*i;

  s[0][0] = 1;
  for (int i = 1; i < N; i++)
    for (int j = 1; j <= i; j++)
      s[i][j] = s[i-1][j-1]+(i-1)*s[i-1][j];

  for (int i = 1; i < N; i++)
    for (int j = 1; j <= i; j++)
      l[i] += j*s[i][j];

  for (int i = 1; i < N; i++)
    cout << i << ":" << l[i]/f[i] << endl;
}

int main()
{
  cin.sync_with_stdio(0);
  Init();
  while (cin >> n) {
    cout << n << endl;
  }
  return 0;
}
