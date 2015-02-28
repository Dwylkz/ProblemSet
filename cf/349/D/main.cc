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

LL gcd(LL a, LL b) {
  return b? gcd(b, a%b): a;
}
LL lcm(LL a, LL b) {
  return a/gcd(a, b)*b;
}

int n, a[N];

LL weight[N], delta[N];
void dfs(int u, int p = -1) {
  int branch = 0;
  delta[u] = 1;
  for (int e = L[u]; ~e; e = E[e].to) if (e != p) {
    int v = E[e].v;
    branch++;
    dfs(v, e^1);
    delta[u] = lcm(delta[u], delta[v]);
  }
  if (branch) {
    LL minval = inf;
    for (int e = L[u]; ~e; e = E[e].to) if (e != p) {
      int v = E[e].v;
      if (!delta[u]) minval = 0;
      else minval = min(minval, weight[v]-weight[v]%delta[u]);
    }
    weight[u] = minval*branch;
    delta[u] *= branch;
  } else weight[u] = a[u];
}

int main() {
#if 0
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    LL total = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
      total += a[i];
    }
    init();
    for (int i = 0; i < n-1; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      add(u, v);
      add(v, u);
    }
    dfs(0);
    cout << total-weight[0] << endl;
  }
  return 0;
}
