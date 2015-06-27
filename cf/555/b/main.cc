#include <stdint.h>
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

typedef multimap<int64_t, int64_t> Map;

const int N = 2e5+5;
const char* YES = "Yes\n";
const char* NO = "No\n";

int n, m;
pair<int64_t, int64_t> l[N];
int64_t ans[N], gap[N];

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  if (m < n-1) {
    cout << NO;
    return 0;
  }
  Map gap;
  for (int i = 0; i < n; i++) {
    cin >> l[i].first >> l[i].second;
    if (i > 0) {
      gap.insert(Map::value_type(l[i].second-l[i-1].first, i-1));
    }
  }
  Map s;
  for (int i = 0; i < m; i++) {
    int64_t ai;
    cin >> ai;
    s.insert(Map::value_type(ai, i));
  }
  for (auto& gi: gap) {
    int i = gi.second;
    Map::iterator found = s.lower_bound(l[i+1].first-l[i].second);
    if (found == s.end() || found->first > gi.first) {
      cout << NO;
      return 0;
    }
    ans[i] = found->second+1;
    s.erase(found);
  }
  cout << YES;
  for (int i = 0; i < n-1; i++)
    cout << ans[i] << (i < n-2? ' ': '\n');
  return 0;
}
