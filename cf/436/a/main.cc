#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2e3+10;

struct Candy {
  int t, h, m;
};

Candy cs[N];
int n, x;

int ban[N];
int g(int cur, int vane)
{
  for (int i = 0; i < n; i++)
    if (!ban[i] && cs[i].t == vane && cur >= cs[i].h)
      return i;
  return -1;
}

int f(int vane)
{
  memset(ban, 0, sizeof(ban));
  int cur = x, res = 0;
  while (1) {
    int found = g(cur, vane);
    if (!~found)
      break;

    cur += cs[found].m;
    ban[found] = 1;
    res++;
    vane ^= 1;
  }
  return res;
}

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n >> x) {
    for (int i = 0; i < n; i++)
      cin >> cs[i].t >> cs[i].h >> cs[i].m;
    sort(cs, cs+n, [&](const Candy& lhs, const Candy& rhs) {
         return lhs.m > rhs.m;
         });

    cout << max(f(0), f(1))<< endl;
  }
  return 0;
}
