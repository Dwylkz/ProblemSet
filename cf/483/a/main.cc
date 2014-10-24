#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

LL Gcd(LL a, LL b)
{
  if (b == 0)
    return a;
  return Gcd(b, a%b);
}

LL l, r;

int main()
{
  cin.sync_with_stdio(0);
  cin >> l >> r;
  for (LL i = l; i <= r-2; i++) {
    if (Gcd(i, i+2) > 1) {
      cout << i << " " << i+1 << " " << i+2 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
