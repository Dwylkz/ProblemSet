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

static const int N = 1e3+5;

struct P
{
  int x, y;

  P()
  {
  }

  P(int x, int y): x(x), y(y)
  {
  }

  void Input()
  {
    scanf("%d%d", &x, &y);
  }

  friend P operator - (const P& lhs, const P& rhs)
  {
    return P(lhs.x-rhs.x, lhs.y-rhs.y);
  }

  friend int operator % (const P& lhs, const P& rhs)
  {
    return lhs.x*rhs.y-lhs.y*rhs.x;
  }
};

int n;
P p[N];

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n+1; i++)
  {
    p[i].Input();
  }
  int cnt = 0;
  for (int i = 2; i < n+1; i++)
  {
    if ((p[i]-p[i-2])%(p[i-1]-p[i-2]) < 0)
    {
      cnt++;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
