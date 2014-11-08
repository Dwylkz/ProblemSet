#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
#include <memory>

using namespace std;

const int N = 1e5+5;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> Graph;
typedef pair<int*, int*> PAA;

Graph g;
int t, n, k, sz[N];

int DFS(int u, int p = -1)
{
  sz[u] = 1;
  for (int i = 0; i < g[u].size(); i++)
    if (g[u][i] != p)
      sz[u] += DFS(g[u][i], u);
  return sz[u];
}

int ts[N];
PAA DAC(int u, int p = -1)
{
  int* us = new int[sz[u]];
  int* uc = new int[sz[u]];
  for (int i = 0; i < sz[u]; i++) {
    us[i] = 0;
    uc[i] = 0;
  }
  us[0] = 1;
  uc[0] = 1;

  for (int i = 0; i < g[u].size(); i++)
    if (g[u][i] != p) {
      int v = g[u][i];
      PAA p = DAC(v, u);
      int* vs = p.first;
      int* vc = p.second;

      for (int j = 1; j < sz[u]; j++)
        ts[j] = 0;

      for (int j = 0; j < sz[v] && vc[j]; j++)
        uc[j] += vc[j];
      for (int j = 0; j < sz[u] && us[j]; j++)
        for (int k = 1; k <= sz[v] && vs[k-1]; k++) {
          ts[j+k] += us[j]*vs[k-1];
          uc[j+k] += us[j]*vs[k-1];
        }

      for (int j = 1; j < sz[u] && ts[j]; j++)
        us[j] = ts[j];

      delete[] vs;
      delete[] vc;
    }
  int sum = 0;
  for (int i = 1; i < sz[u]-1; i++) {
    sum += us[i];
    if (sum >= k) {
      us[i+1] = 0;
      break;
    }
  }
  return PAA(us, uc);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    g = Graph(n, VI());
    for (int i = 0; i < n-1; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    DFS(0);

    PAA p = DAC(0);

    LL res = 0;
    for (int i = 1; i < n; i++) {
      int d = min(k, p.second[i]);
      res += 1ll*d*i;
      k -= d;
      if (k == 0)
        break;
    }
    cout << res << endl;

    delete[] p.first;
    delete[] p.second;
  }
  return 0;
}
