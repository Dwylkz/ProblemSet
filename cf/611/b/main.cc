#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
  uint64_t l, u;

  ios_base::sync_with_stdio(false);
  cin >> l >> u;
  int cnt = 0;
  for (int i = 1; i <= 63; i++) {
    uint64_t sum = (1ull<<i)-1;
    for (int j = 0; j < i-1; j++) {
      uint64_t v = sum&(~(1ull<<j));
      if (v >= l && v <= u) cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
