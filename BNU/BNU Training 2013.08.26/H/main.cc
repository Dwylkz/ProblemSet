#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3+10;

int n, in[N];
vector<int> w[N];

int v[N];
int dfs(int u) {
  int sz = 1;
  v[u] = 1;
  for (int i = 0; i < w[u].size(); i++)
    if (!v[w[u][i]]) sz += dfs(w[u][i]);
  return sz;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n), n; ) {
    memset(in, 0, sizeof(in));
    for (int i = 0; i < n; i++) w[i].clear();
    for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++) {
        int wi;
        scanf("%1d", &wi);
        if (wi) w[i].push_back(j);
        else w[j].push_back(i);
      }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      memset(v, 0, sizeof(v));
      ans += dfs(i) == n;
    }
    printf("%d\n", ans);
  }
  return 0;
}
