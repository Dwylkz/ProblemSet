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

const int N = 1e2+5;

int n, k, a[N], h[N][N];

int main()
{
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  int pre[N] = {0};
  int s = 0, ki = 0;
  for (int i = 0; i < n; i++) {
    memcpy(h[i], pre, sizeof(h[i]));
    if (a[i] > s) {
      for (int j = 0; j < a[i]-s; j++) {
        h[i][ki]++;
        ki = (ki+1)%k;
      }
    } else {
      for (int j = 0; j < s-a[i]; j++) {
        ki = (ki-1+k)%k;
        h[i][ki]--;
      }
    }
    for (int j = 0; j < k; j++) {
      if (abs(pre[j]-h[i][j]) > 1) {
        puts("NO");
        return 0;
      }
    }
    s = a[i];
    memcpy(pre, h[i], sizeof(pre));
  }
  puts("YES");
  for (int i = 0; i < n; i++) {
    int ki = 0, rem = a[i];
    while (rem) {
      if (h[i][ki] > 0) {
        printf("%d", ki+1);
        h[i][ki]--;
        rem--;
        if (rem == 0)
          puts("");
        else
          putchar(' ');
      } else {
        ki++;
      }
    }
  }
  return 0;
}
