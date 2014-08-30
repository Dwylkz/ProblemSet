#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1e3+10;
const int K = 5+10;

int n, k, a[N], h[K][N], m[K][N];

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n >> k) {
    for (int i = 0; i < n; i++)
      cin >> a[i];

    k--;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < n; j++) {
        int v;
        cin >> v;
        h[i][v] = j;
      }
    }

    int res = 0;
    memset(m, 0, sizeof(m));
    for (int i = 0; i < n; i++) {
      int x = a[i];
      int mx = 0;
      for (int j  = 0; j < i; j++) {
        int y = a[j];
        int mn = n;
        for (int l = 0; l < k; l++)
          if (h[l][y] < h[l][x])
            mn = min(mn, m[l][y]);
          else
            mn = min(mn, 0);

        mx = max(mx, mn);
      }

      for (int l = 0; l < k; l++)
        m[l][x] = mx+1;

      res = max(res, mx+1);
    }

    cout << res << endl;
  }

  return 0;
}
