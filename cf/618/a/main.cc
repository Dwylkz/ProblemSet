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

int n;

int main()
{
  scanf("%d", &n);
  vector<int> s;
  for (int i = 0; i < n; i++) {
    s.push_back(1);
    while (s.size() > 1 && s.back() == s[s.size()-2]) {
      s.pop_back();
      s.back()++;
    }
  }
  for (int i = 0; i < s.size(); i++) {
    printf("%d%c", s[i], i < s.size()-1? ' ': '\n');
  }
  return 0;
}
