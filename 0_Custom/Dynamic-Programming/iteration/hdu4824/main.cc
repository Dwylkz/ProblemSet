#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1e3+10;
const int CS = 360;
const int CT = 400;
const int CR = 10;
const int INF = 0x3f3f3f3f;

int n, t[N], s[N], f[N][N];

int Arc(int x, int y)
{
  int arc = abs(s[x]-s[y]);
  return min(arc, CS-arc);
}

int main()
{
  cin.sync_with_stdio(false);

  int T;
  cin >> T;
  for (int kas = 1; kas <= T; kas++) {
    cin >> n;
    t[0] = s[0] = 0;
    for (int i = 1; i <= n; i++)
      cin >> t[i] >> s[i];

    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 0; j < i; j++) {
        f[i][j] = min(f[i][j], f[i-1][j]+Arc(i, i-1));
        f[i][i-1] = min(f[i][i-1], f[i-1][j]+Arc(i, j));
      }

    int res = INF;
    for (int i = 0; i < n; i++)
      res = min(res, f[n][i]+Arc(n, i));

    cout << res+CT*t[n]*2+CR*n << endl;
  }
  return 0;
}
