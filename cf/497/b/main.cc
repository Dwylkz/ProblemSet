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
const int M = 2;

int n, a[N], sa[M][N];

int Search(int lb, int rb, int t, int i, int l)
{
  if (lb == rb)
    return lb;
  int m = (lb+rb)/2;
  if (sa[i][m]-sa[i][l] >= t)
    return Search(lb, m, t, i, l);
  return Search(m+1, rb, t, i, l);
}

bool IsOk(int t, int win, int& s)
{
  int ts[M] = {0}, i = 0;
  while (i < n) {
    int ls = Search(i+1, n+1, t, 0, i);
    int rs = Search(i+1, n+1, t, 1, i);
    if (ls == n+1 && rs == n+1)
      return false;
    if (rs == n+1 || ls < rs) {
      ts[0]++;
      i = ls;
    }
    else {
      ts[1]++;
      i = rs;
    }
  }
  s = ts[win];
  return ts[win] > ts[1-win];
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    a[i]--;
    for (int j = 0; j < 2; j++)
      sa[j][i+1] = sa[j][i];
    ++sa[a[i]][i+1];
  }
  int win = a[n-1];
  vector<pair<int, int>> ans;
  for (int t = 1; t <= sa[win][n]; t++) {
    int s;
    if (IsOk(t, win, s))
      ans.push_back(make_pair(s, t));
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", (int)ans.size());
  for (auto& p: ans)
    printf("%d %d\n", p.first, p.second);
  return 0;
}
