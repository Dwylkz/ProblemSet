#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 3e5+10;
typedef vector<int> VI;

int n, a[N];

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    VI id(n);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int x, int y){return a[x] < a[y];});
    int rank = a[id[0]]+1;
    for (int i = 1; i < n; i++) {
      if (a[id[i]] > rank) rank = a[id[i]];
      a[id[i]] = rank++;
    }
    for (int i = 0; i < n; i++)
      printf("%d%c", a[i], i < n-1? ' ': '\n');
  }
  return 0;
}
