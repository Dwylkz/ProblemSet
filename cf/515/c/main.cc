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

const int N = 15+5;
const int M = 10;
const vector<vector<int>> P = {
  {},
  {},
  {2},
  {3},
  {2, 2},
  {5},
  {2, 3},
  {7},
  {2, 2, 2},
  {3, 3}
};

char s[N];
int n, h[M];

int main()
{
  scanf("%d%s", &n, s);
  for (int i = 0; i < n; i++) {
    if (s[i]-'0' >= 5) {
      h[s[i]-'0']++;
      continue;
    }
    for (int j = 2; j <= s[i]-'0'; j++) {
      for (auto pi: P[j]) {
        h[pi]++;
      }
    }
  }
  for (int i = M-1; i >= 0; i--) {
    for (int j = 0; j < h[i]; j++) {
      printf("%d", i);
      if (i == 3) {
        h[2]--;
      }
    }
  }
  puts("");
  return 0;
}
