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

static const int N = 1e5+5;

int n, m;
set<int> a;
vector<int> ans;

int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    int ai;
    scanf("%d", &ai);
    a.insert(ai);
  }
  int i = 1;
  while (i <= m)
  {
    if (!a.count(i))
    {
      m -= i;
      ans.push_back(i);
    }
    i++;
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); i++)
  {
    printf("%d%c", ans[i], i < ans.size()-1? ' ': '\n');
  }
  return 0;
}
