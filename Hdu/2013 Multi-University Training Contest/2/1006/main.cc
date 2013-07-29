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
#define WHERE    puts(__func__);
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
  int val, trp;
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

LL ans, dp[maxn][4][2];
/* dp[node_number][trapped_times][end_without_trap or end_with_trap] */
void dp_init()
{
  ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 2; k++)
        dp[i][j][k] = -inf64;
}
void dp_run(int u = 0, int p = -1)
{
  LL (&f)[4][2] = dp[u],
     val = V[u].val,
     trp = V[u].trp;
  f[trp][trp] = val;
  ans = max(ans, f[trp][trp]);
  for (int i = L[u]; i != -1; i = E[i].to) {
    if (i == p) continue;
    dp_run(E[i].v, i ^ 1);
    LL (&g)[4][2] = dp[E[i].v];
    for (int j = 0; j <= c; j++)
      for (int k = 0; k+j <= c; k++) {
        if (k+j <= c) ans = max(ans, f[j][1]+g[k][1]);
        if (k+j < c) ans = max(ans, f[j][0]+g[k][0]);
        if (j != c) ans = max(ans, f[j][0]+g[k][1]);
        if (k != c) ans = max(ans, f[j][1]+g[k][0]);
      }
    for (int j = 0; j < c; j++) {
      f[j+trp][0] = max(f[j+trp][0], g[j][0]+val);
      f[j+trp][1] = max(f[j+trp][1], g[j][1]+val);
    }
    if (!trp) f[c][1] = max(f[c][1], g[c][1]+val);
  }
#if 0
  printf("node %4d{%4lld, %4lld}\n", u, val, trp);
  for (int i = 0; i <= c; i++) {
    printf("%4d end_without_trap = %4lld, end_with_trap = %4lld\n",
        i, f[i][0], f[i][1]);
  }
#endif
}

//main
int main() {
#if 0
  freopen(input, "r", stdin);
  //freopen(output, "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d%d", &n, &c);
    graph_init();
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &V[i].val, &V[i].trp);
    }
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      graph_add_edge(u, v);
      graph_add_edge(v, u);
    }
    dp_init();
    dp_run();
    printf("%lld\n", ans);
  }
  return 0;
}
