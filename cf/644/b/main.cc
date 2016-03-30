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

static const int N = 2e5+5;

int n, b, r[N];

int main()
{
  scanf("%d%d", &n, &b);
  deque<pair<int, int>> q;
  int gt = 0;
  int srv = 0;
  for (int i = 0; i < n; i++)
  {
    int t, d;
    scanf("%d%d", &t, &d);
    if (srv == 0)
    {
      if (q.size())
      {
        r[q.back().first] = gt+q.back().second;
        q.pop_back();
      }
    }
    while (q.size() && q.front() <= t)
    {
      q.pop_front();
    }
    if (q.size() == b+1)
    {
      r[i] = -1;
    }
    else
    {
      if (q.size()) 
      {
        d += q.back();
      }
      else
      {
        d += t;
      }
      q.push_back(d);
      r[i] = d;
    }
  }
  for (int i = 0; i < n; i++)
  {
    printf("%d%c", r[i], i < n-1? ' ': '\n');
  }
  return 0;
}
