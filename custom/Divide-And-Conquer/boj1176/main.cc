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

const int N = 18e4+5;

struct Fenwick {
  static const int M = 2e6+5;
  int d[M];
  void Add(int x, int y)
  {
    for (x++; x < M; x += -x&x)
      d[x] += y;
  }
  int Ask(int x)
  {
    int ans = 0;
    for (x++; x; x -= -x&x)
      ans += d[x];
    return ans;
  }
};

struct Line {
  int op, x, y1, y2, i, c;
  Line()
  {
  }
  Line(int op_, int x_, int y1_, int y2_, int i_, int c_):
      op(op_), x(x_), y1(y1_), y2(y2_), i(i_), c(c_)
  {
  }
  friend bool operator < (const Line& lhs, const Line& rhs)
  {
    if (lhs.x != rhs.x)
      return lhs.x < rhs.x;
    return lhs.y1 < rhs.y1;
  }
};

Line p[N];
int s, w, n, m, ans[N];

Fenwick f;
void DAC(int l, int r)
{
  if (r-l < 2)
    return ;
  int m = (l+r)/2;
  DAC(l, m);
  DAC(m, r);
  int j = l;
  for (int i = m; i < r; i++)
    if (p[i].op == 2) {
      while (j < m && p[j].x <= p[i].x) {
        if (p[j].op == 1)
          f.Add(p[j].y1, p[j].c);
        j++;
      }
      ans[p[i].i] += p[i].c*(f.Ask(p[i].y2)-f.Ask(p[i].y1-1));
    }
  while (j > l) {
    if (p[j-1].op == 1)
      f.Add(p[j-1].y1, -p[j-1].c);
    j--;
  }
  inplace_merge(p+l, p+m, p+r);
}

int main()
{
  scanf("%d%d", &s, &w);
  int op, x, y, w, z, a;
  while (~scanf("%d", &op) && op != 3)
    if (op == 1) {
      scanf("%d%d%d", &x, &y, &a);
      p[n++] = Line(op, x, y, 0, 0, a);
    }
    else {
      scanf("%d%d%d%d", &x, &y, &w, &z);
      p[n++] = Line(op, x-1, y, z, m, -1);
      p[n++] = Line(op, w, y, z, m, 1);
      ans[m++] = (z+1-y)*(w+1-x)*s;
    }
  DAC(0, n);
  for (int i = 0; i < m; i++)
    printf("%d\n", ans[i]);
  return 0;
}
