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
#include <cmath>

using namespace std;

int main()
{
  double r, x, y, x1, y1;
  scanf("%lf%lf%lf%lf%lf", &r, &x, &y, &x1, &y1);
  int res = ceil(sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1))/(2.0*r));
  printf("%d\n", res);
  return 0;
}
