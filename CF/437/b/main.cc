#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> VI;

int main()
{
  cin.sync_with_stdio(0);

  int sum, limit;
  while (cin >> sum >> limit) {
    VI v;
    for (int i = 1; i <= limit; i++)
      v.push_back(i);
    sort(v.begin(), v.end(), [&](int lhs, int rhs){
         return (-lhs&lhs) > (-rhs&rhs);
         });

    VI res;
    for (int i = 0; i < v.size(); i++) {
      int lb = -v[i]&v[i];
      if (lb <= sum) {
        sum -= lb;
        res.push_back(v[i]);
      }
      if (!sum)
        break;
    }

    if (sum) {
      puts("-1");
      continue;
    }

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
      cout << res[i] << (i < res.size()-1? ' ': '\n');
  }

  return 0;
}
