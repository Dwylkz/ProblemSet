#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
#include <cassert>

using namespace std;

typedef long long LL;

const int N = 1e3+5;

int n, m, t[N], g[N][N], f[N][N];

int main()
{
  ios_base::sync_with_stdio(0);
  while (cin >> n) {
    for (int i = 0; i < 2*n-1; i++)
      cin >> t[i];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        g[i][j] = t[(n-1-i)+j];

    for (int i = 0; i < n; i++) {
      f[0][i] = 0;
      for (int j = 0; j < n; j++)
        f[0][i] += g[0][j]*g[j][i];
    }
    for (int i = 1; i < n; i++) {
      f[i][0] = 0;
      for (int j = 0; j < n; j++)
        f[i][0] += g[i][j]*g[j][0];
      for (int j = 1; j < n; j++)
        f[i][j] = f[i-1][j-1]
            -g[i-1][n-1]*g[n-1][j-1]
            +g[i][0]*g[0][j];
    }

    cin >> m;
    LL ret = 0;
    int ans = 0;
    while (m--) {
      int r, c;
      cin >> r >> c;
      r = (r+ans)%n;
      c = (c+ans)%n;
      ans = f[r][c];
      ret += ans;
    }
    cout << ret << endl;
  }
  return 0;
}
