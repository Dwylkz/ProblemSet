#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;
const int M = N<<1;

struct edge_t {
  int v, to, i;
} E[M];
int El, L[N];
void init(int n) {
  El = 0;
  memset(L, -1, sizeof(int)*n);
}
void add_edge(int u, int v, int i) {
  edge_t t = {v, L[u], i};
  L[u] = El;
  E[El++] = t;
}

int n, w[N];

struct dp_t {
  int d, i;
  dp_t(int _d = -1, int _i = -1): d(_d), i(_i) {}
  friend bool operator < (const dp_t &lhs, const dp_t &rhs) {
    return lhs.d < rhs.d;
  }
} g[N][3], s[N][2];
int h[N], p[N], f[N], re[N];
void dp_init(int n) {
  memset(h, 0, sizeof(int)*n);
  memset(p, 0, sizeof(int)*n);
  memset(f, 0, sizeof(int)*n);
  memset(g, -1, sizeof(g[0])*n);
  memset(s, -1, sizeof(s[0])*n);
}
void dp_update(int u) {
  if (g[u][1] < g[u][2]) {
    swap(g[u][1], g[u][2]);
    if (g[u][0] < g[u][1]) {
      swap(g[u][0], g[u][1]);
    }
  }
  if (s[u][0] < s[u][1]) swap(s[u][0], s[u][1]);
}
void dp_down() {
  static int sv[N], si[N];
  int top = 1;
  sv[top] = 0;
  si[top] = L[0];
  for ( ; top; ) {
    int u = sv[top], &i = si[top];
    for ( ; ~i; i = E[i].to) {
      if (re[u] != i) {
        break;
      }
    }
    if (~i) {
      top++;
      int v = E[i].v;
      re[v] = i^1;
      sv[top] = v;
      si[top] = L[v];
      i = E[i].to;
    } else {
      for (int j = L[u]; ~j; j = E[j].to) {
        if (re[u] == j) continue;
        int v = E[j].v;
        if (g[v][0].i == -1) {
          if (g[u][2].d < 1) {
            g[u][2] = dp_t(1, v);
            dp_update(u);
          }
        } else {
          if (g[u][2] < g[v][0].d+1) {
            g[u][2] = dp_t(g[v][0].d+1, v);
            dp_update(u);
          }
        }
        if (s[u][1].d < f[v]) {
          s[u][1] = dp_t(f[v], v);
          dp_update(u);
        }
      }
      f[u] = max(f[u], s[u][0].d);
      if (g[u][0].i != -1) {
        f[u] = max(f[u], g[u][0].d);
        if (g[u][1].i != -1) {
          f[u] = max(f[u], g[u][0].d+g[u][1].d);
        }
      }
      top--;
    }
  }
}
void dp_up() {
  static int sv[N], si[N];
  int top = 1;
  sv[top] = 0;
  si[top] = L[0];
  for ( ; top; ) {
    int u = sv[top], &i = si[top];
    if (i == L[u]) {
      for (int ei = L[u]; ~ei; ei = E[ei].to) {
        if (re[u] == ei) continue;
        int v = E[ei].v, d[3] = {0}, j = 0;
        for (int k = 0; k < 3; k++) {
          if (g[u][k].i == -1) {
            break;
          } 
          if (g[u][k].i != v) {
            d[j++] = k;
          }
        }
        p[v] = p[u]+1;
        h[v] = max(h[u], p[u]);
        if (s[u][0].i == v) h[v] = max(h[v], s[u][1].d);
        else h[v] = max(h[v], s[u][0].d);
        if (j) {
          p[v] = max(p[v], g[u][d[0]].d+1);
          h[v] = max(h[v], p[u]+g[u][d[0]].d);
          if (j > 1) {
            h[v] = max(h[v], g[u][d[0]].d+g[u][d[1]].d);
          }
        }
      }
    }
    for ( ; ~i; i = E[i].to) {
      if (re[u] != i) {
        break;
      }
    }
    if (~i) {
      top++;
      int v = E[i].v;
      sv[top] = v;
      si[top] = L[v];
      i = E[i].to;
    } else {
      top--;
    }
  }
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int Case = 1; Case <= T; Case++) {
    scanf("%d", &n);
    init(n);
    for (int i = 0; i < n-1; i++) {
      int u, v, wi;
      scanf("%d%d%d", &u, &v, w+i);
      add_edge(--u, --v, i);
      add_edge(v, u, i);
    }
    dp_init(n);
    memset(re, -1, sizeof(bool)*n);
    dp_down();
    dp_up();
    int mn = 0x7fffffff, id = 0x7fffffff;
    for (int u = 1; u < n; u++) {
      int i = E[re[u]].i, t = max(h[u], f[u])*w[i];
      if (t < mn || (t == mn && i < id)) {
        mn = t;
        id = i;
      }
    }
    printf("Case #%d: %d\n", Case, id+1);
  }
  return 0;
}
