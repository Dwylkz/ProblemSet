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
const char* YES = "Possible";
const char* NO = "Impossible";

typedef vector<int> VI;

int n;
VI h[N];

int Size(int t[])
{
  int sum = 0;
  for (int i = 0; i < 3; i++)
    sum += h[t[i]].size();
  return sum;
}

int main()
{
  scanf("%d", &n);
  int maxv = 0;
  for (int i = 0; i < n; i++) {
    int ai;
    scanf("%d", &ai);
    maxv = max(maxv, ai);
    h[ai].push_back(i+1);
  }
  maxv = (maxv+2)/3;
  VI ans;
  int tail = -1;
  for (int i = maxv; i >= 0; i--) {
    int t[] = {i*3+2, i*3+1, i*3};
    printf("%d %d\n", i, Size(t));
    if (Size(t)%3 != 0) {
      if (tail != -1) {
        puts(NO);
        return 0;
      }
      tail = i;
    }
    while (h[t[0]].size() && h[t[1]].size() && h[t[2]].size())
      for (int i = 2; i >= 0; i--) {
        ans.push_back(h[t[i]].back());
        h[t[i]].pop_back();
      }
  }
  reverse(ans.begin(), ans.end());
  if (tail != -1) {
    int t[] = {tail*3, tail*3+1, tail*3+2};
    if (Size(t) == 1 && h[t[0]].size() == 1) {
      ans.push_back(h[t[0]].back());
    } else if (Size(t) == 2 && h[t[0]].size() == 1 && h[t[1]].size() == 1) {
      ans.push_back(h[t[0]].back());
      ans.push_back(h[t[1]].back());
    } else {
      puts(NO);
      return 0;
    }
  }
  puts(YES);
  for (int i = 0; i < ans.size(); i++)
    printf("%d%c", ans[i], i < ans.size()-1? ' ': '\n');
  return 0;
}
