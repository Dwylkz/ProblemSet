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

const int N = 1e3+5;
const int B = 2;

int n, m;
bool rb[N], cb[N], ru[N][B], cu[N][B];

int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    rb[x-1] = true;
    cb[y-1] = true;
  }
  for (int i = 1; i < n-1; i++)
    if (n%2 == 1 && i == n/2) {
      if (!cb[i])
        cu[i][0] = true;
      else if (!rb[i])
        ru[i][1] = true;
    } else {
      if (!cb[i] && !cu[i][1] && !ru[i][0])
        cu[i][0] = true;
      if (!rb[i] && !ru[i][0] && !cu[n-i-1][0])
        ru[i][1] = true;
      if (!cb[n-1-i] && !cu[n-1-i][0] && !ru[n-i-1][1])
        cu[n-1-i][1] = true;
      if (!rb[n-1-i] && !ru[n-1-i][1] && !cu[i][1])
        ru[n-1-i][0] = true;
    }
  int res = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < B; j++)
      res += ru[i][j]+cu[i][j];
  printf("%d\n", res);
  return 0;
}
