#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int N = 3*1e5+10;
const int M = 1e5+10;

typedef vector<int> VI;

struct Edge {
  int u, v, w;
  void input()
  {
    cin >> u >> v >> w;
    u--;
    v--;
  }
};

int n, m;
Edge e[N];
int f[N], g[N];
VI d[M];

int main()
{
  cin.sync_with_stdio(0);
  for (;cin >> n >> m;) {
    for (int i = 0; i < M; i++)
      d[i].clear();

    for (int i = 0; i < m; i++) {
      e[i].input();
      d[e[i].w].push_back(i);
    }

    int ret = 0;
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    for (int i = 0; i < M; i++)
      for (auto j: d[i]) {
        int u = e[j].u, v = e[j].v, w = e[j].w;
        if (g[u] >= w)
          continue;

        if (f[v] >= f[u]+1)
          continue;

        f[v] = f[u]+1;
        g[v] = w;

        ret = max(ret, f[v]);
      }

    cout << ret << endl;
  }
  return 0;
}
