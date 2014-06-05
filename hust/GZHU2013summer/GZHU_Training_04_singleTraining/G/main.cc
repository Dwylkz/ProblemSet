#include <set>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 2e4 + 10;
typedef long long LL;

struct point {
  int x, y;
  friend bool operator < (point lhs, point rhs)
  {
    if (lhs.x != rhs.x) return lhs.x < rhs.x;
    return lhs.y < rhs.y;
  }
};
typedef multiset<point> msi;
typedef msi::iterator msi_i;

int n;

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T, space = 0;
  scanf("%d", &T);
  for (int Case = 1; Case <= T; Case++) {
    if (space) puts("");
    space = 1;
    scanf("%d", &n);
    printf("Case #%d:\n", Case);
    for (vector<point> v; n--; ) {
      point p;
      scanf("%d%d", &p.x, &p.y);
      for (int i = 0; i < v.size(); i++)
        if (p.x < v[i].x && p.x <= v[i].y) {
          swap(v[i], v.back());
          v.pop_back();
          i--;
        }
      int f = 0;
      for (int i = 0; i < v.size() && !f; i++)
        if (v[i].x < p.x && v[i].y <= p.y) {
          f = 1;
          break;
        }
      if (!f) v.push_back(p);
      printf("%d\n", (int)v.size());
    }
  }
  return 0;
}
