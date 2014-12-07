#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

const int N = 4e5+5;
const int M = 1e5+5;

struct Fenwick {
  int v[M];
  void Init()
  {
    memset(v, 0, sizeof(v));
  }
  void Add(int x, int y)
  {
    for (x++; x < M; x += -x&x)
      v[x] += y;
  }
  int Ask(int x)
  {
    int ans = 0;
    for (x++; x; x -= -x&x)
      ans += v[x];
    return ans;
  }
};

struct Ask {
  int op, x, y, z, c, i;
  Ask()
  {
  }
  Ask(int op, int x, int y, int z, int c, int i):
      op(op), x(x), y(y), z(z), c(c), i(i)
  {
  }
};

typedef map<int, int> MII;

Ask a[N];
int q, ans[N];

Fenwick f;
void DAC2(Ask* a[], int l, int r)
{
  struct Lambda {
    static bool Cmp(Ask* lhs, Ask* rhs)
    {
      if (lhs->y != rhs->y)
        return lhs->y < rhs->y;
      return lhs->z < rhs->z;
    }
  };
  if (r-l < 2)
    return ;
  int m = (l+r)/2;
  DAC2(a, l, m);
  DAC2(a, m, r);
  static Ask* b[N];
  int bl = 0;
  for (int i = l; i < m; i++)
    if (a[i]->op == 1)
      b[bl++] = a[i];
  int bm = bl;
  for (int i = m; i < r; i++)
    if (a[i]->op == 2)
      b[bl++] = a[i];
  int lb = 0;
  for (int i = bm; i < bl; i++)
    if (b[i]->op == 2) {
      for ( ; lb < bm && b[lb]->y <= b[i]->y; lb++)
        if (b[lb]->op == 1)
          f.Add(b[lb]->z, 1);
      ans[b[i]->i] += b[i]->c*f.Ask(b[i]->z);
    }
  for (int i = 0; i < lb; i++)
    if (b[i]->op == 1)
      f.Add(b[i]->z, -1);
  inplace_merge(a+l, a+m, a+r, Lambda::Cmp);
}

void DAC(Ask* a[], int l, int r)
{
  struct Lambda {
    static bool Cmp(Ask* lhs, Ask* rhs)
    {
      return lhs->x < rhs->x;
    }
  };
  if (r-l < 2)
    return ;
  int m = (l+r)/2;
  DAC(a, l, m);
  DAC(a, m, r);
  static Ask* b[N];
  int bl = 0;
  for (int i = l; i < m; i++)
    if (a[i]->op == 1)
      b[bl++] = a[i];
  int bm = bl;
  for (int i = m; i < r; i++)
    if (a[i]->op == 2)
      b[bl++] = a[i];
  inplace_merge(b, b+bm, b+bl, Lambda::Cmp);
  DAC2(b, 0, bl);
  inplace_merge(a+l, a+m, a+r, Lambda::Cmp);
}

int main()
{
  int kase;
  scanf("%d", &kase);
  while (kase--) {
    scanf("%d", &q);
    int n = 0, m = 0;
    MII dis;
    for (int i = 0; i < q; i++) {
      int op, x1, y1, z1, x2, y2, z2;
      scanf("%d%d%d%d", &op, &x1, &y1, &z1);
      if (op == 1) {
        a[n++] = Ask(op, x1, y1, z1, 0, 0);
        dis[z1] = 0;
      }
      else {
        scanf("%d%d%d", &x2, &y2, &z2);
        dis[z1-1] = 0;
        dis[z2] = 0;
        a[n++] = Ask(op, x2, y2, z2, 1, m);
        a[n++] = Ask(op, x2, y1-1, z2, -1, m);
        a[n++] = Ask(op, x1-1, y2, z2, -1, m);
        a[n++] = Ask(op, x1-1, y1-1, z2, 1, m);
        a[n++] = Ask(op, x2, y2, z1-1, -1, m);
        a[n++] = Ask(op, x2, y1-1, z1-1, 1, m);
        a[n++] = Ask(op, x1-1, y2, z1-1, 1, m);
        a[n++] = Ask(op, x1-1, y1-1, z1-1, -1, m);
        ans[m++] = 0;
      }
    }
    int idx = 0;
    for (MII::iterator i = dis.begin(); i != dis.end(); i++)
      i->second = idx++;
    static Ask* pa[N];
    for (int i = 0; i < n; i++) {
      a[i].z = dis[a[i].z];
      pa[i] = a+i;
    }
    f.Init();
    DAC(pa, 0, n);
    for (int i = 0; i < m; i++)
      printf("%d\n", ans[i]);
  }
  return 0;
}
