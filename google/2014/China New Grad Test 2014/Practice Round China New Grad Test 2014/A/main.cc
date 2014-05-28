#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int N = 1e2+10;
const int C = 1e5+10;
typedef map<string, int> msi_t;

struct edge_t {
  int v, to;
};
vector<edge_t> E;
int L[N];
void init() {
  E.clear();
  memset(L, -1, sizeof(L));
}
void add(int u, int v) {
  edge_t t = {v, L[u]};
  L[u] = E.size();
  E.push_back(t);
}

int n;
msi_t m;
char a[C], b[C];

int col[N];
bool dfs(int u, int c = 0) {
  col[u] = c;
  for (int e = L[u]; ~e; e = E[e].to) {
    int v = E[e].v;
    if (col[u] == col[v]) return 0;
    if (!~col[v] && !dfs(v, !c)) return 0;
  }
  return 1;
}

int main() {
#if 0
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int ks = 1; T--; ks++) {
    printf("Case #%d: ", ks);
    scanf("%d", &n);
    init();
    m.clear();
    int r = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s%s", a, b);
      int u, v;
      if (m.find(a) == m.end()) m[a] = r++;
      u = m.find(a)->second;
      if (m.find(b) == m.end()) m[b] = r++;
      v = m.find(b)->second;
      add(u, v) ,add(v, u);
    }
    memset(col, -1, sizeof(col));
    int yes = 1;
    for (int i = 0; i < N; i++)
      if (!~col[i] && !dfs(i)) {
        yes = 0;
        break;
      }
    puts(yes? "Yes": "No");
  }
  return 0;
}
