#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5+10;

int n, d[N];
vector<int> a[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 1; i < N; i++) a[i].clear();
    for (int i = 0; i < n; i++) {
      int ai;
      scanf("%d", &ai);
      a[ai].push_back(i);
    }
    int result = 0;
    for (int i = 1; i < N; i++) {
      int diff = 0;
      for (int j = 1; j < a[i].size(); j++)
        if (j == 1) diff = a[i][j]-a[i][j-1];
        else if (a[i][j]-a[i][j-1] != diff) {
          diff = -1;
          break;
        }
      if (a[i].size()) {
        d[i] = diff;
        if (~diff) result++;
      } else d[i] = -1;
    }
    printf("%d\n", result);
    for (int i = 1; i < N; i++)
      if (~d[i]) printf("%d %d\n", i, d[i]);
  }
  return 0;
}
