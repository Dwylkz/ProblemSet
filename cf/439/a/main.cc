#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e2+10;

int n, d, t[N];

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n >> d) {
    int res = 0;
    for (int i = 0; i < n; i++) {
      cin >> t[i];
      if (i > 0) {
        d -= 10;
        res += 2;
      }
      d -= t[i];
    }
    if (d < 0)
      res = -1;
    else
      res += d/5;
    cout << res << endl;
  }
  return 0;
}
