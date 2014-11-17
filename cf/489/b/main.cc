#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int N = 1e2+5;

int n, m, a[N], b[N];

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int ai;
    scanf("%d", &ai);
    a[ai]++;
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int bi;
    scanf("%d", &bi);
    b[bi]++;
  }
  int ans = 0;
  for (int i = 0; i < N; i++)
    for (int j = -1; j < 2; j++)
      if (i+j >= 0 && i+j < N) {
        int d = min(a[i], b[i+j]);
        ans += d;
        a[i] -= d;
        b[i+j] -= d;
      }
  printf("%d\n", ans);
  return 0;
}
