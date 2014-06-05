#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVi;

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  cin.sync_with_stdio(0);
  int n;
  while (cin >> n) {
    VI a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    n++;
    VI x(n), y(n);
    int low = 0;
    for (int i = 1; i < n; i++) {
      x[i] = x[i-1]+a[i-1];
      y[i] = y[i-1]+(i&1? 1: -1)*a[i-1];
      low = min(low, y[i]);
    }
    int upp = 0;
    for (int i = 0; i < n; i++) {
      y[i] -= low;
      upp = max(upp, y[i]);
    }

#ifndef ONLINE_JUDGE
    for (int i = 0; i < n; i++)
      cout << "(" << x[i] << ";" << y[i] << ")" << endl;
#endif
    VVi g(x[n-1], VI(upp, ' '));
    for (int i = 1; i < n; i++) {
      int l = x[i-1];
      int r = x[i];
      if (y[i-1] > y[i]) {
        for (int j = r-1; j >= l; j--)
          g[j][y[i]+(r-1)-j] = '\\';
        continue;
      }
      for (int j = l; j < r; j++)
        g[j][y[i-1]+j-l] = '/';
    }
#ifndef ONLINE_JUDGE
    for (int i = 0; i < x[n-1]; i++) {
      for (int j = 0; j < upp; j++)
        cout << (char)g[i][j];
      cout << endl;
    }
#endif

    for (int i = upp-1; i >= 0; i--) {
      for (int j = 0; j < x[n-1]; j++)
        cout << (char)g[j][i];
      cout << endl;
    }
  }
  return 0;
}
