#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5+10;
typedef long long LL;
const LL inf = 1e13+10;

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

int n, a[N];

LL gcd(LL a, LL b) {
  return b? gcd(b, a%b): a;
}
LL lcm(LL a, LL b) {
  return a/gcd(a, b)*b;
}

struct dfs_c {
  int *a, e, v, ra[N], bc;
  LL rv, w[N], c[N], lb, mb, rb, mn;
  bool look(int u, int k) {
    for (e = L[u]; ~e; e = E[e].to) if (e != ra[u]) {
      v = E[e].v;
      if ((w[v]-k)%c[v]) return 0;
    }
    return 1;
  }
  void dfs(int u) {
    // deal reverse arc and branch counting
    bc = 0;
    for (e = L[u]; ~e; e = E[e].to) if (e != ra[u]) {
      ra[E[e].v] = e^1;
      bc++;
    }
    // go deeper
    for (e = L[u]; ~e; e = E[e].to) if (e != ra[u]) {
      dfs(E[e].v);
    }
    // look for init right bound 
    // deal with lcm
    mn = inf;
    c[u] = 1;
    for (e = L[u]; ~e; e = E[e].to) if (e != ra[u]) {
      v = E[e].v;
      mn = min(mn, w[v]);
      c[u] = lcm(c[u], c[v]);
    }
    // find lower bound of max minimum value
    w[u] = a[u];
    if (bc) {
      for (lb = 0, rb = mn, mn = 0; lb <= rb; ) {
        mb = lb+rb>>1;
        if (look(u, mb)) {
          mn = mb;
          lb = mb+1;
        } else rb = mb-1;
      }
      c[u] *= bc;
      // deal with weight
      for (e = L[u]; ~e; e = E[e].to) if (e != ra[u]) {
        v = E[e].v;
        rv += w[v]-mn;
        w[u] += mn;
      }
    }
#if 1
    printf("in %d, ra = %d, mn = %lld, w = %lld, c = %lld\n",
        u, ra[u], mn, w[u], c[u]);
#endif
  }
  LL operator () (int u, int *_a) {
    a = _a;
    rv = 0;
    ra[u] = -1;
    dfs(u);
    return rv;
  }
} dfs;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    init();
    for (int i = 0; i < n-1; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      add(u, v);
      add(v, u);
    }
    cout << dfs(0, a) << endl;
  }
  return 0;
}
