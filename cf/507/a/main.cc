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

int n, k, a[N], id[N];

int main()
{
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    id[i] = i;
  }
  sort(id, id+n, [&](int x, int y){return a[x] < a[y];});
  int m = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    int j = id[i];
    sum += a[j];
    if (sum <= k)
      m++;
    else
      break;
  }
  printf("%d\n", m);
  for (int i = 0; i < m; i++) {
    printf("%d", id[i]+1);
    if (i == m-1)
      puts("");
    else
      putchar(' ');
  }
  return 0;
}
