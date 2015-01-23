#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <stdint.h>

using namespace std;

int main()
{
  int h;
  int64_t n;
  cin >> h >> n;
  n += (1ll<<h)-1;
  vector<int> d;
  while (n != 1) {
    d.push_back(n&1);
    n >>= 1;
  }
  reverse(d.begin(), d.end());
  int c = 0;
  int ch = h;
  int64_t res = 0;
  for (auto di: d) {
    if (c == di) {
      res += 1;
      c ^= 1;
    } else {
      res += 1ll<<ch;
    }
    ch--;
  }
  cout << res << endl;
  return 0;
}
