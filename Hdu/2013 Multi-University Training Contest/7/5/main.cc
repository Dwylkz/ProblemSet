#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 5e4+10;
const int K = 32;
typedef long long LL;

struct edge_t {
  int v, to;
};
vector<edge_t> E;
int L[N];
void init(int n) {
  E.clear();
  memset(L, -1, sizeof(int)*n);
}
void add_edge(int u, int v) {
  edge_t t = {v, L[u]};
  L[u] = E.size();
  E.push_back(t);
}

int n, k;
LL w[N], p[K];

LL ll_split(LL x) {
  LL rv = 0;
  for (int i = 0; i < k; i++) {
    LL o = 0;
    for ( ; x%p[i] == 0; x/= p[i]) o++;
    rv |= o%3<<(i<<1);
  }
  return rv;
}
LL ll_add(LL lhs, LL rhs) {
  LL rv = 0;
  for (int i = 0; i < k; i++) {
    LL o = ((lhs>>(i<<1)&3)+(rhs>>(i<<1)&3))%3;
    rv |= o<<(i<<1);
  }
  return rv;
}
LL ll_com(LL x) {
  LL rv = 0;
  for (int i = 0; i < k; i++) {
    rv |= (3-(x>>(i<<1)&3))%3<<(i<<1);
  }
  return rv;
}
void ll_show(LL x) {
  for (int i = 0; i < k; i++) {
    printf("%lld ", x>>(i<<1)&3);
  }
}

bool vis[N];
int size, s[N];
void get_size(int u) {
  vis[u] = 1;
  s[u] = 1;
  for (int i = L[u]; ~i; i = E[i].to) {
    int v = E[i].v;
    if (vis[v]) continue;
    get_size(v);
    s[u] += s[v];
  }
  vis[u] = 0;
}
int core;
void find_core(int u) {
  vis[u] = 1;
  int flag = 1;
  for (int i = L[u]; ~i; i = E[i].to) {
    int v = E[i].v;
    if (vis[v]) continue;
    if (s[v] > size/2) flag = 0;
    find_core(v);
  }
  if (flag && size-s[u] <= size/2) core = u;
  vis[u] = 0;
}
vector<LL> dis;
void get_dis(int u, LL d) {
  vis[u] = 1;
  dis.push_back(ll_add(w[u], d));
  for (int i = L[u]; ~i; i = E[i].to) {
    int v = E[i].v;
    if (vis[v]) continue;
    get_dis(v, ll_add(w[u], d));
  }
  vis[u] = 0;
}
int dac(int u) {
  get_size(u);
  size = s[u];
  if (size == 1) return !w[u];
  find_core(u);
  int rv = !w[u = core];
  vis[u] = 1;
  map<LL, int> m;
  m[0]++;
  for (int i = L[u]; ~i; i = E[i].to) {
    int v = E[i].v;
    if (vis[v]) continue;
    dis.clear();
    get_dis(v, 0);
    for (int j = 0; j < dis.size(); j++) {
      map<LL, int>::iterator it = m.find(ll_com(ll_add(dis[j], w[u])));
      if (it != m.end()) rv += it->second;
    }
    for (int j = 0; j < dis.size(); j++) m[dis[j]]++;
  }
  for (int i = L[u]; ~i; i = E[i].to) {
    int v = E[i].v;
    if (vis[v]) continue;
    rv += dac(v);
  }
  vis[u] = 0;
  return rv;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    init(n);
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
      char b[32];
      scanf("%s", b);
      p[i] = atoll(b);
    }
    for (int i = 0; i < n; i++) {
      char b[32];
      scanf("%s", b);
      w[i] = ll_split(atoll(b));
    }
    for (int i = 0; i < n-1; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      add_edge(u, v);
      add_edge(v, u);
    }
    printf("%d\n", dac(0));
  }
  return 0;
}
