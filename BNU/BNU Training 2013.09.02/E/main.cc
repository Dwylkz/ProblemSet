#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 5e2+10;

int n, a[N], r[N][N], in[N], ans[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d", &n);
    memset(r, 0, sizeof(r));
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
      for (int j = 0; j < i; j++)
        r[a[i]-1][a[j]-1] = 1;
    }
    int m;
    scanf("%d", &m);
    for ( ; m--; ) {
      int u, v;
      scanf("%d%d", &u, &v);
      --u, --v;
      swap(r[u][v], r[v][u]);
    }
    for (int i = 0; i < n; i++) {
      in[i] = 0;
      for (int j = 0; j < n; j++)
        in[i] += r[i][j];
    }
#if 0
    puts("r");
    for (int i = 0; i < n; i++) {
      printf("%4d: ", in[i]);
      for (int j = 0; j < n; j++)
        printf(" %d", r[i][j]);
      puts("");
    }
#endif
    vector<int> q;
    int z = 0;
    for (int i = 0; i < n; i++)
      if (!in[i]) {
        q.push_back(i);
        z++;
      }
    for (int h = 0; h < q.size(); h++) {
      int u = q[h];
#if 0
      printf("in %d, z = %d\n", u, z);
#endif
      if (z-- > 1) ans[h] = -1;
      else ans[h] = u;
      for (int v = 0; v < n; v++)
        if (r[v][u] && !--in[v]) {
          q.push_back(v);
          z++;
        }
    }
    if (q.size() != n) {
      puts("IMPOSSIBLE");
      continue;
    }
    for (int i = 0, b = 0; i < n; i++) {
      if (b) putchar(' ');
      b = 1;
      if (~ans[i]) printf("%d", ans[i]+1);
      else putchar('?');
    }
    puts("");
  }
  return 0;
}
