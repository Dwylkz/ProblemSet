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

using namespace std;

typedef long long LL;

LL a, b;

int main()
{
  cin >> a >> b;
  LL c = 0;
  while (1) {
    if (a > b) swap(a, b);
    if (a == 0) break;
    c += b/a;
    b %= a;
  }
  cout << c << endl;
  return 0;
}
