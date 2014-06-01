#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e3+10;
typedef vector<int> VI;

int n, m, w[N], c[N], id[N];
VI g[N];

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) {
      cin >> w[i];
      g[i].clear();
      c[i] = 0;
    }
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    for (int u = 0; u < n; u++)
      for (auto v: g[u])
        c[v] += w[u];
    for (int i = 0; i < n; i++)
      id[i] = i;

    long long cost = 0;
    for (int i = 0; i < n; i++) {
      int min_id = i;
      for (int j = i+1; j < n; j++) {
        int a = id[j], b = id[min_id];
        if (w[a] > w[b]
            || (w[a] == w[b] && c[a] < c[b]))
          min_id = j;
      }
      swap(id[min_id], id[i]);

      cost += c[id[i]];
      for (auto v: g[id[i]])
        c[v] -= w[id[i]];
    }
    cout << cost << endl;
  }
  return 0;
}
