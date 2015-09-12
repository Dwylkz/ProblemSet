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

/* Of course, we can use dp in $n > m$ case.
 *
 * All we have to do is, turn $a$  into $[a]_m$，than count each $[a_i]_m$ into
 * slots, eg.
 *
 * $$n=5$$
 * $$m=5$$
 * $$a: [1, 2, 6, 7, 3]$$
 *
 * turn into
 * $$[a]_m: [1, 2, 1, 2, 3]$$
 *
 * and put number into its slot
 * $$cnt: [0, 2, 2, 1, 0]$$
 * $$idx: [0, 1, 2, 3, 4]$$
 *
 * We had reduced the prolem into classic 0/1 Knapsack problem with each item's
 * amount greater than 1.
 *
 * Here is the [code](http://codeforces.com/contest/577/submission/12973072),
 * but it would be a little slower:
 *
 * $$O(m^2\log{n})$$
 *
 * Actually, we could solve this use [Monotone priority
 * queue](https://en.wikipedia.org/wiki/Monotone_priority_queue). in:
 *
 * $$O(m^2)$$
 * */

using namespace std;

const int N = 1e3+10;

int n, m, h[N];
bool dp[2][N];

int main()
{
  scanf("%d%d", &n, &m);
  fill(h, h+m, 0);
  for (int i = 0; i < n; i++) {
    int ai;
    scanf("%d", &ai);
    h[ai%m]++;
  }
  bool *pdp = dp[0];
  bool *cdp = dp[1];
  fill(cdp, cdp+m, 0);
  for (int i = 0; i < m; i++) {
    int cnt = h[i];
    int seg = 1;
    while (cnt > 0) {
      swap(pdp, cdp);
      fill(cdp, cdp+m, 0);
      int det = min(cnt, seg);
      int wei = det*i%m;
      for (int j = 0; j < m; j++)
        cdp[(j+wei)%m] |= pdp[j];
      for (int j = 0; j < m; j++)
        cdp[j] |= pdp[j];
      cdp[wei] = true;
      cnt -= det;
      seg <<= 1;
      // for (int i = 0; i < m; i++) printf("%d%c", cdp[i], i < m-1? ' ': '\n');
    }
  }
  // for (int i = 0; i < m; i++) printf("%d%c", h[i], i < m-1? ' ': '\n');
  // for (int i = 0; i < m; i++) printf("%d%c", cdp[i], i < m-1? ' ': '\n');
  puts(cdp[0]? "YES": "NO");
  return 0;
}
