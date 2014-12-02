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
  void Init()
  {
    memset(d, 0, sizeof(d));
  }
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

struct Query {
  int op, x, y, w, z, a;
};

struct Line {
  int x, y1, y2, i, c;
  Line()
  {
  }
  Line(int x_, int y1_, int y2_, int i_, int c_):
      x(x_), y1(y1_), y2(y2_), i(i_), c(c_)
  {
  }
  friend bool operator < (const Line& lhs, const Line& rhs)
  {
    if (lhs.x != rhs.x)
      return lhs.x < rhs.x;
    return lhs.i < rhs.i;
  }
};

Query q[N];
int s, w;
int ans[N];

Fenwick f;
Line p[N];
void DAC(int l, int r)
{
  if (r-l < 2)
    return ;
  int m = (l+r)/2;
  int np = 0;
  for (int i = l; i < m; i++)
    if (q[i].op == 1)
      p[np++] = Line(q[i].x, q[i].y, 0, i, 0);
  for (int i = m; i < r; i++)
    if (q[i].op == 2) {
      p[np++] = Line(q[i].x-1, q[i].y-1, q[i].z, i, -1);
      p[np++] = Line(q[i].w, q[i].y-1, q[i].z, i, 1);
    }
  sort(p, p+np);
  for (int i = 0; i < np; i++)
    if (q[p[i].i].op == 1)
      f.Add(p[i].y1, q[p[i].i].a);
    else
      ans[q[p[i].i].a] += p[i].c*(f.Ask(p[i].y2)-f.Ask(p[i].y1));
  for (int i = 0; i < np; i++)
    if (q[p[i].i].op == 1)
      f.Add(p[i].y1, -q[p[i].i].a);
  DAC(l, m);
  DAC(m, r);
}

int main()
{
  scanf("%d%d", &s, &w);
  int n = 0, m = 0;
  while (~scanf("%d", &q[n].op) && q[n].op != 3) {
    if (q[n].op == 1)
      scanf("%d%d%d", &q[n].x, &q[n].y, &q[n].a);
    else {
      scanf("%d%d%d%d", &q[n].x, &q[n].y, &q[n].w, &q[n].z);
      q[n].a = m;
      ans[m++] = 1ll*(q[n].z+1-q[n].y)*(q[n].w+1-q[n].x)*s;
    }
    n++;
  }
  DAC(0, n);
  for (int i = 0; i < m; i++)
    printf("%d\n", ans[i]);

  return 0;
}
