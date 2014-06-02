#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5+10;
typedef vector<int> VI;

int n, m, w[N], id[N], ufs[N], cnt[N], ban[N];
VI g[N];

int Find(int x)
{
  if (ufs[x] == x) return x;
  return ufs[x] = Find(ufs[x]);
}

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) {
      cin >> w[i];
      g[i].clear();
      ufs[i] = i;
      id[i] = i;
      cnt[i] = 1;
      ban[i] = 0;
    }
    sort(id, id+n, [&](int a, int b){return w[a] > w[b];});
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    double res = 0;
    for (int i = 0; i < n; i++) {
      int u = id[i];
      int ru = Find(u);
      for (auto v: g[u]) {
        if (!ban[v])
          continue;
        int rv = Find(v);
        if (rv != ru) {
          res += 1.0*cnt[ru]*cnt[rv]*w[u];
          ufs[rv] = ru;
          cnt[ru] += cnt[rv];
        }
      }
      ban[u] = 1;
    }
    cout << 2.0*res / (1.0*n*(n-1)) << endl;
  }
  return 0;
}
