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
  ban[u] = true;
  for (int i = 0; i < (int)g[u].size(); i++)
    if (HasLoop(g[u][i]))
      return true;
  ban[u] = false;
  return false;
}

int main()
{
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i < n; i++)
      g[i].clear();
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      g[b-1].push_back(a-1);
    }
    for (int v = 0; v < n; v++)
      g[n].push_back(v);
    for (int u = 0; u <= n; u++)
      ban[u] = false;
    puts(!HasLoop(n)? "YES": "NO");
  }
  return 0;
}
