#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef map<int, int>  mii_t;
const int N = 2e5+10;

int n, m, p, a[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d", &n, &m, &p); ) {
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    mii_t b;
    for (int i = 0; i < m; i++) {
      int bi;
      scanf("%d", &bi);
      b[bi]++;
    }
#if 0
    for (auto i: b) printf("%d %d\n", i.first, i.second);
#endif
    vector<int> res;
    for (int i = 0; i < p; i++) {
      mii_t bm;
      vector<int> q;
      int sum = 0, head = 0;
#if 0
      printf("in %d:\n", i);
#endif
      for (int j = i; j < n; j += p) {
        q.push_back(j);
        if (q.size()-head > m) {
          int ai = a[q[head]];
          if (b[ai]) {
            bm[ai]--;
            if (bm[ai] < b[ai]) sum--;
          }
          head++;
        }
        if (b[a[j]]) {
          if (bm[a[j]] < b[a[j]]) sum++;
          bm[a[j]]++;
        }
        if (sum == m) res.push_back(q[head]);
#if 0
        printf("\t%d sum=%d\n", a[j], sum);
#endif
      }
#if 0
      puts("");
#endif
    }
    sort(res.begin(), res.end());
    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); i++) {
      if (i) putchar(' ');
      printf("%d", res[i]+1);
    }
    puts("");
  }
  return 0;
}
