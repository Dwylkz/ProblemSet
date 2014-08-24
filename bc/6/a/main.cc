#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

const int N = 1e3+10;

int n, a[N];

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n) {
    for (int i = 0; i < n; i++)
      cin >> a[i];

    int ave = (accumulate(a, a+n, 0))/n;

    sort(a, a+n);
    int med = a[(n+1)/2-1];

    cout << (ave < med? "YES": "NO") << endl;
  }
  return 0;
}
