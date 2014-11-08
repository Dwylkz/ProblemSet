#include <queue>
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

struct R {
  int u, v, l;
  R(int u_, int v_, int l_): u(u_), v(v_), l(l_) {}
};

typedef long long LL;
typedef vector<int> VI;

VI g[N];
int t, n, k;

int main()
{
  ios_base::sync_with_stdio(0);
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
      g[i].clear();
    for (int i = 0; i < n-1; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--;
      v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    k *= 2;
    queue<R> q;
    for (int u = 0; u < n; u++)
      for (int i = 0; i < g[u].size(); i++) {
        q.push(R(u, g[u][i], 1));
        k--;
      }

    LL res = 0;
    while (!q.empty()) {
      int u = q.front().u, v = q.front().v, l = q.front().l;
      q.pop();
      res += l;

      for (int i = 0; i < g[v].size() && k > 0; i++)
        if (u != g[v][i]) {
          q.push(R(v, g[v][i], l+1));
          k--;
        }
    }
    cout << res/2 << endl;
  }
  return 0;
}
