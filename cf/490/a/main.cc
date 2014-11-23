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

const int N = 5e3+5; 

typedef vector<int> VI;

VI t[3];
int n;

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int ti;
    scanf("%d", &ti);
    t[ti-1].push_back(i+1);
  }
  printf("%d\n", (int)min(t[0].size(), min(t[1].size(), t[2].size())));
  while (t[0].size() && t[1].size() && t[2].size()) {
    printf("%d %d %d\n", t[0].back(), t[1].back(), t[2].back());
    for (int i = 0; i < 3; i++)
      t[i].pop_back();
  }
  return 0;
}
