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
#include <algorithm>
#include <stdint.h>

using namespace std;

const int N = 2e5+10;
const int X = 10;

int n, k, x, a[N], p[X];

int main()
{
  ios_base::sync_with_stdio(false);
  scanf("%d%d%d", &n, &k, &x);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  p[0] = 1;
  for (int i = 1; i <= k; i++)
    p[i] = p[i-1]*x;
  sort(a, a+n, greater<int>());
  int64_t ans = 0;
  for (int i = 63; i >= 0; i--) {
    int minki = -1, mink = k;
    for (int j = 0; j < n; j++) {
      if (1ll*a[j]*p[k] < (1ll<<i)) break;
      int tk = k;
      while (1ll*a[j]*p[tk] >= (1ll<<i)) tk--;
      if (tk < mink) {
        minki = j;
        mink = tk;
      }
    }
    k -= mink;
    a[minki] = 0;
    if (k == 0) break;
  }
  for (int i = 0; i < n; i++)
    ans |= a[i];
  cout << ans << endl;
  return 0;
}
