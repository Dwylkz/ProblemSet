#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 3e3+10;

int n, v, f[N][2];

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n >> v) {
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      f[a][0] += b;
    }

    int res = 0;
    for (int i = 1; i < N-1; i++) {
      int r = v;
      int d = min(r, f[i][1]);
      r -= d;
      res += d;

      d = min(r, f[i][0]);
      res += d;
      f[i+1][1] = f[i][0]-d;
    }

    cout << res << endl;
  }
  return 0;
}
