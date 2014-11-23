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

LL GCD(LL a, LL b)
{
  if (b == 0)
    return a;
  return GCD(b, a%b);
}

void Reduce(LL& x, int& f2, int& f3)
{
  while (x%2 == 0) {
    x /= 2;
    f2++;
  }
  while (x%3 == 0) {
    x /= 3;
    f3++;
  }
}

void Set(int* f1, int* f2)
{
  if (f1[1] > f2[1])
    swap(f1, f2);
  int d = f2[1]-f1[1];
  int d1 = min(f1[0], d);
  f1[0] -= d1;
  d -= d1;
  f2[0] += d;
}

void Trans(int* f, LL& a, LL& b)
{
  for (int i = 0; i < f[1]; i++)
    if (a%3 == 0)
      a = a/3*2;
    else
      b = b/3*2;
  for (int i = 0; i < f[0]; i++)
    if (a%2 == 0)
      a /= 2;
    else
      b /= 2;
}

LL a1, b1, a2, b2;

int main()
{
  cin >> a1 >> b1 >> a2 >> b2;
  LL s1 = a1*b1;
  LL s2 = a2*b2;
  LL gcd = GCD(s1, s2);
  LL r1 = s1/gcd;
  int f1[2] = {0, 0};
  Reduce(r1, f1[0], f1[1]);
  LL r2 = s2/gcd;
  int f2[2] = {0, 0};
  Reduce(r2, f2[0], f2[1]);
  if (r1 > 1 || r2 > 1) {
    cout << "-1" << endl;
    return 0;
  }
  Set(f1, f2);
  Trans(f1, a1, b1);
  Trans(f2, a2, b2);
  cout << f1[0]+f1[1]+f2[0]+f2[1] << endl;
  cout << a1 << " " << b1 << endl;
  cout << a2 << " " << b2 << endl;
  return 0;
}
