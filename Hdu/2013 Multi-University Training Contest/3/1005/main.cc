#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 5e4 + 10;
const int maxm = 5e2 + 10;
const int mod = 10007;
typedef long long LL;

struct edge {
  int v, to;
};
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

int c[maxm][maxm];
void init()
{
  memset(c, 0, sizeof(c));
  for (int i = c[0][0] = 1; i < maxm; i++) {
    c[i][0] = 1;
    for (int j = 1; j < maxm; j++) 
      c[i][j] = c[i-1][j] + c[i-1][j-1];
  }
#if 0
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      printf("%7d%c", c[i][j], j < 9? ' ': '\n');
#endif
}

int n, k;

int f[maxn][maxm];
int calc(int *y, int l)
{
  int sum = 0;
  for (int j = 0; j <= l; j++)
    sum = (sum + c[l][j] * y[j] % mod) % mod;
#if 0
  printf("sum = %d\n", sum);
#endif
  return sum;
}
void dp_son(int u = 0, int p = -1)
{
  memset(f[u], 0, sizeof(f[u]));
  for (int i = L[u]; i != -1; i = E[i].to)
    if (i != p) {
      int v = E[i].v;
      dp_son(v, i^1);
      for (int j = 0; j <= k; j++)
        f[u][j] = (f[u][j] + calc(f[v], j) + 1) % mod;
    }
}
void dp_father(int u = 0, int p = -1)
{
  static int tmp[maxm];
  if (p != -1) {
    int v = E[p].v;
    memcpy(tmp, f[v], sizeof(f[v]));
    for (int i = 0; i <= k; i++)
      tmp[i] -= calc(f[u], i) + 1;
    for (int i = 0; i <= k; i++)
      f[u][i] = (f[u][i] + calc(tmp, i) + 1) % mod;
  }
  for (int i = L[u]; i != -1; i = E[i].to)
    if (i != p) dp_father(E[i].v, i^1);
}

int main()
{
#if 1
	freopen("input.in", "r", stdin);
#endif
  init();
  int T;
  scanf("%d", &T);
	for ( ; T--; ) {
    graph_init();
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n-1; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      graph_add(u, v);
      graph_add(v, u);
    }
    dp_son();
#if 0
    puts("dp_son");
    for (int i = 0; i < n; i++) {
      printf("node %d: ", i);
      for (int j = 0; j <= k; j++)
        printf("%d%c", f[i][j], j < k? ' ': '\n');
    }
#endif
    dp_father();
#if 0
    puts("dp_father");
    for (int i = 0; i < n; i++) {
      printf("node %d: ", i);
      for (int j = 0; j <= k; j++)
        printf("%d%c", f[i][j], j < k? ' ': '\n');
    }
#endif
    for (int i = 0; i < n; i++)
      printf("%d\n", f[i][k]);
	}
	return 0;
}
