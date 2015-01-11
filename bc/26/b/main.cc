#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

int T, x, b;

int main()
{
  scanf("%d", &T);
  for (int kase = 1; kase <= T; kase++) {
    scanf("%d%d", &x, &b);
    printf("Case #%d: %.3f\n", kase, (1.0+x)*x/2.0*(1.0-pow(1.0-1.0/x, b)));
  }
  return 0;
}
