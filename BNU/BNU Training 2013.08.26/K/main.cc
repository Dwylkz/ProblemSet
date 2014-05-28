#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;

struct edge_t {
  int v, to, w;
} E[N<<2];
int L[N];
void init() {
  E[0].to = 0;
  memset(L, -1, sizeof(L));
}
void add(int u, int v, int w) {
  edge_t t = {v, L[u], w};
  E[L[u] = ++E[0].to] = t;
}

struct spfa_t {
  int d[N], b[N], c[N], s[N];
  int operator () (edge_t *E, int *L, int n, int u) {
    memset(d, 0x7f, sizeof(d));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    d[s[s[0] = 1] = u] = 0;
    b[u] = c[u] = 1;
    for ( ; s[0]; ) {
      b[u = s[s[0]--]] = 0;
      for (int e = L[u]; ~e; e = E[e].to) {
        int v = E[e].v, w = E[e].w;
        if (d[v]-w > d[u]) {
          d[v] = d[u]+w;
          if (!b[v]) {
            if ((c[v] += b[v] = 1) > n) return 0;
            s[++s[0]] = v;
          }
        }
      }
    }
    return 1;
  }
} spfa;

int n;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n), n; ) {
    init();
    int rt = 1;
    for (int i = 2; i <= n; i++) {
      int v, c;
      scanf("%d%d", &v, &c);
      add(i, v, 1);
      add(v, i, 1);
      if (c) rt = i;
    }
    spfa(E, L, n, rt);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += spfa.d[i];
    printf("%d\n", ans);
  }
  return 0;
}
