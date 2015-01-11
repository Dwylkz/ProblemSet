#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

const int N = 1e2+5;

typedef vector<int> VI;

VI g[N];
int n, m;

bool ban[N];
bool HasLoop(int u)
{
  if (ban[u])
    return true;
  bool has = false;
  ban[u] = true;
  for (int i = 0; i < (int)g[u].size(); i++)
    has |= HasLoop(g[u][i]);
  ban[u] = false;
  return has;
}

int main()
{
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i < n; i++)
      g[i].clear();
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      g[a-1].push_back(b-1);
    }
    bool has = false;
    for (int v = 0; v < n; v++)
      has |= HasLoop(v);
    puts(!has? "YES": "NO");
  }
  return 0;
}
