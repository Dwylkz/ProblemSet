#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int N = 1e5+10;
const double EPS = 1e-1;
typedef long long LL;
typedef vector<int> VI;

int n, m, a[N], b[N];

LL look(int x)
{
  LL res = 0;
  for (int i = 0; i < n; i++)
    if (a[i] < x)
      res += x-a[i];
  for (int i = 0; i < m; i++)
    if (b[i] > x)
      res += b[i]-x;
  return res;
}

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < m; i++)
      cin >> b[i];

    LL res = 1e18;
    double lb = 1, rb = 1e9;
    while (lb < rb-EPS) {
      double len = (rb-lb)/3.0;
      double midl = lb+len, midr = rb-len;
      LL resl = look(floor(midl)), resr = look(ceil(midr));
      if (resl < resr)
        rb = midr;
      else
        lb = midl;
      res = min(res, min(resl, resr));
    }
    cout << res << endl;
  }
  return 0;
}
