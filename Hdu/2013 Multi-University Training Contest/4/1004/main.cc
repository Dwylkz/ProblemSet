#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long LL;
typedef int int_a[maxn];

struct edge {
  int v, to;
};
struct node {
  int i, o;
} V[maxn];
vector<edge> E;
int_a L;
void graph_init()
{
  E.clear();
  memset(L, -1, sizeof(L));
}
void graph_add(int u, int v)
{
  edge t = {v, L[u]};
  L[u] = E.size();
  E.push_back(t);
}

int n, m;

int times, scp;
int_a id, od, it, ot, sz, in_st, bl;
vector<int> st;
void tarjan_run(int u = 0)
{
  st.push_back(u);
  in_st[u] = 1;
  it[u] = ot[u] = times++;
  for (int i = L[u]; i != -1; i = E[i].to) {
    int v = E[i].v;
    if (it[v] == -1) {
      tarjan_run(v);
      ot[u] = min(ot[u], ot[v]);
    } else if (in_st[v]) ot[u] = min(ot[u], it[v]);
  }
  if (it[u] == ot[u]) {
    for ( ; ; ) {
      int v = st.back();
      bl[v] = scp;
      sz[scp]++;
      st.pop_back();
      in_st[v] = 0;
      if (u == v) break;
    }
    scp++;
  }
}
void tarjan()
{
  st.clear();
  memset(in_st, 0, sizeof(in_st));
  times = scp = 0;
  memset(id, 0, sizeof(id));
  memset(od, 0, sizeof(od));
  memset(it, -1, sizeof(it));
  memset(ot, -1, sizeof(ot));
  memset(sz, 0, sizeof(sz));
  memset(bl, -1, sizeof(bl));
  for (int u = 0; u < n; u++)
    if (it[u] == -1) tarjan_run(u);
}

int main()
{
#if 1
	freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
	for (int Case = 1; Case <= T; Case++) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
      V[i] = (node){0, 0};
    graph_init();
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      V[u].o++, V[v].i++;
      graph_add(u, v);
    }
    tarjan();
    int ans = 0;
    for (int u = 0; u < n; u++)
      for (int i = L[u]; i != -1; i = E[i].to)
        if (bl[u] != bl[E[i].v]) {
          od[bl[u]]++;
          id[bl[E[i].v]]++;
        }
#if 0
    for (int i = 0; i < n; i++) {
      printf("%d(%d, %d) belong to %d\n",
          i, V[i].i, V[i].o, bl[i]);
    }
    for (int i = 0; i < scp; i++) 
      printf("scp %d: size = %d, id = %d, od = %d\n",
          i, sz[i], id[i], od[i]);
#endif
    for (int i = 0; i < scp; i++)
      if (!id[i] || !od[i]) {
        int x = sz[i], y = n - x;
        ans = max(ans, x*(x-1) + y*(y-1) + x*y - m);
      }
    if (scp < 2) ans = -1; 
    printf("Case %d: %d\n", Case, ans);
	}
	return 0;
}
