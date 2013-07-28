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

LL ans, dp[maxn][4][2];
void dp_init()
{
  ans = -1;
  memeset(dp, 0, sizeof(dp));
}
void dp_run(int u = 0, int p = -1)
{
  for (int i = L[u]; i != -1; i++) {
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
    dp_run();
    printf("%lld\n", ans);
  }
  return 0;
}
