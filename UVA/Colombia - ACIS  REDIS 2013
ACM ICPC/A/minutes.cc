#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int N = 2e2+10;
const int inf = 0x3f3f3f3f;

struct pt_t {
  double x, y;
  pt_t(double _x = 0, double _y = 0) {
    x = _x, y = _y;
  }
  double operator [] (int b) {
    return b? b < 2? abs(x)+abs(y): x*x+y*y: sqrt(x*x+y*y);
  }
  friend pt_t operator + (const pt_t &lhs, const pt_t &rhs) {
    return pt_t(lhs.x+rhs.x, lhs.y+rhs.y);
  }
  friend pt_t operator - (const pt_t &lhs, const pt_t &rhs) {
    return pt_t(lhs.x-rhs.x, lhs.y-rhs.y);
  }
  friend double operator * (const pt_t &lhs, const pt_t &rhs) {
    return lhs.x*rhs.x+lhs.y*rhs.y;
  }
  friend double operator % (const pt_t &lhs, const pt_t &rhs) {
    return lhs.x*rhs.y-lhs.y*rhs.x;
  }
  pt_t &input() {
    scanf("%lf%lf", &x, &y);
    return *this;
  }
};

struct edge_t {
  int v, to, w, c;
};
vector<edge_t> E;
int L[N];
void init() {
  E.clear();
  memset(L, -1, sizeof(L));
}
void add(int u, int v, int w, int c) {
  edge_t t = {v, L[u], w, c};
  L[u] = E.size();
  E.push_back(t);
}
void badd(int u, int v, int w, int c) {
  add(u, v, w, c), add(v, u, 0, -c);
}

struct ek_t {
  vector<edge_t> E;
  int n, *L, src, snk, dis[N], ra[N], inq[N];
  int spfa(int u) {
    vector<int> q(1, u);
    memset(dis, 0x3f, sizeof(int)*n);
    memset(ra, -1, sizeof(int)*n);
    memset(inq, 0, sizeof(int)*n);
    dis[u] = 0;
    inq[u] = 1;
    for (int h = 0; h < q.size(); h++) {
      u = q[h], inq[u] = 0;
      for (int e = L[u]; ~e; e = E[e].to) {
        int v = E[e].v, w = E[e].w, c = E[e].c;
        if (w && dis[v] > dis[u]+c) {
          dis[v] = dis[u]+c;
          ra[v] = e^1;
          if (inq[v]) continue;
          inq[v] = 1;
          q.push_back(v);
        }
      }
    }
    return ra[snk] != -1;
  }
  int operator () (vector<edge_t> _E, int *_L, int _n, int _src, int _snk) {
    E = _E, L = _L, n = _n;
    src = _src, snk = _snk;
    int mmf = 0;
    for ( ; spfa(src); ) {
      int mf = inf;
      for (int e = ra[snk]; ~e; e = ra[E[e].v])
        mf = min(mf, E[e^1].w);
      for (int e = ra[snk]; ~e; e = ra[E[e].v])
        E[e].w += mf, E[e^1].w -= mf;
      mmf += dis[snk]*mf;
    }
    return mmf;
  }
} ek;

int n, m;
pt_t rs[N], ds[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    for (int i = 0; i < n; i++) rs[i].input();
    for (int i = 0; i < m; i++) ds[i].input();
    init();
    int src = n+m, snk = src+1, V = snk+1;
    for (int i = 0; i < m; i++) {
      badd(src, i, 1, 0);
      for (int j = 0; j < n; j++)
        badd(i, j+m, 1, (ds[i]-rs[j])[1]);
    }
    for (int i = 0; i < n; i++) badd(i+m, snk, 1, 0);
    printf("%d\n", ek(E, L, V, src, snk));
  }
  return 0;
}
