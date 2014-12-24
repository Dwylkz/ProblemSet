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

typedef long long LL;

const int N = 90+5;

LL p, q, a[N];
int n;

LL GCD(LL p, LL q)
{
  return q? GCD(q, p%q): p;
}

bool IsValid(LL p, LL q, LL i)
{
  if (i == n)
    return (p == 1 && q == 0);
  if (q == 0)
    return false;
  LL gcd = GCD(p, q);
  p /= gcd;
  q /= gcd;
  if (p/q < a[i])
    return false;
  return IsValid(q, q*(p/q-a[i])+p%q, i+1);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin >> p >> q;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  puts(IsValid(p, q, 0)? "YES": "NO");
  return 0;
}
