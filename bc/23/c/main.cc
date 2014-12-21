#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

const int N = 2e3+5;
const int M = 50+5;
const long long oo = (1ull<<63)-1;

struct Arc {
  int v, w;
  Arc() {}
  Arc(int v, int w): v(v), w(w) {}
};

typedef long long LL;
typedef vector<Arc> VA;

VA g[N];
int n, k;

LL f[N][M];
void DFS(int u, int p)
{
  f[u][0] = f[u][1] = 0;
  for (int i = 2; i <= k; i++)
    f[u][i] = oo;
  for (int i = 0; i < (int)g[u].size(); i++) {
    int v = g[u][i].v, w = g[u][i].w;
    if (v == p)
      continue;
    DFS(v, u);
    for (int a = k; a >= 0; a--)
      for (int b = 1; b <= a; b++)
        if (f[u][a-b] != oo && f[v][b] != oo)
          f[u][a] = min(f[u][a], f[u][a-b]+f[v][b]+2*b*(k-b)*w);
  }
}

int main()
{
  int kase;
  scanf("%d", &kase);
  while (kase--) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
      g[i].clear();
    for (int i = 0; i < n-1; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      u--;
      v--;
      g[u].push_back(Arc(v, w));
      g[v].push_back(Arc(u, w));
    }
    DFS(0, -1);
    cout << f[0][k] << endl;
  }
  return 0;
}
