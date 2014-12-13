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

const int N = 2e5+5;

typedef map<int, int> MII;

int n, m, k, a[N], b[N], ha[N], hb[N];

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  MII dis;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    dis[a[i]] = 0;
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", b+i);
    dis[b[i]] = 0;
  }
  int rank = 0;
  for (auto i = dis.begin(); i != dis.end(); ++i)
    i->second = rank++;
  for (int i = 0; i < n; ++i)
    ha[i] = 0;
  for (int i = 0; i < m; ++i)
    hb[i] = 0;
  for (int i = 0; i < n; ++i)
    ++ha[dis[a[i]]];
  for (int i = 0; i < m; ++i)
    ++hb[dis[b[i]]];
  bool ans = false;
  int suma = 0, sumb = 0;
  for (int i = rank; i > 0; --i) {
    suma += ha[i-1];
    sumb += hb[i-1];
    if (suma > sumb)
      ans = true;
  }
  puts(ans? "YES": "NO");
  return 0;
}
