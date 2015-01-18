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

struct Ufs {
  int f[N];
  bool b[N];
  void Init()
  {
    for (int i = 0; i < N; i++) {
      f[i] = i;
      b[i] = false;
    }
  }
  int Find(int x)
  {
    if (f[x] == x)
      return x;
    b[f[x]] |= b[x];
    f[x] = Find(f[x]);
    return f[x];
  }
  int Union(int x, int y)
  {
    int px = Find(x);
    int py = Find(y);
    if (px != py) {
      f[py] = px;
      b[px] |= b[py];
      return 1;
    }
    if (x < y)
      return 0;
    if (b[px])
      return 0;
    b[px] = true;
    return 1;
  }
};

Ufs ufs;
int n, m;

int main()
{
  scanf("%d%d", &n, &m);
  ufs.Init();
  int res = 0;
  for (int i = 0; i < m; i++) {
    int ai, bi;
    scanf("%d%d", &ai, &bi);
    res += ufs.Union(ai-1, bi-1);
  }
  printf("%d\n", res);
  return 0;
}
