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

int n, x;

int main()
{
  scanf("%d%d", &n, &x);
  int cur = 1, ans = 0;
  for (int i = 0; i < n; i++) {
    int li, ri;
    scanf("%d%d", &li, &ri);
    while (cur < li)
      cur += x;
    if (cur > li) {
      ans += ri+1-(cur-x);
    }
    else {
      ans += ri+1-li;
    }
    cur = ri+1;
  }
  printf("%d\n", ans);
  return 0;
}
