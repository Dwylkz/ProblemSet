#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

LL l, r;
int k;

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> l >> r >> k) {
    LL b = (l&1)? l+1: l;
    LL ret = 0;
    vector<LL> v;
    for (int i = 20; i >= 1; i--)
      if (k&(1<<i)) {
        for (int j = 1<<i; j > 0; j--) {
          ret ^= b;
          v.push_back(b);
          b++;
        }
      }

    if (k == r-l+1) {
      ret = 0;
      v.clear();
      for (LL i = l; i <= r; i++) {
        ret |= i;
        v.push_back(i);
      }
    }

    cout << ret << endl;
    cout << v.size() << endl;
    for (int i = 0; i < v.size()-1; i++)
      cout << v[i] << " ";
    cout << v.back() << endl;
  }
  return 0;
}
