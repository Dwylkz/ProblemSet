#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
typedef vector<int> VI;

int n, m, w[N], ban[N], id[N];
VI g[N];

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) {
      cin >> w[i];
      ban[i] = 0;
      g[i].clear();
    }
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
      id[i] = i;
    sort(id, id+n, [&](int a, int b){return w[a] > w[b];});

    double res = 0;
    int old = 0;
    for (int i = 0; i < n; i++) {
      int u = id[i];
      if (!ban[u]) {
        VI q(1, u);
        int cnt = 1;
        for (int h = 0; h < q.size(); h++) {
          ban[q[h]] = 1;
          cnt++;
          for (auto v: g[q[h]])
            if (w[v] < w[u] && !ban[v])
              q.push_back(v);
        }
        old += cnt;
        res += 1.0*cnt*cnt*w[u];
      }
    }
    cout << res*2.0 / ((1.0*n)*(n-1)) << endl;
  }
  return 0;
}
