#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
const int N = 2e5+10;
typedef vector<vector<int> > Graph;

struct Bia {
  int s[N];
  void init() {
    memset(s, 0, sizeof(s));
  }
  void add(int x, int y) {
    for (x++; x < N; x += -x&x) s[x] += y;
  }
  void rAdd(int x, int y, int z) {
    add(x, z);
    add(y+1, -z);
  }
  int ask(int x) {
    int ret = 0;
    for (x++; x; x -= -x&x) ret += s[x];
    return ret;
  }
};

int n, m, a[N];
Graph g;

Bia zkl[2];
int dep[N], ind[2], l[2][N], r[2][N];
void dfs(int u, int d = 0, int p = -1) {
  int oe = d&1;
  dep[u] = d;
  l[oe][u] = ind[oe]++;
  l[!oe][u] = ind[!oe];
  zkl[oe].rAdd(l[oe][u], l[oe][u], a[u]);
  for (int v: g[u])
    if (v != p) dfs(v, d+1, u);
  r[oe][u] = ind[oe];
  r[!oe][u] = ind[!oe];
}

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    g.resize(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
      g[i].clear();
    }
    for (int i = 0; i < n-1; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    for (int i = 0; i < 2; i++) {
      ind[i] = 0;
      zkl[i].init();
    }
    dfs(0);
    while (m--) {
      int op, x;
      scanf("%d%d", &op, &x);
      x--;
      int oe = dep[x]&1;
      if (op == 1) {
        int val;
        scanf("%d", &val);
        if (l[oe][x] < r[oe][x]) zkl[oe].rAdd(l[oe][x], r[oe][x]-1, val);
        if (l[!oe][x] < r[!oe][x]) zkl[!oe].rAdd(l[!oe][x], r[!oe][x]-1, -val);
      } else printf("%d\n", zkl[oe].ask(l[oe][x]));
    }
  }
  return 0;
}
