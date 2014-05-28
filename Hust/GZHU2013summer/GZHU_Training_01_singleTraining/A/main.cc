#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int maxn = 1e3 + 10;
typedef long long LL;
typedef int int_a[maxn];

struct edge {
  int v, to;
};
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

int n;
map<string, int> si;
vector<string> name, rank[maxn];
char str[maxn];

void travel(int u = 1, int level = 0)
{
#if 0
  printf("in %s\n", name[u].data());
#endif
  rank[level].push_back(name[u]);
  for (int i = L[u]; i != -1; i = E[i].to)
     travel(E[i].v, level+1);
}

int main()
{
#if 1
	freopen("input.in", "r", stdin);
#endif
	for ( ; ~scanf("%d", &n); ) {
    graph_init();
    name.clear();
    si.clear();
    name.push_back("*%*%*%*%*");
    si["Alice"] = name.size();
    name.push_back("Alice");
    for (int i = 0; i < n; i++) {
      int u, v;
      scanf("%s", str);
      if (!si[str]) {
        si[str] = name.size();
        name.push_back(str);
      }
      u = si[str];
      scanf("%s", str);
      if (!si[str]) {
        si[str] = name.size();
        name.push_back(str);
      }
      v = si[str];
#if 0
      printf("add %d %d\n", v, u);
#endif
      graph_add(v, u);
    }
    for (int i = 0; i < si.size(); i++)
      rank[i].clear();
    travel();
    for (int i = 1; i < si.size(); i++) {
      sort(rank[i].begin(), rank[i].end());
      for (int j = 0; j < rank[i].size(); j++)
        printf("%s %d\n", rank[i][j].data(), i);
    }
	}
	return 0;
}
