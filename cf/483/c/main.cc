#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 10 1 9 2 8 3 7 4 6 5

int n, k;

int main()
{
  scanf("%d%d", &n, &k);
  vector<int> ans(1, k+1);
  for (int i = 1; i <= k; i++)
    if (i&1)
      ans.push_back(ans[i-1]-(k-i+1));
    else
      ans.push_back(ans[i-1]+(k-i+1));

  reverse(ans.begin(), ans.end());
  for (int i = k+2; i <= n; i++)
    ans.push_back(i);
  for (int i = 0; i < n; i++)
    printf("%d%c", ans[i], i < n-1? ' ': '\n');
  return 0;
}
