//coder: SXDwylkz
#if 0006100106
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
//namespaces
using namespace std;
//constants
const char input[] = "input.in",
      output[] = "output.out";
const int inf32 = 0x7fffffff,
      maxn = 5e4 + 10,
      oo = -1;
const long long inf64 = 0x7fffffffffffffffLL; 

//type definition
typedef unsigned char UC;
typedef unsigned long long ULL;
typedef long long LL;
typedef int int_a[maxn];
typedef bool bool_a[maxn];
typedef char char_a[maxn];
typedef pair<int, int> II;

//macro
#define WHERE	puts(__func__);
#define PA(H, I, S, E, F,...) {\
  puts(H);\
  for (int I = (S); I < (E); I++) {\
    printf(F,##__VA_ARGS__);\
  }\
  puts("");\
}

#endif

struct edge {
  int v, to;
};
struct node {
  LL val;
  int trp;
} V[maxn];
vector<edge> E;
int_a L; 
void graph_init()
{
  E.clear();
  memset(L, -1, sizeof(L));
}
void graph_add_edge(int u, int v)
{
  edge t = {v, L[u]};
  L[u] = E.size();
  E.push_back(t);
}

int n, c;

LL ans;
struct dp_t {
  LL val;
  int pre;
  LL tail;
} dp[maxn][4][2];
void dp_init()
{
  ans = -1;
  for (int i = 0; i < n * 8; i++) {
    *((dp_t*)dp + i) = (dp_t){-1, -1, 0};
  }
}
void dp_son(int u = 0, int p = -1)
{
  dp_t (&f)[4][2] = dp[u];
  LL val = V[u].val;
  int t = V[u].trp;
  f[t][0] = f[t][1] = (dp_t){val, u};
  for (int i = L[u]; i != -1; i = E[i].to) {
    if (i == p) continue;
    int v = E[i].v;
    dp_son(v, i ^ 1);
    dp_t (&g)[4][2] = dp[v];
    for (int j = 0; j <= c - t; j++) {
      if (g[j][0].val == -1) continue;
      if (c && j + t == c && !t && f[c][0].val < g[j][0].val - g[j][0].tail + val) {
        f[c][1] = f[1][0];
        f[c][0] = (dp_t){g[j][0].val - g[j][0].tail + val, v, 0};
      } else if (f[t + j][0].val < g[j][0].val + val) {
        f[t + j][1] = f[t + j][0];
        f[t + j][0] = (dp_t){g[j][0].val + val, v, g[j][0].tail};
      }
    }
  }
  if (t) {
    f[1][0].tail = f[1][0].val - val;
    f[1][1].tail = f[1][1].val - val;
  }
#if 0
  printf("%8s node %d(%4lld, %4d):\n", __func__, u, val, t);
  for (int i = 0 ; i <= c; i++) {
    printf("\tc = %d, max = (%5lld, %5d, %5lld), ex-max = (%5lld, %5d, %5lld)\n",
        i,
        f[i][0].val, f[i][0].pre, f[i][0].tail,
        f[i][1].val, f[i][1].pre, f[i][1].tail);
  }
#endif
}
void dp_father(int u = 0, int p = -1)
{
  dp_t (&f)[4][2] = dp[u];
  LL val = V[u].val;
  int t = V[u].trp;
  if (p != -1) {
    int v = E[p].v;
    dp_t (&g)[4][2] = dp[v];
    for (int j = 0; j <= c - t; j++) {
      int k = (g[j][0].pre == u);
      if (g[j][k].val == -1) continue;
      if (c && j + t == c && !t && f[c][0].val < g[j][k].val - g[j][k].tail + val) {
        f[c][1] = f[c][0];
        f[c][0] = (dp_t){g[j][k].val -  g[j][k].tail + val, v, 0};
      } else if (f[t + j][0].val < g[j][k].val + val) {
        f[t + j][1] = f[t + j][0];
        f[t + j][0] = (dp_t){g[j][k].val + val, v, g[j][k].tail};
      }
    }
  }
  if (t) {
    f[1][0].tail = f[1][0].val - val;
    f[1][1].tail = f[1][1].val - val;
  }
  for (int j = 0; j <= c; j++) {
    ans = max(ans, f[j][0].val);
  }
#if 0
    printf("%8s node %d(%4lld, %4d):\n", __func__, u, val, t);
    for (int i = 0 ; i <= c; i++) {
      printf("\tc = %d, max = (%5lld, %5d, %5lld)\n",
          i,
          dp[u][i][0].val, dp[u][i][0].pre, dp[u][i][0].tail);
    }
#endif
  for (int i = L[u]; i != -1; i = E[i].to) {
    if (i == p) continue;
    dp_father(E[i].v, i ^ 1);
  }
}

//main
int main() {
#if 1
  freopen(input, "r", stdin);
  //freopen(output, "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d%d", &n, &c);
    graph_init();
    for (int i = 0; i < n; i++) {
      scanf("%lld%d", &V[i].val, &V[i].trp);
    }
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      graph_add_edge(u, v);
      graph_add_edge(v, u);
    }
    dp_init();
    dp_son();
    dp_father();
    printf("%lld\n", ans);
  }
  return 0;
}
