#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef long long LL;

const int N = 1e2+10;

int n;
LL a[N];

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n) {
    for (int i = 0; i < n; i++)
      cin >> a[i];

    VI v;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < i; j++)
        v.push_back(a[i]+a[j]);

    sort(v.begin(), v.end());
    cout << accumulate(v.begin(), unique(v.begin(), v.end()), 0ll) << endl;
  }
  return 0;
}
