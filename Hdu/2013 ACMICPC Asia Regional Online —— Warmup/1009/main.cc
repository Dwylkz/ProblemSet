#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
#define _pb push_back
const int inf = 0x3f3f3f3f;
const int N = 1e6+10;

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

int n;

int f[N];
int bfs(int rt) {
  vector<int> q(1, rt), r(n, -1);
  for (int h = 0; h < q.size(); h++)
    for (int e = L[q[h]]; ~e; e = E[e].to) 
      if (e != r[q[h]]) r[E[e].v] = e^1, q._pb(E[e].v);
  int rv = 0;
  for (int h = q.size()-1; h >= 0; h--) {
    int u = q[h], ec = f[u] = 0;
    for (int e = L[u]; ~e; e = E[e].to)
      if (e != r[u]) ec += f[E[e].v];
    if (ec > 1) {
      if (u == rt) rv += ec-2;
      else rv += ec-1;
      f[u] = 0;
    } else f[u] = 1;
  }
  return rv<<1|1;
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
    for (int u, v, i = 0; i < n-1; i++) {
      scanf("%d%d", &u, &v);
      add(--u, --v), add(v, u);
    }
    printf("%d\n", bfs(0));
  }
  return 0;
}
