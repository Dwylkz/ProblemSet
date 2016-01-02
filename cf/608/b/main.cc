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
#include <cstdint>

using namespace std;

const int N = 2e5+5;

int n;
char a[N], b[N];
int fc[N][2];

int GetSum(int x, int l, int r)
{
  x = (x-'0')^1;
  if (l > 0) return fc[r][x]-fc[l-1][x];
  return fc[r][x];
}

int main()
{
  scanf("%s%s", a, b);
  int la = strlen(a);
  int lb = strlen(b);
  fc[0][a[0]-'0']++;
  for (int i = 1; i < la; i++) {
    for (int j = 0; j < 2; j++)
      fc[i][j] += fc[i-1][j];
    fc[i][a[i]-'0']++;
  }
  // for (int i = 0; i < la; i++)
  //   printf("(%3d,%3d)", fc[i][0], fc[i][1]);
  // puts("");
  uint64_t sum = 0;
  for (int i = 0; i < lb; i++) {
    int l = 0;
    int r = la-1;
    if (i-la+1 < 0) r = i;
    if (i+la-1 >= lb) l = la-(lb-i);
    // printf("%d,%d\n", l, r);
    sum += GetSum(b[i], l, r);
  }
  cout << sum << endl;
  return 0;
}
