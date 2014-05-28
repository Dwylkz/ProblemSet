#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e4+10;
const int M = 1e5+10;

struct edge_t {
  int u, v;
};
struct jfs_t {
  int f[N];
  void init(int n) {
    for (int i = 0; i < n; i++) f[i] = i;
  }
  int find(int x) {
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
  }
  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    f[x] = y;
    return 1;
  }
};

int n, m;
edge_t e[M];
jfs_t zkl;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    for (int i = 0; i < m; i++) scanf("%d%d", &e[i].u, &e[i].v);
    zkl.init(n);
    vector<int> ans;
    int scc = n;
    for (int i = m-1; i >= 0; i--) {
      ans.push_back(scc);
      scc -= zkl.join(e[i].u, e[i].v);
    }
    for ( ; ans.size(); ans.pop_back()) printf("%d\n", ans.back());
  }
  return 0;
}
