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

static const int N = 10000+5;

struct Member
{
  string name;
  int score;
  int region;

  void Input()
  {
    char foo[20];
    scanf("%s%d%d", foo, &region, &score);
    name = foo;
  }

  friend bool operator < (const Member& lhs, const Member& rhs)
  {
    return lhs.score > rhs.score;
  }
};

int n, m;
vector<Member> h[N];

int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    Member t;
    t.Input();
    h[t.region-1].push_back(t);
  }
  for (int i = 0; i < m; i++)
  {
    sort(h[i].begin(), h[i].end());
    if (h[i].size() > 2 && (h[i][0].score == h[i][1].score || h[i][1].score == h[i][2].score)) puts("?");
    else printf("%s %s\n", h[i][0].name.c_str(), h[i][1].name.c_str());
  }
  return 0;
}
