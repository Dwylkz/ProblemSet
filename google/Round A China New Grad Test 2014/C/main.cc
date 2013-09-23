#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e3+10;

int my_abs(int x) {
  return x < 0? -x: x;
}

int n, tag[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
//   freopen("output.out", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int kas = 1; T--; kas++) {
    printf("Case #%d:", kas);
    scanf("%d", &n);
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
      int ai;
      scanf("%d", &ai);
      tag[i] = my_abs(ai)&1;
      if (tag[i]) a.push_back(ai);
      else b.push_back(ai);
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
      if (tag[i]) {
        tag[i] = a.back();
        a.pop_back();
      } else {
        tag[i] = b.back();
        b.pop_back();
      }
    for (int i = 0; i < n; i++)
      printf(" %d", tag[i]);
    puts("");
  }
  return 0;
}
