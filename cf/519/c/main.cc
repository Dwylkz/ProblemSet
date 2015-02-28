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

int n, m;

int Calc(int n, int m)
{
  int res = 0;
  for (int i = 1; i <= n; i++) {
    int dn = min(i, m/2);
    int tn = n-dn, tm = m-2*dn;
    int dm = min(tm, tn/2);
    res = max(res, dn+dm);
  }
  return res;
}

int main()
{
  scanf("%d%d", &n, &m);
  printf("%d\n", max(Calc(n, m), Calc(m, n)));
  return 0;
}
