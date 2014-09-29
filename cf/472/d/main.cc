#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int N = 2e3+10;

int n, d[N][N], id[N][N];

bool IsOk()
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i == j) {
        if (d[i][i] != 0)
          return false;
      }
      else if (d[i][j] == 0 || d[j][i] == 0 || d[i][j] != d[j][i])
        return false;
  return true;
}

bool vis[N];
bool Dfs(int u, int p)
{
  if (vis[u] == true)
    return true;

  vis[u] = true;
  for (int i = 0; i < n; i++) {
    int v = id[u][i];
    if (v == u || v == p)
      continue;

    if (p != -1) {
      if (d[p][v]-d[u][v] == d[p][u]) {
        if (!Dfs(v, u))
          return false;
      }
      else if (d[u][v]-d[p][v] != d[u][p])
        return false;
    }
    else if (!Dfs(v, u))
      return false;
  }
  return true;
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      scanf("%d", d[i]+j);

    for (int j = 0; j < n; j++)
      id[i][j] = j;
    sort(id[i], id[i]+n, [&](int a, int b){return d[i][a] < d[i][b];});
  }

  puts(IsOk() && Dfs(0, -1)? "YES": "NO");
  return 0;
}
