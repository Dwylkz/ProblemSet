#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3+10;
const int M = 26;

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

struct bgm_t {
  int vis[N], pre[N], lma[N], rma[N];
  bool bfs(vector<edge_t> &E, int *L, int u) {
    vector<int> q(1, u);
    memset(vis, 0, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    for (int h = 0; h < q.size(); h++) {
      u = q[h];
      for (int e = L[u]; ~e; e = E[e].to) {
        int v = E[e].v;
        if (!vis[v]) {
          vis[v] = 1;
          if (rma[v] == -1) {
            for ( ; ~u; ) {
              rma[v] = u;
              swap(v, lma[u]);
              u = pre[u];
            }
            return 1;
          } else {
            pre[rma[v]] = u;
            q.push_back(rma[v]);
          }
        }
      }
    }
    return 0;
  }
  int operator () (vector<edge_t> &E, int *L, int V) {
    int mmat = 0;
    memset(lma, -1, sizeof(lma));
    memset(rma, -1, sizeof(rma));
    for (int u = 0; u < V; u++)
      mmat += bfs(E, L, u);
    return mmat;
  }
} bgm;

int n, m, jack[N][M], jill[N][M];
char s[N];

void split(int *t, char *s) {
  for (char *i = s; *i; i++) t[*i-'a']++;
}
void show(int *t) {
  for (int i = 0; i < M; i++)
    printf("%c: %d\n", i+'a', t[i]);
  puts("");
}
bool match(int *lhs, int *rhs) {
  for (int i = 0; i < M; i++)
    if (rhs[i] && lhs[i] < rhs[i]) return 0;
  return 1;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    memset(jack, 0, sizeof(jack));
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      split(jack[i], s);
    }
    memset(jill, 0, sizeof(jill));
    for (int i = 0; i < m; i++) {
      scanf("%s", s);
      split(jill[i], s);
    }
    init();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (match(jack[i], jill[j]))
          add(i, j+n);
    printf("%d\n", bgm(E, L, n));
  }
  return 0;
}
