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

int n, k;

int main()
{
  scanf("%d%d", &n, &k);
  int ans = 0;
  for (int i = 0; i < k; i++) {
    int m;
    scanf("%d", &m);
    bool ok = true;
    for (int i = 1; i <= m; i++) {
      int s;
      scanf("%d", &s);
      if (ok) {
        if (i != s) ok = false;
      }
      if (!ok) {
        if (i == 1) ans++;
        else ans += 2;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
