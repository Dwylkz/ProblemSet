#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3+10;

int n, x[N], m, y[N], f[N][N];
vector<int> tmp[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) tmp[i].clear();
    for (int i = 0; i < n; i++) {
      int j;
      scanf("%d", &j);
      tmp[j-1].push_back(i);
    }
    for (int i = 0, k = 0; i < n; i++)
      for (int j = 0; j < tmp[i].size(); j++)
        x[k++] = tmp[i][j];
    scanf("%d", &m);
    for (int i = 0; i < m; i++) tmp[i].clear();
    for (int i = 0; i < m; i++) {
      int j;
      scanf("%d", &j);
      tmp[j-1].push_back(i);
    }
    for (int i = 0, k = 0; i < m; i++)
      for (int j = 0; j < tmp[i].size(); j++)
        y[k++] = tmp[i][j];
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (x[i-1] == y[j-1]) f[i][j] = f[i-1][j-1]+1;
        else f[i][j] = max(f[i-1][j], f[i][j-1]);
    printf("%d\n", f[n][m]);
  }
  return 0;
}
