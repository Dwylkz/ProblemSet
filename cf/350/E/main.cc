#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 3e3+10;

int n, m, k, mark[N], id[N];

bool cmp(int lhs, int rhs) {
  return mark[lhs] > mark[rhs];
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d", &n, &m, &k); ) {
    memset(mark, 0, sizeof(mark));
    for (int i = 0; i < k; i++) {
      int ai;
      scanf("%d", &ai);
      mark[ai-1] = 1;
    }
    if (k == n || m > (n-2)*(n-1)/2+(n-k)) {
      puts("-1");
      continue;
    }
    for (int i = 0; i < n; i++) id[i] = i;
    sort(id, id+n, cmp);
    for (int i = 1; i < n-1; i++)
      printf("%d %d\n", id[i]+1, id[i+1]+1);
    printf("%d %d\n", id[n-1]+1, id[0]+1);
    m -= n-1;
    for (int i = 1; i < n; i++)
      for (int j = i+2; j < n; j++)
        if (m) {
          printf("%d %d\n", id[i]+1, id[j]+1);
          m--;
        }
    for (int i = k; i < n; i++)
      if (m) {
        printf("%d %d\n", id[0]+1, id[i]+1);
        m--;
      }
  }
  return 0;
}
