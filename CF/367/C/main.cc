#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+10;

int n, m, q[N], w[N];

long long calc(int x) {
  return (x&1? 1: x/2)+1ll*x*(x-1)/2;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    for (int i = 0; i < m; i++) scanf("%*d%d", w+i);
    sort(w, w+m, greater<int>());
    long long res = 0, sum = 0;
    for (int i = 1; i <= m && calc(i) <= n; i++) {
      sum += w[i-1];
      res = max(res, sum);
    }
    cout << res << endl;
  }
  return 0;
}
