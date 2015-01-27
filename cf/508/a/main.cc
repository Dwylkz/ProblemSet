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

const int N = 1e3+5;

bool g[N][N];
int n, m, k;

bool Check(int x, int y)
{
  return g[x][y]&&g[x][y+1]&&g[x+1][y]&&g[x+1][y+1];
}

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  int res = 0;
  for (int i = 0; i < k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x][y] = true;
    if (Check(x, y) || Check(x, y-1) || Check(x-1, y) || Check(x-1, y-1)) {
      if (res == 0)
        res = i+1;
    }
  }
  printf("%d\n", res);
  return 0;
}
