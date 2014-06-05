#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
const int N = 1000+10;
const int inf = 0x7fffffff;

struct edge_t {
  int v, to, w;
};
vector<edge_t> E;
int L[N];
void init() {
  E.clear();
  memset(L, -1, sizeof(L));
}
void add(int u, int v, int w = 0) {
  edge_t t = {v, L[u], w};
  L[u] = E.size();
  E.push_back(t);
}

int n, g[N][N], col[N];
void fill(int u, int c) {
  if (col[u] != -1) return ;
  col[u] = c;
  for (int e = L[u]; ~e; e = E[e].to)
    fill(E[e].v, c^1);
}
int dis[N], inq[N], cnt[N];
bool spfa(int u) {
  vector<int> q(1, u);
  memset(inq, 0, sizeof(inq));
  memset(cnt, 0, sizeof(cnt));
  memset(dis, 0x7f, sizeof(dis));
  inq[u] = 1;
  dis[u] = 0;
  cnt[u]++;
  for ( ; q.size(); ) {
    u = q.back();
    q.pop_back();
    inq[u] = 0;
    for (int e = L[u]; ~e; e = E[e].to) {
      int v = E[e].v, w = E[e].w;
      if (dis[v] <= dis[u]+w) continue;
      dis[v] = dis[u]+w;
      if (!inq[v]) {
        inq[v] = 1;
        if (++cnt[v] > n) return 0;
        q.push_back(v);
      }
    }
  }
  return 1;
}
bool look() {
  memset(col, -1, sizeof(col));
  for (int u = 0; u < n; u++) fill(u, 0);
  for (int u = 0; u < n; u++)
    for (int v = 0; v < n; v++)
      if (g[u][v] && col[u] == col[v])
        return 0;
  init();
  for (int u = 0; u < n; u++)
    for (int v = 0; v < n; v++) {
      if (g[u][v]) {
        if (!col[u]) add(u, v, -N);
        else add(v, u, -N);
      } else {
        if (!col[u]) add(v, u, N-1);
        else add(u, v, N-1);
      }
    }
  for (int u = 0; u < n; u++)
    if (!col[u]) add(n, u, N-1);
    else  add(u, n, N-1);
  return spfa(n);
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d", &n);
    init();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        scanf("%1d", g[i]+j);
        if (g[i][j]) add(i, j);
      }
    puts(look()? "Yes": "No");
#if 0
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        printf("%d", g[i][j]);
      puts("");
    }
    printf("col: ");
    for (int i = 0; i < n; i++) printf("%d", col[i]);
    puts("");
#endif
  }
  return 0;
}
