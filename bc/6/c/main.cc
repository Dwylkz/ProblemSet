#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;
const int M = 1e9+7;

int n, k;

int Phi(int n)
{
  int ret = n;
  for (int i = 2; i*i*1ll <= n; i++) {
    if (n%i)
      continue;

    while (n%i == 0)
      n /= i;

    ret = ret/i*(i-1);
  }
  if (n > 1)
    ret = ret/n*(n-1);
  return ret;
}

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n >> k) {
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }

    if (k == 2) {
      cout << 1 << endl;
      continue;
    }

    if (k > 2) {
      cout << 0 << endl;
      continue;
    }

    int res = 0;
    for (int i = 1; 1ll*i*i <= n; i++) {
      if (n%i)
        continue;

      int con = 2;
      if (i == n/i)
        con = 1;

      res = (res+1ll*con*Phi(i)*Phi(n/i)%M)%M;
    }

    cout << res << endl;
  }
  return 0;
}
