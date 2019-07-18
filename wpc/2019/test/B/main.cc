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
#include <stdint.h>

using namespace std;

const int N = 1e5+10;

int a[N];

int main()
{
  int T, n, m;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d%d", &n, &m);
    int64_t r = 1;
    for (int i = 0; i < n; i++)
    {
      scanf("%d", a+i);
      r += a[i];
    }
    if (n == m)
    {
      cout << "Richman\n";
    }
    else
    {
      int64_t l = 0;
      while (l < r)
      {
        int64_t mid = (l+r)/2;
        int64_t remain = mid;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
          if (remain >= a[i])
          {
            remain -= a[i];
            res += 1;
          }
        }
        if (res > m)
        {
          r = mid;
        }
        else
        {
          l = mid+1;
        }
      }
      if (l == 0)
      {
        cout << "Impossible\n";
      }
      else
      {
        cout << l-1 << "\n";
      }
    }
  }
  return 0;
}
