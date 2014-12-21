#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int N = 1e5+5;

typedef vector<int> VI;

VI g[N], rc[N];
int n, m, c[N];

int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", c+i);
    rc[c[i]].push_back(i);
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int maxc = -1, maxv = -1;
  for (int i = 0; i < N; i++) {
    if (rc[i].size() == 0)
      continue;
    set<int> cs;
    for (auto u: rc[i])
      for (auto v: g[u])
        if (c[u] != c[v])
          cs.insert(c[v]);
    if (maxc == -1 || maxv < cs.size()) {
      maxc = i;
      maxv = cs.size();
    }
  }
  printf("%d\n", maxc);
  return 0;
}
