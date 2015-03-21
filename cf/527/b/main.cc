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

const int N = 2e5+5;

int n;
char s[N], t[N];

int main()
{
  scanf("%d%s%s", &n, s, t);
  map<int, vector<int>> h;
  int d = 0;
  for (int i = 0; i < n; i++) d += (s[i] != t[i]);
  for (int i = 0; t[i]; i++) h[t[i]].push_back(i);
  int maxv = 0, x = -2, y = -2;
  for (int i = 0; i < s[i]; i++)
    if (s[i] != t[i] && h[s[i]].size())
      for (auto& hi: h[s[i]]) {
        int tx = i;
        int ty = hi;
        int v = 1;
        if (s[ty] == t[ty]) v--;
        if (s[ty] == t[tx]) v++;
        if (v > maxv) {
          maxv = v;
          x = tx;
          y = ty;
        }
      }
  printf("%d\n%d %d\n", d-maxv, x+1, y+1);
  return 0;
}
