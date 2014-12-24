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

const int N = 1e5+5;

int n, a[N], r1, c1, r2, c2, v[N], b[N], ans;

int main()
{
#ifdef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    a[i]++;
  }
  scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
  r1--;
  r2--;
  int minv = c1;
  for (int i = r1; i >= 0; i--) {
    minv = min(minv, a[i]);
    b[i] = minv;
    v[i] = r1-i;
  }
  minv = c1;
  for (int i = r1; i < n; i++) {
    minv = min(minv, a[i]);
    b[i] = minv;
    v[i] = i-r1;
  }
  // for (int i = 0; i < n; i++)
  //   printf("%d%c", b[i], i < n-1? ' ': '\n');
  ans = N+N;
  minv = b[r2];
  for (int i = r2; i >= 0; i--) {
    minv = min(minv, b[i]);
    ans = min(ans, v[i]+abs(c2-minv)+r2-i);
  }
  minv = b[r2];
  for (int i = r2; i < n; i++) {
    minv = min(minv, b[i]);
    ans = min(ans, v[i]+abs(c2-minv)+i-r2);
  }
  printf("%d\n", ans);
  return 0;
}
