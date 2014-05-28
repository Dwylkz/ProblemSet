#include <cstdio>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 4e5+10;
const int inf = 0x7f7f7f7f;

struct edge_t {
  int v, to, w;
};
vector<edge_t> E;
int L[N];
void init() {
  E.clear();
  memset(L, -1, sizeof(L));
}
void add(int u, int v, int w) {
  edge_t t = {v, L[u], w};
  L[u] = E.size();
  E.push_back(t);
}

struct spfa_t {
  int d[N], b[N];
  struct node {
    int u, w;
    node (int _u = 0, int _w = 0): u(_u), w(_w) {}
    friend bool operator < (const node &lhs, const node &rhs) {
      return lhs.w > rhs.w;
    }
  };
  void operator () (vector<edge_t> &E, int *L, int u) {
    memset(d, 0x7f, sizeof(d));
    memset(b, 0, sizeof(b));
    priority_queue<node> q;
    for (q.push(node(u, d[u] = 0)); q.size(); ) {
      u = q.top().u, q.pop();
      if (b[u]++) continue;
      for (int e = L[u]; ~e; e = E[e].to) {
        int v = E[e].v, w = E[e].w;
        if (b[u] && d[v]-w > d[u])
          q.push(node(v, d[v] = d[u]+w));
      }
    }
  }
} spfa;

int n, m, c, l[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int ks = 1; T--; ks++) {
    printf("Case #%d: ", ks);
    scanf("%d%d%d", &n, &m, &c);
    init();
    for (int l, i = 0; i < n; i++) {
      scanf("%d", &l);
      add(n+(l<<1), i, 0), add(i, n+(l<<1|1), c);
      add(i, n+(l+1<<1), c), add(n+(l+1<<1|1), i, 0);
    }
    for (int u, v, w, i = 0; i < m; i++) {
      scanf("%d%d%d", &u, &v, &w);
      u--, v--;
      add(u, v, w), add(v, u, w);
    }
    spfa(E, L, 0);
    if (spfa.d[n-1] != inf) printf("%d\n", spfa.d[n-1]);
    else puts("-1");
  }
  return 0;
}
