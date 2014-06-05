#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 5e4 + 10;
typedef long long LL;

int n, d[maxn];
vector<int> e[maxn];

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; i++) e[i].clear();
    for (int u, v, i = 0; i < n; i++) {
      scanf("%d%d", &u, &v);
      d[u]++, d[v]++;
      e[u].push_back(v);
      e[v].push_back(u);
    }
    int res = 0;
    for ( ; ; ) {
      int id = 0;
      for (int i = 0; i < n; i++)
        if (d[i] > d[id]) id = i;
      if (!d[id]) break;
      for (int i = 0; i < e[id].size(); i++)
        d[e[id][i]]--;
      d[id] = 0;
      res++;
    }
    printf("%d\n", res);
  }
  return 0;
}
