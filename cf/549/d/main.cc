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

struct Fenwick {
  int t[N];
  void Init()
  {
    fill(t, t+N, 0);
  }
  void Add(int x, int y)
  {
    for (x++; x < N; x += -x&x)
      t[x] += y;
  }
  int Ask(int x)
  {
    int res = 0;
    for (x++; x; x -= -x&x)
      res += t[x];
    return res;
  }
};

struct Fenwick2 {
  Fenwick t[N];
  void Init()
  {
    for (int i = 0; i < N; i++)
      t[i].Init();
  }
  void Add(int x, int y, int z)
  {
    for (x++; x < N; x += -x&x)
      t[x].Add(y, z);
  }
  int Ask(int x, int y)
  {
    int res = 0;
    for (x++; x; x -= -x&x)
      res += t[x].Ask(y);
    return res;
  }
};

Fenwick2 zkl;
int n, m;
char b[N][N];

int main()
{
  scanf("%d%d", &n, &m);
  int res = 0;
  zkl.Init();
  for (int i = n-1; i >= 0; i--) {
    scanf("%s", b[i]);
    reverse(b[i], b[i]+m);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int x = b[i][j] == 'W'? 1: -1;
      int y = zkl.Ask(i, j);
      if (y != x) {
        zkl.Add(i, j, x-y);
        res++;
      }
    }
  printf("%d\n", res);
  return 0;
}
