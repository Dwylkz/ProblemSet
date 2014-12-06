#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

int n;

int main()
{
  while (~scanf("%d", &n)) {
    vector<int> ans;
    int d[] = {15, 7, 4, 2, 1, -1};
    for (int i = 0; d[i] != -1; i++)
      if (n > d[i])
        ans.push_back(n-d[i]);
    for (int i = 0; i < ans.size(); i++)
      printf("%d%c", ans[i], i < ans.size()-1? ' ': '\n');
  }
  return 0;
}
