#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  cin.sync_with_stdio(0);
  string a;
  int k;
  while (cin >> a >> k) {
    for (int head = 0; head < a.size(); head++) {
      int l = min(a.size(), 1u*head+k+1);
      int mxi = head;
      for (int i = head+1; i < l; i++)
        if (a[i] > a[mxi])
          mxi = i;
      a = a.substr(0, head)
          +a.substr(mxi, 1)
          +a.substr(head, mxi-head)
          +a.substr(mxi+1, a.size()-(mxi+1));
      k -= mxi-head;
      if (k == 0)
        break;
    }
    cout << a << endl;
  }
  return 0;
}
