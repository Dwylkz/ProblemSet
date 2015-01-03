#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
#include <set>

using namespace std;

const int N = 5e4+5;

typedef vector<int> VI;
typedef set<int> SI;

VI g[N], c[N];
int n, m;

int f[N];
SI* Walk(int u, int p)
{
  SI* su = new SI;
  for (int i = 0; i < (int)g[u].size(); i++) {
    int v = g[u][i];
    if (v == p)
      continue;
    SI* sv = Walk(v, u);
    if (sv->size() > su->size())
      swap(sv, su);
    for (SI::iterator j = sv->begin(); j != sv->end(); j++)
      su->insert(*j);
    delete sv;
  }
  for (int i = 0; i < (int)c[u].size(); i++)
    su->insert(c[u][i]);
  f[u] = su->size();
  return su;
}

int main()
{
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i < n; i++) {
      g[i].clear();
      c[i].clear();
    }
    for (int i = 0; i < n-1; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      a--;
      b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      c[a-1].push_back(b);
    }
    delete Walk(0, -1);
    for (int i = 0; i < n; i++)
      printf("%d%c", f[i], i < n-1? ' ': '\n');
  }
  return 0;
}
