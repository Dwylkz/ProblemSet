#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5+10;
typedef vector<int> VI;
typedef vector<VI> VVi;

int n, k, p;

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n >> k >> p) {
    VI a[2];
    for (int i = 0; i < n; i++) {
      int ai;
      cin >> ai;
      a[ai%2].push_back(ai);
    }

    if (a[1].size() < k-p || (a[1].size()-(k-p))%2
        || a[0].size()+(a[1].size()-(k-p))/2 < p) {
      puts("NO");
      continue;
    }

    VVi res(k);
    for (int i = 0; i < k-p; i++) {
      res[i].push_back(a[1].back());
      a[1].pop_back();
    }

    for (int i = k-p; i < k; i++)
      if (!a[0].size())
        for (int j = 0; j < 2; j++) {
          res[i].push_back(a[1].back());
          a[1].pop_back();
        }
      else {
        res[i].push_back(a[0].back());
        a[0].pop_back();
      }

    for (int i = 0; i < 2; i++)
      for (auto ai: a[i])
        res[0].push_back(ai);

    cout << "YES" << endl;
    for (int i = 0; i < k; i++) {
      cout << res[i].size();
      for (auto ri: res[i])
        cout << " " << ri;
      cout << endl;
    }
  }
  return 0;
}
