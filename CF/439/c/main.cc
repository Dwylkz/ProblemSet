#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5+10;
typedef vector<int> VI;
typedef vector<VI> VVi;

int n, k, p;

void show(VI& v)
{
  cout << v.size();
  for (auto vi: v)
    cout << " " << vi;
  cout << endl;
}

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n >> k >> p) {
    k -= p;
    VVi odd, even;
    VI rem_odd, rem_even;
    for (int i = 0; i < n; i++) {
      int ai;
      cin >> ai;
      if (ai%2 != 0) {
        if (odd.size() < k)
          odd.push_back(VI(1, ai));
        else
          rem_odd.push_back(ai);
      }
      else {
        if (even.size() < p)
          even.push_back(VI(1, ai));
        else
          rem_even.push_back(ai);
      }
    }

    if (odd.size() < k) {
      cout << "NO" << endl;
      continue;
    }

    if (even.size() < p) {
      if (rem_odd.size()/2 < p-even.size()) {
        cout << "NO" << endl;
        continue;
      }

      for (int i = 0; i < p-even.size(); i++) {
        VI temp = {rem_odd.back(), rem_odd[rem_odd.size()-2]};
        rem_odd.pop_back();
        rem_odd.pop_back();
        even.push_back(temp);
      }
    }

    if (rem_odd.size()%2 != 0) {
      cout << "NO" << endl;
      continue;
    }

    VI& rem = p > 0? even[0]: odd[0];
    for (auto i: rem_odd)
      rem.push_back(i);
    for (auto i: rem_even)
      rem.push_back(i);

    cout << "YES" << endl;
    for (auto v: even)
      show(v);
    for (auto v: odd)
      show(v);
  }
  return 0;
}
