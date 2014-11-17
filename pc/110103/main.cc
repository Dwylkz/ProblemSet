#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <cmath>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int N = 1e3+5;

typedef long long LL;

int n;
double e[N];

int main()
{
  while (~scanf("%d", &n) && n != 0) {
    double total = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lf", e+i);
      total += e[i];
    }
    double ave = round(100*total/n)/100;
    double in = 0.0, out = 0.0;
    for (int i = 0; i < n; i++)
      if (e[i] > ave)
        in += e[i]-ave;
      else
        out += ave-e[i];
    printf("$%.2f\n", min(in, out));
  }
  return 0;
}
