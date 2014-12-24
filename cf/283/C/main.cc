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

int n, a[N], d[N];

int main()
{
  scanf("%d", &n);
  int i = 0;
  a[i] = 0;
  d[i] = 0;
  i++;
  double sum = 0;
  while (n--) {
    int ti;
    scanf("%d", &ti);
    if (ti == 1) {
      int ai, xi;
      scanf("%d%d", &ai, &xi);
      sum += ai*xi;
      d[ai-1] += xi;
    } else if (ti == 2) {
      int ki;
      scanf("%d", &ki);
      sum += ki;
      a[i] = ki;
      d[i] = 0;
      i++;
    } else if (ti == 3) {
      sum -= a[i-1]+d[i-1];
      d[i-2] += d[i-1];
      i--;
    }
    printf("%f\n", sum/i);
  }
  return 0;
}
