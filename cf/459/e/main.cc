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
int f[N];
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
    for (int w = 0; w < M; w++) {
      VI t, c;
      for (auto i: d[w]) {
        int u = e[i].u, v = e[i].v;
        if (f[v] >= f[u]+1)
          continue;

        t.push_back(v);
        c.push_back(f[u]+1);
      }

      for (int i = 0; i < t.size(); i++) {
        f[t[i]] = max(f[t[i]], c[i]);
        ret = max(ret, f[t[i]]);
      }
    }

    cout << ret << endl;
  }
  return 0;
}
