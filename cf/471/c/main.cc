#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long LL;

LL n;

LL F(LL n)
{
  return (n+1)*n/2*3-n;
}

LL G(LL n)
{
  return F(n)-(n > 2? 5: 0);
}

int main()
{
  cin.sync_with_stdio(0);

  cin >> n;

  int ret = 0;
  for (LL i = 1; F(i) <= n; i++) {
    if ((n-F(i))%3 != 0)
      continue;
    ret++;
  }

  cout << ret << endl;
  return 0;
}
