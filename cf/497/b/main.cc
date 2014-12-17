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

const int N = 1e5+5;

int n, a[N];

bool Check(int s, int t, int win)
{
  int p[2] = {0}, r[2] = {0};
  for (int i = 0; i < n; i++) {
    p[a[i]]++;
    if (p[a[i]] == t) {
      memset(p, 0, sizeof(p));
      r[a[i]]++;
    }
  }
  return (r[1-win] < r[win] && r[win] == s);
}

int main()
{
  scanf("%d", &n);
  int p[2] = {0};
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    a[i]--;
    p[a[i]]++;
  }
  int win = a[n-1];
  vector<pair<int, int>> ans;
  for (int i = 1; 1ll*i*i <= p[win]; i++)
    if (p[win]%i == 0) {
      int s = i, t = p[win]/i;
      if (Check(s, t, win))
        ans.push_back(make_pair(s, t));
      if (s == t)
        continue;
      swap(s, t);
      if (Check(s, t, win))
        ans.push_back(make_pair(s, t));
    }
  sort(ans.begin(), ans.end());
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
