#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

const LL N = 1e18;

int cnt1, cnt2, x, y;

bool Check(LL v, int cnt1, int cnt2)
{
  LL cx = v-v/x;
  LL cy = v-v/y;
  LL cxy = v-(v/x+v/y-v/(x*y));
  cx -= cxy;
  cy -= cxy;

  cnt1 -= min(1ll*cnt1, cx);
  cnt2 -= min(1ll*cnt2, cy);
  return cnt1+cnt2 <= cxy;
}

int main()
{
  scanf("%d%d%d%d", &cnt1, &cnt2, &x, &y);
  LL l = 1, r = N;
  while (l < r) {
    LL m = (l+r)/2;
    if (Check(m, cnt1, cnt2))
      r = m;
    else
      l = m+1;
  }
  cout << l << endl;
  return 0;
}
