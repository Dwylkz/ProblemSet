#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3+10;
const int M = 1e2+10;
const int G = 1e1+10;

char l[N][G][G];
int n, m, k, w, g[N][N];

int d[N], ban[N], p[N], a[N];
int Prim()
{
  int res = 0;
  for (int u = 0; u < k; u++) {
    ban[u] = 0;
    d[u] = n*m;
    p[u] = 0;
  }
  ban[0] = 1;
  a[0] = 0;

  for (int i = 1; i < k; i++) {
    int u = 1;
    for (int j = 1; j < k; j++)
      if (!ban[j] && (ban[u] || d[j] < d[u]))
        u = j;

    ban[u] = 1;
    res += d[u];
    a[i] = u;

    for (int v = 0; v < k; v++) {
      if (ban[v] || g[u][v] >= d[v])
        continue;

      d[v] = g[u][v];
      p[v] = u;
    }
  }
  return res;
};

int Diff(char lhs[][G], char rhs[][G])
{
  int res = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      res += lhs[i][j]!=rhs[i][j];
  return res;
}

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n >> m >> k >> w) {
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < n; j++)
        cin >> l[i][j];

      g[0][i+1] = g[i+1][0] = n*m;
      for (int j = 0; j < i; j++)
        g[i+1][j+1] = g[j+1][i+1] = Diff(l[i], l[j])*w;
    }
    k++;

    cout << Prim() << endl;
    for (int i = 1; i < k; i++)
          cout << a[i] << " " << p[a[i]] << endl;
  }
  return 0;
}
