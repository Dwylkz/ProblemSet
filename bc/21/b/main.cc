#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

const int N = 1e6+5;
const int MOD = 1e9+7;

pair<int, int> ask[N];
int ans[N];

int main()
{
  int m = 0;
  while (~scanf("%d", &ask[m].first)) {
    ask[m].second = m;
    m++;
  }
  sort(ask, ask+m);
  int f = 1, g = 1;
  for (int i = 0, j = 1; i < m; i++) {
    while (j <= ask[i].first) {
      f = 1ll*f*j%MOD;
      g = 1ll*g*f%MOD;
      j++;
    }
    ans[ask[i].second] = g;
  }
  for (int i = 0; i < m ; i++)
    printf("%d\n", ans[i]);
  return 0;
}
