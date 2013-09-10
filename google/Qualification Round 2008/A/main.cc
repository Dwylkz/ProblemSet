#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
typedef map<string, int> msi_t;
const int inf = 0x3f3f3f3f;
const int N = 1e2+10;

int n, m, f[2][N];
char b[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ks = 1; T--; ks++) {
    printf("Case #%d: ", ks);
    msi_t msi;
    scanf("%d", &n), getchar();
    for (int i = 0; i < n; i++) {
      gets(b);
      msi[b] = i;
    }
    scanf("%d", &m), getchar();
    int *g = f[0], *h = f[1];
    memset(g, 0, sizeof(f[0]));
    for (int i = 0; i < m; i++) {
      gets(b);
      int id = msi.find(b)->second;
      for (int j = 0; j < n; j++) {
        h[j] = inf;
        if (j == id) continue;
        for (int k = 0; k < n; k++)
          h[j] = min(h[j], g[k]+(k != j));
      }
      swap(g, h);
#if 0
      for (int j = 0; j < n; j++) printf(" %d", g[j]);
      puts("");
#endif
    }
    int rv = inf;
    for (int j = 0; j < n; j++) rv = min(rv, g[j]);
    printf("%d\n", rv);
  }
  return 0;
}
