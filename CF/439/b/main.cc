#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
typedef long long LL;

int n, x, c[N];

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n >> x) {
    for (int i = 0; i < n; i++)
      cin >> c[i];
    sort(c, c+n);
    LL res = 0;
    for (int i = 0; i < n; i++) {
      res += 1ll*c[i]*x;
      if (x > 1)
        x--;
    }
    cout << res << endl;
  }
  return 0;
}
