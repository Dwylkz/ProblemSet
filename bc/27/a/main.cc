#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

const int N = 3+5;

typedef pair<int, int> PII;

PII ps[N];
int n;

int main()
{
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      ps[i].first = 0;
      ps[i].second = i;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 3; j++) {
        int d;
        scanf("%d", &d);
        ps[i].first = max(ps[i].first, d);
      }
    }
    sort(ps, ps+n, greater<PII>());
    for (int i = 0; i < n; i++) {
      printf("%d", ps[i].second+1);
      if (i < n-1)
        putchar(' ');
      else
        puts("");
    }
  }
  return 0;
}
