#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

const int N = 3e2+5;

int n, h[N], r[N];

int main()
{
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    memset(h, -1, sizeof(h));
    for (int i = 0; i < n; i++) {
      int md = 0;
      for (int j = 0; j < 3; j++) {
        int d;
        scanf("%d", &d);
        md = max(md, d);
      }
      h[md] = i;
    }
    int rank = 0;
    for (int i = N-1; i >= 0; i--)
      if (h[i] != -1)
        r[h[i]] = rank++;
    for (int i = 0; i < n; i++)
      printf("%d%c", r[i]+1, i < n-1? ' ': '\n');
  }
  return 0;
}
