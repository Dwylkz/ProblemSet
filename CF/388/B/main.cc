#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3+10;
typedef pair<int, int> PII;
typedef vector<PII> VPii;
typedef vector<int> VI;

int k, n;
bool g[N][N];

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &k); ) {
    n = 2;
    memset(g, 0, sizeof(g));
    while (k) {
      VI h = {0};
      int o = 0;
      while ((1<<o) <= k) o++;
      o--;
      k -= 1<<o;
      for (int i = 0; i < o; i++) {
        VI t = {n, n+1};
        for (auto hi: h)
          for (auto ti: t)
            g[hi][ti] = g[ti][hi] = 1;
        h = t;
        n += 2;
      }
      for (auto hi: h)
        g[hi][1] = g[1][hi] = 1;
    }
    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        putchar(g[i][j]? 'Y': 'N');
      puts("");
    }
  }
  return 0;
}
