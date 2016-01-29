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

static const int N = 1e5+5;

struct Point
{
  int x, y, i;
  friend bool operator < (const Point& lhs, const Point& rhs) {
    if (lhs.x != rhs.x) return lhs.x < rhs.x;
    return lhs.y < rhs.y;
  }
};

int n;
Point ps[N];

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &ps[i].x, &ps[i].y);
    ps[i].i = i+1;
  }
  sort(ps, ps+n);
  printf("%d %d ", ps[0].i, ps[1].i);
  for (int i = 2; i < n; i++) {
    if ((ps[0].x-ps[i].x)*(ps[1].y-ps[i].y)-(ps[1].x-ps[i].x)*(ps[0].y-ps[i].y) != 0) {
      printf("%d\n", ps[i].i);
      break;
    }
  }
  return 0;
}
