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
        x = i;
        y = hi;
        maxv = max(maxv, 1);
        if (t[x] == s[y]) {
          maxv = 2;
          printf("%d\n%d %d\n", d-maxv, x+1, y+1);
          return 0;
        }
      }
  printf("%d\n%d %d\n", d-maxv, x+1, y+1);
  return 0;
}
