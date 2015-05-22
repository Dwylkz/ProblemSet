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

const int N = 6e3+5;

int n, h[N];

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int ai;
    scanf("%d", &ai);
    h[ai]++;
  }
  int ans = 0;
  for (int i = N-1; i >= 0; i--) {
    int j = i;
    while (j+1 < N && h[j] > 1) {
      ans += h[j]-1;
      h[j+1] += h[j]-1;
      h[j] = 1;
      j++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
