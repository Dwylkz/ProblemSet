#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1e3 + 10;
const int inf32 = 1e7;
typedef long long LL;

struct edge {int v, to;};
struct ndoe {int v;} V[maxn];
vector<edge> E;
int L[maxn];
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

int n, k, v[maxn];

int f[maxn][21][2], (*maxf)(int, int), inf;
int max(int x, int y)
{
  return x > y? x: y;
}
int min(int x, int y)
{
  return x < y? x: y;
}
int dp_init(int u = 0, int p = -1)
{
  for (int i = 0; i <= k; i++) {
    f[u][i][0] = inf;
    f[u][i][1] = V[u].v;
  }
  f[u][0][1] = V[u].v;
  for (int i = L[u]; i != -1; i = E[i].to)
    if (i != p) {
      int v = E[i].v;
      dp_init(v, i^1);
      f[u][0][1] += f[v][0][1];
    }
}
int (*g)[2], (*h)[2];
void dp_run(int u = 0, int p = -1)
{
  g = f[u];
  for (int i = L[u]; i != -1; i = E[i].to)
    if (i != p) {
      int v = E[i].v;
      dp_run(v, i^1);
      h = f[v];
      for (int j = 1; j <= k; j++)
        for (int l = 0; j + l <= k; l++)
          g[j+l][1] = maxf(g[j+l][1], g[j][1]+h[j][1]);
    }
#if 1
  printf("node %d:\n", u);
  for (int i = 0; i <= k; i++)
    printf("\tcut %d times, connect: %d, unconnect %d\n",
        i, f[u][i][1], f[u][i][0]);
#endif
}

int main()
{
#if 1
	freopen("input.in", "r", stdin);
#endif
	for ( ; ~scanf("%d%d", &n, &k); ) {
    graph_init();
    for (int i = 0; i < n; i++) scanf("%d", &V[i].v);
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      x--, y--;
      graph_add(x, y);
      graph_add(y, x);
    }
    int mx = -inf32, mn = inf32;
#if 1
    puts("min");
#endif
    maxf = min, inf = inf32;
    dp_init(), dp_run();
    mn = min(mn, min(f[0][k][0], f[0][k][1]));
#if 1
    puts("max");
#endif
    maxf = max, inf = -inf32;
    dp_init(), dp_run();
    mx = max(mx, max(f[0][k][0], f[0][k][1]));
    printf("%d %d\n", mn, mx);
//     break;
	}
	return 0;
}
