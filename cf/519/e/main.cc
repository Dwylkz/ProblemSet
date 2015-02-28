#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int N = 1e5+5;
const int B = 21;

vector<int> g[N];
int n, m, depth[N], size[N], link[N][B];

void DFS(int u, int p, int d)
{
  depth[u] = d;
  size[u] = 1;
  memset(link[u], -1, sizeof(link[u]));
  if (p != -1) {
    link[u][0] = p;
    for (int i = 1; i < B; i++)
      if (link[u][i-1] != -1)
        link[u][i] = link[link[u][i-1]][i-1];
  }
  for (auto v: g[u])
    if (v != p) {
      DFS(v, u, d+1);
      size[u] += size[v];
    }
}

int Jump(int u, int d)
{
  for (int i = B-1; i >= 0; i--)
    if (d>>i&1)
      u = link[u][i];
  return u;
}

int LCA(int u, int v)
{
  if (depth[u] < depth[v])
    swap(u, v);
  u = Jump(u, depth[u]-depth[v]);
  if (u == v)
    return u;
  // printf("-- (%d:%d, %d:%d) first jump to %d\n", u, depth[u], v, depth[v], u);
  for (int i = B-1; i >= 0; i--)
    if (depth[u] < (1<<i)) {
    } else if (link[u][i] == link[v][i]) {
    } else {
      u = link[u][i];
      v = link[v][i];
    }
  return link[u][0];
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n-1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  DFS(0, -1, 0);
  scanf("%d", &m);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    int lca = LCA(u, v);
    // printf("-- lca=%d\n", lca);
    int dis = depth[u]+depth[v]-depth[lca]*2;
    if (dis%2 == 0) {
      if (depth[u] == depth[v]) {
        if (u == v) {
          printf("%d\n", size[0]);
        } else {
          u = Jump(u, depth[u]-depth[lca]-1);
          v = Jump(v, depth[v]-depth[lca]-1);
          printf("%d\n", size[0]-size[lca]+(size[lca]-size[u]-size[v]));
        }
      } else {
        if (depth[u] < depth[v])
          swap(u, v);
        u = Jump(u, dis/2-1);
        printf("%d\n", size[link[u][0]]-size[u]);
      }
    } else {
      puts("0");
    }
  }
  return 0;
}
