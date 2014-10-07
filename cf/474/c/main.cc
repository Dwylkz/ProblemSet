#include <bits/stdc++.h>

using namespace std;

struct Point {
  int x, y;

  Point(const int x_ = 0, const int y_ = 0): x(x_), y(y_) {}

  friend Point operator + (const Point& lhs, const Point& rhs)
  {
    return Point(lhs.x+rhs.x, lhs.y+rhs.y);
  }

  friend Point operator - (const Point& lhs, const Point& rhs)
  {
    return Point(lhs.x-rhs.x, lhs.y-rhs.y);
  }

  friend int operator % (const Point& lhs, const Point& rhs)
  {
    return lhs.x*rhs.y-lhs.y*rhs.x;
  }

  friend int operator * (const Point& lhs, const Point& rhs)
  {
    return lhs.x*rhs.x+lhs.y*rhs.y;
  }

  void Input()
  {
    scanf("%d%d", &x, &y);
  }

  void Output()
  {
    printf("(%d, %d)", x, y);
  }

  int Mod2()
  {
    return x*x+y*y;
  }

  Point Rot(int times)
  {
    Point ret = *this;
    for (int i = 0; i < times; i++)
      ret = Point(-ret.y, ret.x);
    return ret;
  }
};

int n;

int Check2(Point* p)
{
  for (int i = 0; i < 4; i++)
    if (((p[(i+1)%4]-p[i])%(p[(i+2)%4]-p[i])) <= 0)
      return false;

  for (int i = 0; i < 4; i++)
    if (((p[i]-p[(i+1)%4])*(p[(i+2)%4]-p[(i+1)%4])) != 0)
      return false;

  int l = (p[0]-p[3]).Mod2();
  if (l == 0)
    return false;

  for (int i = 1; i < 4; i++)
    if ((p[i]-p[i-1]).Mod2() != l)
      return false;
  return true;
}

bool Check(Point* p, Point* a, int* r)
{
  Point tp[4];
  for (int i = 0; i < 4; i++)
    tp[i] = a[i]+(p[i]-a[i]).Rot(r[i]);

  int id[4] = {0, 1, 2, 3};
  do {
    Point q[4];
    for (int i = 0; i < 4; i++)
      q[i] = tp[id[i]];

    if (Check2(q))
      return true;
  } while (next_permutation(id, id+4));
  return false;
}

int main()
{
  scanf("%d", &n);
  while (n--) {
    Point p[4], a[4];
    for (int i = 0; i < 4; i++) {
      p[i].Input();
      a[i].Input();
    }

    int ret = -1;
    int r[4];
    for (r[0] = 0; r[0] < 4; r[0]++)
      for (r[1] = 0; r[1] < 4; r[1]++)
        for (r[2] = 0; r[2] < 4; r[2]++)
          for (r[3] = 0; r[3] < 4; r[3]++)
            if (Check(p, a, r) && (ret == -1 || ret > accumulate(r, r+4, 0)))
              ret = accumulate(r, r+4, 0);

    printf("%d\n", ret);
  }
  return 0;
}
