#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 5e4+10;

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

struct tje_t {
  int dfs[N], low[N], ra[N];
  vector<int> ce;
  struct q_t {
    int u, e;
    q_t(int _u = 0, int _e = -1): u(_u), e(_e) {}
  } q[N];
  void operator () (vector<edge_t> &E, int *L, int n) {
    int time = 0;
    memset(dfs, -1, sizeof(dfs));
    memset(low, -1, sizeof(low));
    for (int i = 0; i < n; i++) {
      if (~dfs[i]) continue;
      int o = 0;
      for (ra[i] = -1, q[++o] = q_t(i, L[i]); o; ) {
        int u = q[o].u, &e = q[o].e;
        printf("u = %d\n", u);
        if (e == L[u]) dfs[u] = low[u] = time++;
        for ( ; ~e; e = E[e].to)
          if (e != ra[u]) {
            int v = E[e].v;
            if (!~dfs[v]) break;
            low[u] = min(low[u], dfs[v]);
          }
        if (~e) {
          int v = E[e].v;
          ra[v] = e^1;
          q[++o] = q_t(v, L[v]);
          e = E[e].to;
        } else {
          for (e = L[u]; ~e; e = E[e].to) {
            int v = E[e].to;
            if (ra[v] == (e^1)) low[u] = min(low[u], low[v]);
          }
          o--;
        }
      }
    }
    for (int v = 0; v < n; v++) {
      if (!~ra[v]) continue;
      int u = E[ra[v]].v;
      if (dfs[u] < low[v]) ce.push_back(ra[v]);
    }
    printf("sz = %d\n", (int)ce.size());
  }
} tje;

int n, r;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &r); ) {
    init();
    for (int i = 0; i < r; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      v--, u--;
      add(u, v), add(v, u);
    }
    tje(E, L, n);
  }
  return 0;
}
