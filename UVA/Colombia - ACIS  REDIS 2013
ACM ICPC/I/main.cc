#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <bitset>
using namespace std;
const int N = 1e3+10;
typedef bitset<N> bs_t;

struct edge_t {
  int v, to;
};
vector<edge_t> E;
int L[N];
void init() {
  E.clear();
  memset(L, -1, sizeof(L));
}
void add(int u, int v) {
  edge_t t = {v, L[u]};
  L[u] = E.size();
  E.push_back(t);
}

int n, m, ban[N];
bs_t bs[N]; 
int p[N];

bool cmp(int lhs, int rhs) {
  return bs[lhs].count() > bs[rhs].count();
}

int rt = 0;
void dfs(int u) {
  ban[u] = 1;
  bs[rt][u] = 1;
  for (int e = L[u]; ~e; e = E[e].to) {
    int v = E[e].v;
    if (!ban[v]) dfs(v);
  }
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    n++;
    init();
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      add(u, v);
    }
    for (int i = 0; i < n; i++) {
      memset(ban, 0, sizeof(ban));
      bs[i].reset();
      rt = i;
      dfs(i);
    }
#if 0
    for (int i = 0; i < n; i++) {
      printf("%d:\n", i);
      for (int j = 0; j < n; j++)
        if (bs[i][j])
          printf("  to %d\n", j);
      puts("");
    }
#endif
    int id = 0;
    for (int i = 1; i < n; i++)
      if (!bs[0][i]) p[id++] = i;
    sort(p, p+id, cmp);
#if 0
    for (int i = 0; i < id; i++)
      printf("not %d\n", p[i]);
#endif
    int rv = 0;
    for (int i = 0; i < id; i++)
      if (!bs[0][p[i]]) {
        for (int j = 0; j < n; j++)
          if (bs[p[i]][j]) bs[0][bs[p[i]][j]] = 1;
        rv++;
      }
    printf("%d\n", rv);
  }
  return 0;
}
