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
static const int N = 1e5+10;
static const int S = 256+10;

int n;
long long a[N];

int main()
{
  while (scanf("%d", &n) && n != 0)
  {
    for (int i = 0; i < n; i++)
    {
      scanf("%lld", a+i);
    }
    long long sum = 0;
    for (int i = n-1; i > 0; i--)
    {
      sum += a[i];
      for (int j = 0; j < i; j++)
      {
        a[j] += a[i];
      }
    }
    cout << sum+a[0] << endl;
  }
  return 0;
}
